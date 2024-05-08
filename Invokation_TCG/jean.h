#ifndef JEAN_H
#define JEAN_H

#include "character.h"

class Jean : public Character
{
public:
    Jean(int life_value, int e, int ise, int w, bool isw);
    void normalAttack(Enemy *e);
    void elementalSkill(Enemy *e);
    void elementalBurst(Enemy *e);
};

#endif // JEAN_H
