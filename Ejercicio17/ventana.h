#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>

namespace Ui {
class Ventana;
}

class Ventana : public QWidget
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);
    ~Ventana();

private:
    Ui::Ventana *ui;
    QImage imgFondo;
    class ImageFetcher* imgFetcher;
protected:
    void paintEvent(QPaintEvent *event) override;
private slots:
    void slot_publicarImagen(QImage);
signals:
    void signal_imagenLista();
};

#endif // VENTANA_H
