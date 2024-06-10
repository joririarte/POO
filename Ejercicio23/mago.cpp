#include "mago.h"

Mago::Mago(int hp,
           int attack,
           int defense,
           std::string name,
           std::string tipoMagia) : Character(hp,attack,defense,name,"Mago"), Principe(), tipoMagia(tipoMagia), mana(100)
{

}

void Mago::setMana(int mana)
{
    this->mana = mana;
}

void Mago::setTipoMagia(std::string TipoMagia)
{
    this->tipoMagia = TipoMagia;
}

int Mago::TakeDamage(Character *enemy)
{
    int damageTaken = this->defense - enemy->GetAttack();

        hp -= damageTaken;

        alive = hp <= 0;

        return damageTaken;
}
