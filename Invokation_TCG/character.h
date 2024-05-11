#ifndef CHARACTER_H
#define CHARACTER_H
#include <QString>
#include <enemy.h>
//火1 水2 雷3 冰4 草5 岩6 风7 物理0
class Character
{
private:
    int hp;
    int e_type;
    int is_e;
    int w_type;
    bool is_w;
    bool is_dead = 0;

public:
    QString name;
    int burst_cost = 0;
    int energy;
    int is_energy;
    Character(int life_value, int e, int ise, int w, bool isw);
    int gethp();
    void updatehp(int n);
    int getE_type();
    void addHp(int n);
    virtual void normalAttack(Enemy *e) = 0;
    virtual void elementalSkill(Enemy *e) = 0;
    virtual void elementalBurst(Enemy *e) = 0;
};

#endif // CHARACTER_H
