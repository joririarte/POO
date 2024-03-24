#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

class Character
{
private:
    int hp;
    int attack;
    int defense;
    std::string name;
    bool alive = true;

public:
    Character();
    Character(int hp, int attack, int defense, std::string name) : hp(hp), attack(attack), defense(defense), name(name){}

    int GetHp() const               { return this->hp; }
    int GetAttack() const           { return this->attack; }
    int GetDefense() const          { return this->defense; }
    std::string GetName() const     { return this->name; }
    bool IsAlive() const            { return this->alive; }

    void SetHp(int newHp);
    void SetAttack(int newAttack);
    void SetDefense(int newDefense);
    void SetName(std::string newName);

    int TakeDamage(Character* enemy);
};

#endif // CHARACTER_H
