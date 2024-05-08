#include "enemy.h"

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
