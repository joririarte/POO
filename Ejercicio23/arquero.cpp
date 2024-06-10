#include "arquero.h"

Arquero::Arquero(int hp,
                 int attack,
                 int defense,
                 std::string name) : Character(hp, attack, defense, name, "Arquero"), arrows(12)
{

}

void Arquero::setArrows(int arrows)
{
    this->arrows = arrows;
}

int Arquero::TakeDamage(Character *enemy)
{
    int damageTaken = this->defense - enemy->GetAttack() * ((enemy->GetTipo() != "Arquero")*2 + 1) ;

    hp -= damageTaken;

    alive = hp <= 0;

    return damageTaken;
}
