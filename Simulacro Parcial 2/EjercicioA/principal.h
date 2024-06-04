#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QWidget>
#include "linea.h"
#include "admindb.h"
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QWidget
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();
protected:
    virtual void paintEvent(QPaintEvent *event) override;

private:
    Ui::Principal *ui;
    QVector<Linea> lineas;
};
#endif // PRINCIPAL_H
