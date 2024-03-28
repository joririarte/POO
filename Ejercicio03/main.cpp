#include <iostream>
#include <QString>

namespace EjerciciosJor{
    QString getVersion(){

        return qVersion();
    }
};

int main(int argc, char** argv){

    std::cout << EjerciciosJor::getVersion().toStdString() << std::endl;

    return 0;
}
