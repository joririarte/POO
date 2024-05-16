#include "admindb.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlError>
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

bool AdminDB::validarUsuario(QString usuario, QString clave)
{
    if ( db.open() )  {
        QSqlQuery query = db.exec( "SELECT nombre, apellido FROM usuarios WHERE usuario='"+usuario+"' AND clave='"+clave+"'" );

        if(query.size() <= 0){
            qDebug() << "No hay datos";
            qDebug() << query.lastError().text();
        }

        while( query.next() )  {
            qDebug() << query.value( 0 ).toString() << " " << query.value( 1 ).toString();
            return true;
        }
    }

    return false;
}
