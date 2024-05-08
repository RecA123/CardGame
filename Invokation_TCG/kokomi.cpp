#include "kokomi.h"

Kokomi::Kokomi(int life_value, int e, int ise, int w, bool isw):Character(life_value, e,ise,w,isw)
{
    name = "珊瑚宫心海";
}

void Kokomi::normalAttack(Enemy *e)
{
    int damage = 2;
    int new_e_hp = e->gethp()-damage;
    if(new_e_hp < 0)
        new_e_hp = 0;
    e->updateHp(new_e_hp);
}

void Kokomi::elementalSkill(Enemy *e)
{
    int damage = 2;
    int new_e_hp = e->gethp()-damage;
    if(new_e_hp < 0)
        new_e_hp = 0;
    e->updateHp(new_e_hp);
}

void Kokomi::elementalBurst(Enemy *e)
{
    int damage = 2;
    int new_e_hp = e->gethp()-damage;
    if(new_e_hp < 0)
        new_e_hp = 0;
    e->updateHp(new_e_hp);
}
