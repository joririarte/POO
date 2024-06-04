#ifndef ADMINDB_H
#define ADMINDB_H
#include <QSqlDatabase>
#include <QString>
#include <QObject>
#include <QVector>
#include <QPair>

class AdminDB : public QObject {
    Q_OBJECT
public:
    static AdminDB* getInstance();

    bool conectar(QString archivoSqlite);
    QSqlDatabase getDB();
    QStringList validarUsuario(QString usuario, QString clave);
    QVector<QStringList> select(QString comando);

private:
    QSqlDatabase db;
    static AdminDB* instance;
    AdminDB(QObject* parent = nullptr);

};

#endif // ADMINDB_H
