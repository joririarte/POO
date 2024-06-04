#ifndef PAINT_H
#define PAINT_H

#include <QWidget>

namespace Ui {
class Paint;
}

class Paint : public QWidget
{
    Q_OBJECT

public:
    explicit Paint(QWidget *parent = nullptr);
    ~Paint();

private:
    Ui::Paint *ui;
private slots:
    void slot_cambiarTrazo(QString);
    void slot_borrarPintura();
};

#endif // PAINT_H
