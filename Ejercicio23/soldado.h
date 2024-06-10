#ifndef SOLDADO_H
#define SOLDADO_H

#include "character.h"

class Soldado : public Character
{
private:
    int armadura;
public:
    Soldado(int hp, int attack, int defense, std::string name);
    int getArmadura() { return armadura; };
    void setArmadura(int armadura);
    virtual int TakeDamage(Character *enemy) override;
};

#endif // SOLDADO_H
