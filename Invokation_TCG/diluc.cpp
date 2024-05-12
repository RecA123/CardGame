#include "diluc.h"

Diluc::Diluc(int life_value, int e, int ise, int w, bool isw)
    :Character(life_value, e,ise,w,isw)
{
    name = "迪卢克";
    burst_cost = 4;
    energy = 3;
    is_energy = 0;
}

void Diluc::normalAttack(Enemy *e)
{
    //设置伤害值
    int damage = 2;
    //更新敌人血量
    int new_e_hp = e->gethp()-damage;
    if(new_e_hp < 0)
        new_e_hp = 0;
    e->updateHp(new_e_hp);
}

void Diluc::elementalSkill(Enemy *e)
{
    //设置伤害
    int damage = 3;

    //火1 水2 雷3 冰4 草5 岩6 风7 物理0
    //判断是否触发元素反应
    //getE()函数获取敌人身上附着的元素
    if(e->getE() == 2 || e->getE() == 3 || e->getE() == 4){
        damage += 1;
        e->updateE(0);
    }else{
        e->updateE(1);
    }

    //更新敌人血量
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
