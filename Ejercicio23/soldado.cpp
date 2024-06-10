#include "soldado.h"

Soldado::Soldado(int hp,
                 int attack,
                 int defense,
                 std::string name) : Character(hp,attack,defense,name,"Soldado"), armadura(50)
{

}

void Soldado::setArmadura(int armadura)
{
    this->armadura = armadura;
}

int Soldado::TakeDamage(Character *enemy)
{
    int damageTaken = this->defense + this->armadura - enemy->GetAttack() * ((enemy->GetTipo() != "Soldado")*2 + 1);

    hp -= damageTaken;

    alive = hp <= 0;

    return damageTaken;
}
