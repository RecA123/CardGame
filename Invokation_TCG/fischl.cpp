#include "fischl.h"

Fischl::Fischl(int life_value, int e, int ise, int w, bool isw):Character(life_value, e,ise,w,isw)
{
    name = "菲谢尔";
    burst_cost = 3;
    energy = 3;
    is_energy = 0;
}

void Fischl::normalAttack(Enemy *e)
{
    int damage = 2;
    int new_e_hp = e->gethp()-damage;
    if(new_e_hp < 0)
        new_e_hp = 0;
    e->updateHp(new_e_hp);
}

void Fischl::elementalSkill(Enemy *e)
{
    int damage = 1;
    if(e->getE() == 1 || e->getE() == 2 || e->getE() == 4){
        damage += 1;
        e->updateE(0);
    }else{
        e->updateE(3);
    }
    int new_e_hp = e->gethp()-damage;
    if(new_e_hp < 0)
        new_e_hp = 0;
    e->updateHp(new_e_hp);
}

void Fischl::elementalBurst(Enemy *e)
{
    int damage = 4;
    if(e->getE() == 1 || e->getE() == 2 || e->getE() == 4){
        damage += 1;
        e->updateE(0);
    }else{
        e->updateE(3);
    }
    int new_e_hp = e->gethp()-damage;
    if(new_e_hp < 0)
        new_e_hp = 0;
    e->updateHp(new_e_hp);
}
