#include "character.h"

Character::Character()
{

}

void Character::SetHp(int newHp)
{
    this->hp = newHp;
}

void Character::SetAttack(int newAttack)
{
    this->attack = newAttack;
}

void Character::SetDefense(int newDefense)
{
    this->defense = newDefense;
}

void Character::SetName(std::string newName)
{
    this->name = newName;
}

int Character::TakeDamage(Character *enemy)
{
    int damageTaken = this->defense - enemy->GetAttack();

    hp -= damageTaken;

    alive = hp <= 0;

    return damageTaken;
}
