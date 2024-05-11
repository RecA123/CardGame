#include "enemy.h"

#include <character.h>
Enemy::Enemy(int life_value)
{
    hp = life_value;
}

int Enemy::gethp()
{
    return hp;
}

void Enemy::updateHp(int newhp)
{
    hp = newhp;
}

void Enemy::updateE(int newe)
{
    is_e = newe;
}

int Enemy::getE()
{
    return is_e;
}

void Enemy::updateIs_fronzen()
{
    is_frozen = 1;
}

void Enemy::normalAtk(Character *c)
{
    int damage = 2;
    int new_e_hp = c->gethp()-damage;
    if(new_e_hp < 0)
        new_e_hp = 0;
    c->updatehp(new_e_hp);
    burstRnd += 1;
}

void Enemy::Burst(Character *c)
{
    int damage = 4;
    int new_e_hp = c->gethp()-damage;
    if(new_e_hp < 0)
        new_e_hp = 0;
    c->updatehp(new_e_hp);
    burstRnd = 0;
}
