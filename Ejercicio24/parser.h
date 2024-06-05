#ifndef PARSER_H
#define PARSER_H

#include <QObject>

class HtmlFetcher;

class Parser : public QObject
{
    Q_OBJECT
public:
    enum Tipo{CSS=1, JAVASCRIPT=2, IMAGEN=4};
    Q_ENUM(Tipo)

    explicit Parser(QObject *parent = nullptr);
    void setOrigen(QString urlOrigen);
    void getRecursos();
    static QString getEnumName(Tipo t);
private:
    QString urlOrigen, htmlCode;
    HtmlFetcher* htmlFetcher;
    QHash<QString,Tipo>* recursos;
private slots:
    void slot_htmlCodeReady(QString);
signals:
    void signal_recursosReady(QHash<QString, Parser::Tipo>*);
};

#endif // PARSER_H
