#include "character.h"

Character::Character(int hp,
                     int attack,
                     int defense,
                     std::string name,
                     std::string tipo) : hp(hp), attack(attack), defense(defense), name(name), tipo(tipo)
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
