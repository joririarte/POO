#ifndef ADMINDB_H
#define ADMINDB_H
#include <QSqlDatabase>
#include <QString>
#include <QObject>
#include <QVector>
#include <QPair>
#include "linea.h"

class AdminDB : public QObject {
    Q_OBJECT
public:
    static AdminDB* getInstance();

    bool conectar(QString archivoSqlite);
    QSqlDatabase getDB();
    //leer lineas -> devuelve un vector de lineas
    QVector<Linea> obtenerLineas();

private:
    QSqlDatabase db;
    static AdminDB* instance;
    AdminDB(QObject* parent = nullptr);

};

#endif // ADMINDB_H
