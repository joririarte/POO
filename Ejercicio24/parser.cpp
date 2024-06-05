#include "parser.h"
#include "htmlfetcher.h"
#include <QHash>
#include <QRegularExpression>
#include <QVariant>
#include <QDebug>

Parser::Parser(QObject *parent) : QObject(parent)
{
    recursos = new QHash<QString,Tipo>;
    htmlFetcher = new HtmlFetcher;
    connect(this->htmlFetcher, SIGNAL(signal_htmlReady(QString)),this,SLOT(slot_htmlCodeReady(QString)));
}

void Parser::setOrigen(QString urlOrigen)
{
    this->urlOrigen = urlOrigen;
}

void Parser::getRecursos()
{
    if(urlOrigen != ""){
        htmlFetcher->getHtml(urlOrigen);
        qDebug() << "htmlFetcher pedido";
    }
}

QString Parser::getEnumName(Parser::Tipo t)
{
    return QVariant::fromValue(t).toString();
}

void Parser::slot_htmlCodeReady(QString html)
{
    qDebug() << "html recibido";
    //Espresion regular para leer links
    QRegularExpression regex(R"(https?://[^\"\'\s]+?\.(?:png|jpe?g|gif|bmp|svg|js|css))",QRegularExpression::CaseInsensitiveOption);

    QRegularExpressionMatchIterator i = regex.globalMatch(html);
    while(i.hasNext()){
        QRegularExpressionMatch match = i.next();
        QString recurso = match.captured(0);
        if(!recursos->contains(recurso)){
            if (recurso.endsWith(".css")) {
                recursos->insert(recurso, CSS);
            }
            else if (recurso.endsWith(".js")) {
                recursos->insert(recurso, JAVASCRIPT);
            }
            else if (recurso.endsWith(".png",  Qt::CaseInsensitive)  ||
                     recurso.endsWith(".jpg",  Qt::CaseInsensitive)  ||
                     recurso.endsWith(".jpeg", Qt::CaseInsensitive)  ||
                     recurso.endsWith(".gif",  Qt::CaseInsensitive)  ||
                     recurso.endsWith(".bmp",  Qt::CaseInsensitive)  ||
                     recurso.endsWith(".svg",  Qt::CaseInsensitive)) {
                recursos->insert(recurso, IMAGEN);
            }
        }
    }
    if(!recursos->isEmpty()){
        qDebug() << "recursos listos";
        emit signal_recursosReady(recursos);
    }
}

