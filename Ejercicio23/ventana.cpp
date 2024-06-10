#include "ventana.h"
#include "ui_ventana.h"
#include "character.h"
#include "arquero.h"
#include "soldado.h"
#include "mago.h"
#include <QDebug>


Ventana::Ventana(QWidget *parent) : QWidget(parent), ui(new Ui::Ventana)
{
    ui->setupUi(this);
    this->ui->twPersonajes->setColumnCount(6);
    this->ui->twPersonajes->setHeaderLabels({"NOMBRE","TIPO", "HP","ATAQUE","DEFENSA","ITEMS"});
    crearPersonajes();
    connect(this->ui->pbCrearPersonajes, SIGNAL(pressed()), this, SLOT(slot_publicarPersonajes()));
}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::setLabelText(QString texto)
{
    this->ui->lUsuario->setText(texto);
}

void Ventana::crearPersonajes()
{
    srand(time(NULL));
    int dado = rand()%6 + 1;
    QVector<std::string> nombres = {"Rahceoead","Ferth'chell","Deb'bras","Cynburcuth","Stee","Jo'cen","Annordruth","Sathaeferd",
                                    "Wigdraniel","Acaranncwen","Bri-elf","Shadodvid","Ris-ferth","Ceol-gar","Ferthjaceo","Werd-hildi","Ni'jen","Sha-bar","Isumdicwulfpaul","Grimfortintim"};
    for(int i=0; i<20;i++){
        if(dado < 2){
            personajes.push_back(new Soldado(rand()%100 + 1,rand()%100 + 1,rand()%100 + 1, nombres[rand()%20]));
        }
        else if(dado < 4){
            personajes.push_back(new Arquero(rand()%100 + 1,rand()%100 + 1,rand()%100 + 1, nombres[rand()%20]));
        }
        else{
            personajes.push_back(new Mago(rand()%100 + 1,rand()%100 + 1,rand()%100 + 1, nombres[rand()%20], "Oscura"));
        }
        dado = rand()%6 + 1;

    }
}

void Ventana::slot_publicarPersonajes()
{
    //qDebug() << personajes;
    for(Character* p : personajes){
        QTreeWidgetItem* item = new QTreeWidgetItem(this->ui->twPersonajes);
        if(p->GetTipo() == "Arquero"){
            Arquero* a = static_cast<Arquero*>(p);
            item->setText(0, QString::fromStdString(a->GetName()));
            item->setText(1, QString::fromStdString(a->GetTipo()));
            item->setText(2, QString::number(a->GetHp()));
            item->setText(3, QString::number(a->GetAttack()));
            item->setText(4, QString::number(a->GetDefense()));
            item->setText(5, QString::number(a->getArrows()));
        }
        else if(p->GetTipo() == "Soldado"){
            Soldado* a = static_cast<Soldado*>(p);
            item->setText(0, QString::fromStdString(a->GetName()));
            item->setText(1, QString::fromStdString(a->GetTipo()));
            item->setText(2, QString::number(a->GetHp()));
            item->setText(3, QString::number(a->GetAttack()));
            item->setText(4, QString::number(a->GetDefense()));
            item->setText(5, QString::number(a->getArmadura()));
        }
        else{
            Mago* a = static_cast<Mago*>(p);
            item->setText(0, QString::fromStdString(a->GetName()));
            item->setText(1, QString::fromStdString(a->GetTipo()));
            item->setText(2, QString::number(a->GetHp()));
            item->setText(3, QString::number(a->GetAttack()));
            item->setText(4, QString::number(a->GetDefense()));
            item->setText(5, QString::fromStdString(a->Principe::hablar()));
        }
    }

}

