#include "admindb.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QSqlError>
#include <QCryptographicHash>
#include <QDebug>

AdminDB* AdminDB::instancia = nullptr;

AdminDB::AdminDB(QObject* parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase( "QSQLITE" );
}

AdminDB *AdminDB::getInstancia()
{
    if(!instancia) instancia = new AdminDB;
    return instancia;
}

bool AdminDB::conectar(QString archivoSqlite)
{
    db.setDatabaseName( archivoSqlite );

    if( db.open() )
        return true;

    return false;
}

QSqlDatabase AdminDB::getDB()
{
    return db;
}

QStringList AdminDB::validarUsuario(QString usuario, QString clave)
{

    QStringList datosPersonales;

    if ( ! db.isOpen() )
        return datosPersonales;

    QSqlQuery * query = new QSqlQuery( db );
    QString claveMd5 = QCryptographicHash::hash( clave.toUtf8(),
                                                 QCryptographicHash::Md5 ).toHex();

    query->exec( "SELECT nombre, apellido FROM usuarios WHERE usuario = '" + usuario +
                 "' AND clave = '" + claveMd5 + "'" );

    while( query->next() )  {
        QSqlRecord registro = query->record();

        datosPersonales << query->value( registro.indexOf( "nombre" ) ).toString();
        datosPersonales << query->value( registro.indexOf( "apellido" ) ).toString();
    }
    return datosPersonales;
}

bool AdminDB::insertarUsuario(QString usuario, QString clave, QString nombre, QString apellido, QString mail)
{
    if (!db.open()) {
        qDebug() << "Error al abrir la base de datos:" << db.lastError().text();
        return false;
    }
    QString claveMd5 = QCryptographicHash::hash( clave.toUtf8(),
                                                 QCryptographicHash::Md5 ).toHex();

    // Prepara la consulta INSERT
    QSqlQuery query;
    query.prepare("INSERT INTO usuarios VALUES (null, :usuario, :clave, :nombre, :apellido, :mail)");
    query.bindValue(":usuario", usuario);
    query.bindValue(":clave", claveMd5);
    query.bindValue(":nombre", nombre);
    query.bindValue(":apellido", apellido);
    query.bindValue(":mail", mail);

    if (!query.exec()) {
        qDebug() << "Error al ejecutar la consulta:" << query.lastError().text();
        return false;
    }
    return true;
}

QVector<QStringList> AdminDB::select(QString comando)
{
    QVector<QStringList> resultados;
    if (!db.open()) {
        // Manejo de errores si no se puede abrir la base de datos
        return resultados;
    }
    // Ejecuta la consulta SELECT
    QSqlQuery query(comando);
    if (!query.exec()) {
        resultados.append({"noresult"});
        return resultados;
    }

    // Procesa los resultados
    while (query.next()) {
        QStringList fila;
        QSqlRecord record = query.record();
        for (int i = 0; i < record.count(); ++i) {
            fila << query.value(i).toString();
        }
        resultados.append(fila);
    }

    return resultados;

}

bool AdminDB::actualizarDatos(QString campo, QString valor, QString id)
{
    if (!db.open()) {
        qDebug() << "Error al abrir la base de datos:" << db.lastError().text();
        return false;
    }

    // Prepara la consulta INSERT
    QSqlQuery query;
    query.prepare("UPDATE usuarios SET " + campo + "='" + valor + "' WHERE id=" + id);

    if (!query.exec()) {
        qDebug() << "Error al ejecutar la consulta:" << query.lastError().text();
        return false;
    }
    return true;

}
