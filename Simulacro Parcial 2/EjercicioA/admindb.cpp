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

QVector<Linea> AdminDB::obtenerLineas()
{
    QVector<Linea > lineas;
    if(db.open()){
        QSqlQuery query = db.exec("SELECT x_inicial, y_inicial, x_final, y_final FROM lineas");
        if(query.next()){
            query.previous();
            while( query.next() )  {
                bool ok;
                lineas.push_back(Linea( query.value(0).toInt(&ok), //x_inicial
                                        query.value(1).toInt(&ok), //y_inicial
                                        query.value(2).toInt(&ok), //x_final
                                        query.value(3).toInt(&ok)));//y_final

            }
        }
        else{
            qDebug() << "No hay datos";
            qDebug() << query.lastError().text();
        }
    }
    return lineas;
}


