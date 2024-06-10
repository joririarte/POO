#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

class Character
{
protected:
    int hp;
    int attack;
    int defense;
    std::string name, tipo;
    bool alive = true;

public:
    Character(int hp, int attack, int defense, std::string name, std::string tipo);

    int GetHp() const               { return this->hp; }
    int GetAttack() const           { return this->attack; }
    int GetDefense() const          { return this->defense; }
    std::string GetName() const     { return this->name; }
    std::string GetTipo() const     { return this->tipo; }
    bool IsAlive() const            { return this->alive; }

    void SetHp(int newHp);
    void SetAttack(int newAttack);
    void SetDefense(int newDefense);
    void SetName(std::string newName);
    void SetTipo(std::string newTipo);

    virtual int TakeDamage(Character* enemy) = 0;
};

#endif // CHARACTER_H
