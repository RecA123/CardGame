#ifndef FISCHL_H
#define FISCHL_H

#include <character.h>
class Fischl:public Character
{
public:
    Fischl(int life_value, int e, int ise, int w, bool isw);
    void normalAttack(Enemy *e);
    void elementalSkill(Enemy *e);
    void elementalBurst(Enemy *e);
};

#endif // FISCHL_H
