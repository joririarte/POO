#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include "parser.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Ventana; }
QT_END_NAMESPACE

class Ventana : public QWidget
{
    Q_OBJECT

public:
    Ventana(QWidget *parent = nullptr);
    ~Ventana();

private:
    Ui::Ventana *ui;
    Parser* parser;
    QString directorioRecursos;
    bool createDir(QString path);
    class Downloader* downloader;
private slots:
    void slot_obtenerRecursos();
    void slot_publicarRecursos(QHash<QString, Parser::Tipo>*);
    void onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void onGlobalDownloadProgress(int downloadsCompleted, int totalDownloads);
    void slot_updateLabelURL(QString);
};
#endif // VENTANA_H
