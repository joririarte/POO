#include "admindb.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QSqlError>
#include <QCryptographicHash>
#include <QDebug>

AdminDB::AdminDB(QObject* parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase( "QSQLITE" );
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

//bool AdminDB::validarUsuario(QString usuario, QString clave)
//{
//    if ( db.open() )  {
//        QSqlQuery query = db.exec( "SELECT nombre, apellido FROM usuarios WHERE usuario='"+usuario+"' AND clave='"+clave+"'" );

//        if(query.size() <= 0){
//            qDebug() << "No hay datos";
//            qDebug() << query.lastError().text();
//        }

//        while( query.next() )  {
//            qDebug() << query.value( 0 ).toString() << " " << query.value( 1 ).toString();
//            return true;
//        }
//    }

//    return false;
//}

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
        db.close();
        return false;
    }

    db.close();
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
