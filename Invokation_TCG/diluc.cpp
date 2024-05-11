#include "diluc.h"

Diluc::Diluc(int life_value, int e, int ise, int w, bool isw):Character(life_value, e,ise,w,isw)
{
    name = "迪卢克";
    burst_cost = 4;
    energy = 3;
    is_energy = 0;
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
    if(e->getE() == 2 || e->getE() == 3 || e->getE() == 4){
        damage += 1;
        e->updateE(0);
    }else{
        e->updateE(1);
    }
    int new_e_hp = e->gethp()-damage;
    if(new_e_hp < 0)
        new_e_hp = 0;

    e->updateHp(new_e_hp);
}

void Diluc::elementalBurst(Enemy *e)
{

    int damage = 8;
    if(e->getE() == 2 || e->getE() == 3 || e->getE() == 4){
        damage += 1;
        e->updateE(0);
    }else{
        e->updateE(1);
    }
    int new_e_hp = e->gethp()-damage;
    if(new_e_hp < 0)
        new_e_hp = 0;

    e->updateHp(new_e_hp);
}
