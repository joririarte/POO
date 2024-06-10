#ifndef ARQUERO_H
#define ARQUERO_H
#include "character.h"

class Arquero : public Character
{
private:
    int arrows;
public:
    Arquero(int hp, int attack, int defense, std::string name);

    int getArrows() { return arrows; };
    void setArrows(int arrows);
    virtual int TakeDamage(Character *enemy) override;
};

#endif // ARQUERO_H
