#ifndef FORMULARIO_H
#define FORMULARIO_H
#include <QWidget>

class Formulario : public QWidget
{
    Q_OBJECT
private:
    class QLabel  *lLegajo, *lNombre, *lApellido, *lCaptcha;
    class QLineEdit *leLegajo, *leNombre, *leApellido, *leCaptcha;
    class QPushButton *pbInsert;
    class QGridLayout *layout, *layoutCaptcha;
    class QGroupBox *gbCaptcha;
    bool validarCaptcha();
    bool formularioCompleto();
public:
    Formulario();
private slots:
    void alta_persona();
};

#endif // FORMULARIO_H
