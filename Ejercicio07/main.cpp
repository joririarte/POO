/*
 * Ejercicio 7
 * Se creo clase Character con sus atributos y métodos
 * Se crea un vector de la clase
 * Se utiliza la funcion sort + una funcion para indicar el orden en el vector
 * En este caso la funcion ordena por ataque ascendente, pero dicho criterio puede ser cualquier cosa
*/
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <algorithm>
#include "character.h"

void LoadCharacters(std::vector<Character*>* personajes)
{

    for(int i=0; i<10; i++){
        int hp = rand()%100 + 1;
        int attack = rand()%250 + 1;
        int defense = rand()%150 + 1;
        std::string name = "Character ";

        personajes->push_back(new Character(hp, attack, defense, name + std::to_string(i + 1)));
    }
}

void PrintCharacter(Character* character){
    std::cout << "\n\n########################################\n\n";
    std::cout << " # Hp: "<< character->GetHp() << std::endl;
    std::cout << " # Attack: "<< character->GetAttack() << std::endl;
    std::cout << " # Defense: "<< character->GetDefense() << std::endl;
    std::cout << " # Name: "<< character->GetName() << std::endl;
    std::cout << "\n\n########################################\n\n";
}

bool OrderByAttackASC(const Character *A, const Character *B)
{
    return A->GetAttack() < B->GetAttack();
}


int main(){

    srand(time(NULL));

    std::vector<Character*>* personajes = new std::vector<Character*>;

    LoadCharacters(personajes);

    std::cout << "Los Personajes son:\n\n";
    for(const auto& character : *personajes){
        PrintCharacter(character);
    }

    std::cout << "\n\nLos Personajes ordenados por ataque son:\n\n";
    std::sort(personajes->begin(), personajes->end(), OrderByAttackASC);

    for(const auto& character : *personajes){
        PrintCharacter(character);
    }

    return 0;
}
