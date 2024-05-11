#include "object.h"

Object::Object(int n)
{
    round = n;
}

void Object::addIs_round()
{
    is_round++;
}

void Object::updateO()
{
    is_round = 0;
}


Aozi::Aozi(int n):Object(n)
{

}

void Aozi::effect(Character *c, Enemy *e)
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

void Aozi::addIs_round()
{
    is_round++;
}

void Aozi::updateO()
{
    is_round = 0;
}
