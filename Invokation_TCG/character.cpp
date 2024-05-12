#include "character.h"

Character::Character(int life_value, int e, int ise, int w, bool isw)
{
    hp = life_value;//初始化生命值
    e_type = e;//初始化元素类型
    is_e = ise;//初始化附着元素
    w_type = w;
    is_w = isw;
}

int Character::gethp()
{
    return hp;
}

void Character::updatehp(int n)
{
    hp = n;
}

int Character::getE_type()
{
    return e_type;
}

void Character::addHp(int n)
{
    if(this->hp+n >= 10){
        this->hp = 10;
    }else{
        this->hp+=n;
    }

}
