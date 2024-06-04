#include "admindb.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QSqlError>
#include <QCryptographicHash>
#include <QDebug>

AdminDB* AdminDB::instance = nullptr;

AdminDB::AdminDB(QObject* parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase( "QSQLITE" );
}

AdminDB *AdminDB::getInstance()
{
   instance = instance ? instance : new AdminDB;
   return instance;
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
    qDebug() << claveMd5;

    while( query->next() )  {
        QSqlRecord registro = query->record();

        datosPersonales << query->value( registro.indexOf( "nombre" ) ).toString();
        datosPersonales << query->value( registro.indexOf( "apellido" ) ).toString();
    }
    qDebug() << datosPersonales;
    return datosPersonales;
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
        // Manejo de errores si la consulta falla
        db.close();
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

    // Cierra la conexión a la base de datos
    db.close();

    return resultados;

}


