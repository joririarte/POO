#ifndef ADMINDB_H
#define ADMINDB_H
#include <QSqlDatabase>
#include <QString>
#include <QObject>

class AdminDB : public QObject {
    Q_OBJECT
public:
    AdminDB(QObject* parent = nullptr);
    bool conectar(QString archivoSqlite);
    QSqlDatabase getDB();
    //bool validarUsuario(QString usuario, QString clave);
    QStringList validarUsuario(QString usuario, QString clave);
    bool insertarUsuario(QString usuario, QString clave, QString nombre, QString apellido, QString mail);
    QVector<QStringList> select(QString comando);
private:
    QSqlDatabase db;
};

#endif // ADMINDB_H
