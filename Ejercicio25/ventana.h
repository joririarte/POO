#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QStyledItemDelegate>

QT_BEGIN_NAMESPACE
namespace Ui { class Ventana; }
QT_END_NAMESPACE

class Ventana : public QWidget
{
    Q_OBJECT

public:
    Ventana(QWidget *parent = nullptr);
    ~Ventana();
    void setUser(QString);
    void updateTreeWidget();

private:
    Ui::Ventana *ui;
    void cargarUsuarios();
    void setupListaUsuarios();
private slots:
    void slot_actualizarUsuario(class QTreeWidgetItem*,int);
signals:
    void signal_volver();
};

class NonEditableDelegate : public QStyledItemDelegate {
public:
    NonEditableDelegate(QObject *parent = nullptr);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};
#endif // VENTANA_H
