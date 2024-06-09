#include "ventana.h"
#include "ui_ventana.h"
#include "admindb.h"
#include <QDebug>
#include <QLineEdit>

Ventana::Ventana(QWidget *parent) : QWidget(parent), ui(new Ui::Ventana)
{
    ui->setupUi(this);
    // Asignar el delegado personalizado
    NonEditableDelegate *delegate = new NonEditableDelegate(this->ui->twListaUsuarios);
    this->ui->twListaUsuarios->setItemDelegate(delegate);

    this->updateTreeWidget();
    connect(this->ui->twListaUsuarios,SIGNAL(itemChanged(QTreeWidgetItem*,int)),this,SLOT(slot_actualizarUsuario(QTreeWidgetItem*,int)));
    connect(this->ui->pbVolver, SIGNAL(pressed()), this, SIGNAL(signal_volver()));

}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::setUser(QString user)
{
    this->ui->lUsuarioActivo->setText("Usuario: " + user);
}

void Ventana::updateTreeWidget()
{
    this->ui->twListaUsuarios->clear();
    this->setupListaUsuarios();
    this->cargarUsuarios();
}

void Ventana::cargarUsuarios()
{
    QVector<QStringList> respuesta = AdminDB::getInstancia()->select("SELECT * FROM usuarios");

    for(QStringList registro : respuesta){
        QTreeWidgetItem* item = new QTreeWidgetItem(this->ui->twListaUsuarios);
        for(int i=0; i<6 ; i++){
            item->setText(i, i!=2 ? registro[i] : "*******");
            item->setFlags(item->flags() | Qt::ItemIsEditable);
        }
    }
}

void Ventana::setupListaUsuarios()
{
    this->ui->twListaUsuarios->setColumnCount(6);
    this->ui->twListaUsuarios->setHeaderLabels({"ID","USUARIO", "CLAVE", "NOMBRE","APELLIDO","MAIL"});
    this->ui->twListaUsuarios->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked | QAbstractItemView::AnyKeyPressed);
}

void Ventana::slot_actualizarUsuario(QTreeWidgetItem* item,int column)
{
    if (column > 0) { // Only update if Name or Email columns are changed
            int id = item->text(0).toInt();
            QString columnName;
            switch (column) {
            case 1:
                columnName = "usuario";
                break;
            case 3:
                columnName = "nombre";
                break;
            case 4:
                columnName = "apellido";
                break;
            case 5:
                columnName = "mail";
                break;
            default:
                return;
            }

            QString newValue = item->text(column);

            if (!AdminDB::getInstancia()->actualizarDatos(columnName,newValue,item->text(0))) {
                qDebug() << "Error en la actualizacion";
            }
        }
}

//////////////////////////////////////////////////////////////////////////////////////////////
/// \brief NonEditableDelegate::NonEditableDelegate
/// \param parent
///

NonEditableDelegate::NonEditableDelegate(QObject *parent) : QStyledItemDelegate(parent){}

QWidget *NonEditableDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

    // Si la columna es la que no queremos que sea editable, devolvemos nullptr
    if (index.column() <=2) { // Cambia 0 por el índice de la columna que deseas no editable
        return nullptr;
    }
    // Para las demás columnas, usamos la implementación por defecto
    return QStyledItemDelegate::createEditor(parent, option, index);

}
