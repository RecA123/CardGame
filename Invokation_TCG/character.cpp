#include "character.h"

Character::Character(int life_value, int e, int ise, int w, bool isw)
{
    hp = life_value;
    e_type = e;
    is_e = ise;
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
