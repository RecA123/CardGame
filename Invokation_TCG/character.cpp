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
