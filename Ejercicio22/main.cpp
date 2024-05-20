#include <iostream>
#include <ctime>
#include <vector>
#include "instrumento.h"
#include "guitarra.h"
#include "teclado.h"
#include "bateria.h"


using namespace std;

Instrumento* selectInstrument()
{
    Instrumento* instrumento;
    switch (rand()%3) {
    case 0://guitarra
        instrumento = new Guitarra();
        break;
    case 1://Bateria
        instrumento = new Bateria();
        break;
    case 2://Teclado
        instrumento = new Teclado();
        break;
    }
    return instrumento;
}

int main(int argc, char ** argv){
    srand(time(NULL));

    vector<Instrumento*> instrumentos;

    for(int i=0;i<5;i++){
        instrumentos.push_back(selectInstrument());
    }
    for(Instrumento* instrumento : instrumentos){
        cout<<"Marca: " << instrumento->verlo() << endl;
        cout<<"Sonido: " << instrumento->sonar() << endl << endl;
    }
    return 0;
}
