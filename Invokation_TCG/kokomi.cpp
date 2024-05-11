#include "kokomi.h"

Kokomi::Kokomi(int life_value, int e, int ise, int w, bool isw):Character(life_value, e,ise,w,isw)
{
    name = "珊瑚宫心海";
    burst_cost = 3;
    energy = 2;
    is_energy = 0;
}

void Kokomi::normalAttack(Enemy *e)
{
    int damage = 2;
    if(e->getE() == 1 || e->getE() == 3){
        damage += 1;
        e->updateE(0);
    }else if(e->getE() == 4){
        e->updateIs_fronzen();
        e->updateE(0);
    }else{
        e->updateE(2);
    }
    int new_e_hp = e->gethp()-damage;
    if(new_e_hp < 0)
        new_e_hp = 0;
    e->updateHp(new_e_hp);
}

void Kokomi::elementalSkill(Enemy *e)
{
    int damage = 0;
    int new_e_hp = e->gethp()-damage;
    if(new_e_hp < 0)
        new_e_hp = 0;
    e->updateHp(new_e_hp);
}

void Kokomi::elementalBurst(Enemy *e)
{
    int damage = 2;
    if(e->getE() == 1 || e->getE() == 3){
        damage += 1;
        e->updateE(0);
    }else if(e->getE() == 4){
        e->updateIs_fronzen();
        e->updateE(0);
    }else{
        e->updateE(2);
    }
    nbstate = 1;
    int new_e_hp = e->gethp()-damage;
    if(new_e_hp < 0)
        new_e_hp = 0;
    e->updateHp(new_e_hp);
}
