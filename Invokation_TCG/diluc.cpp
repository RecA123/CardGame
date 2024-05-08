#include "diluc.h"

Diluc::Diluc(int life_value, int e, int ise, int w, bool isw):Character(life_value, e,ise,w,isw)
{
    name = "迪卢克";
}

void Diluc::normalAttack(Enemy *e)
{
    int damage = 2;
    int new_e_hp = e->gethp()-damage;
    if(new_e_hp < 0)
        new_e_hp = 0;
    e->updateHp(new_e_hp);
}

void Diluc::elementalSkill(Enemy *e)
{
    int damage = 3;
    int new_e_hp = e->gethp()-damage;
    if(new_e_hp < 0)
        new_e_hp = 0;
    e->updateE(1);
    e->updateHp(new_e_hp);
}

void Diluc::elementalBurst(Enemy *e)
{
    int damage = 8;
    int new_e_hp = e->gethp()-damage;
    if(new_e_hp < 0)
        new_e_hp = 0;
    e->updateE(1);
    e->updateHp(new_e_hp);
}
