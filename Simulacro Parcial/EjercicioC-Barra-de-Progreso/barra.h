// Barra.h

#ifndef BARRA_H
#define BARRA_H

#include <QProgressBar>
#include <QNetworkReply>

class Barra : public QProgressBar
{
    Q_OBJECT

public:
    explicit Barra(QWidget* parent = nullptr);
    ~Barra();

public slots:
    void actualizarBarra(qint64,qint64);
};

#endif // BARRA_H
