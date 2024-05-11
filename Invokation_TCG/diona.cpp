#include "diona.h"

Diona::Diona(int life_value, int e, int ise, int w, bool isw):Character(life_value, e,ise,w,isw)
{
    name = "迪奥娜";
    energy = 3;
    is_energy = 0;
    burst_cost = 3;
}

void Diona::normalAttack(Enemy *e)
{
    int damage = 2;
    int new_e_hp = e->gethp()-damage;
    if(new_e_hp < 0)
        new_e_hp = 0;
    e->updateHp(new_e_hp);
}

void Diona::elementalSkill(Enemy *e)
{
    int damage = 2;
    if(e->getE() == 1 || e->getE() == 3){
        damage += 1;
        e->updateE(0);
    }else if(e->getE() == 2){
        e->updateIs_fronzen();
        e->updateE(0);
    }else{
        e->updateE(4);
    }
    int new_e_hp = e->gethp()-damage;
    if(new_e_hp < 0)
        new_e_hp = 0;
    e->updateHp(new_e_hp);
}

void Diona::elementalBurst(Enemy *e)
{
    int damage = 1;
    if(e->getE() == 1 || e->getE() == 3){
        damage += 1;
        e->updateE(0);
    }else if(e->getE() == 2){
        e->updateIs_fronzen();
        e->updateE(0);
    }else{
        e->updateE(4);
    }
    this->addHp(2);
    int new_e_hp = e->gethp()-damage;
    if(new_e_hp < 0)
        new_e_hp = 0;
    e->updateHp(new_e_hp);
}
