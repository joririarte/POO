#ifndef MAGO_H
#define MAGO_H
#include "character.h"
#include "principe.h"

class Mago : public Character, public Principe
{
private:
    std::string tipoMagia;
    int mana;
public:
    Mago(int hp, int attack, int defense, std::string name, std::string tipoMagia);
    int getMana()               { return mana; };
    std::string getTipoMagia()  { return tipoMagia; };
    void setMana(int mana);
    void setTipoMagia(std::string TipoMagia);

    int TakeDamage(Character *enemy) override;
};

#endif // MAGO_H
