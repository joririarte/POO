// Ventana.h

#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>

class Ventana : public QWidget
{
    Q_OBJECT

public:
    explicit Ventana(QWidget* parent = nullptr);
    ~Ventana();

private slots:
    void startDownload();
    void descargaFinalizada(class QNetworkReply*);

private:
    class QLineEdit* urlLineEdit;
    class QPushButton* downloadButton;
    class Barra* progressBar;
};

#endif // VENTANA_H
