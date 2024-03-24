#include "persona.h"
#include "poste.h"
#include <iostream>

template <class T>
void PrintDescription(T* object){
    std::cout << object->Descripcion() << std::endl;
}

int main(){
    Poste* poste = new Poste(7, 20);
    Persona* persona = new Persona("Jorge", 31);

    std::cout << "Descripcion del Poste:\n";
    PrintDescription(poste);

    std::cout << "Descripcion de la Persona:\n";
    PrintDescription(persona);
    return 0;
}
