#ifndef ADMINDB_H
#define ADMINDB_H
#include <QSqlDatabase>
#include <QString>
#include <QObject>

class AdminDB : public QObject {
    Q_OBJECT
public:
    static AdminDB* getInstancia();
    bool conectar(QString archivoSqlite);
    QSqlDatabase getDB();
    QStringList validarUsuario(QString usuario, QString clave);
    bool insertarUsuario(QString usuario, QString clave, QString nombre, QString apellido, QString mail);
    QVector<QStringList> select(QString comando);
    bool actualizarDatos(QString campo, QString valor, QString id);
private:
    QSqlDatabase db;
    AdminDB(QObject* parent = nullptr);
    static AdminDB* instancia;
};

#endif // ADMINDB_H
