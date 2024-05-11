#include "jean.h"

Jean::Jean(int life_value, int e, int ise, int w, bool isw):Character(life_value, e,ise,w,isw)
{
    name = "琴";
    burst_cost = 4;
    energy = 2;
    is_energy = 0;
}

void Jean::normalAttack(Enemy *e)
{
    int damage = 2;
    int new_e_hp = e->gethp()-damage;
    if(new_e_hp < 0)
        new_e_hp = 0;
    e->updateHp(new_e_hp);
}

void Jean::elementalSkill(Enemy *e)
{
    int damage = 3;
    if(e->getE() == 1 || e->getE() == 2 || e->getE() == 3 || e->getE() == 4){
        damage += 1;
        e->updateE(0);
    }
    int new_e_hp = e->gethp()-damage;
    if(new_e_hp < 0)
        new_e_hp = 0;
    e->updateHp(new_e_hp);
}

void Jean::elementalBurst(Enemy *e)
{
    int damage = 0;
    this->addHp(2);
    int new_e_hp = e->gethp()-damage;
    if(new_e_hp < 0)
        new_e_hp = 0;
    e->updateHp(new_e_hp);
}
