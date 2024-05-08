#ifndef DIONA_H
#define DIONA_H

#include "character.h"

class Diona : public Character
{
public:
    Diona(int life_value, int e, int ise, int w, bool isw);
    void normalAttack(Enemy *e);
    void elementalSkill(Enemy *e);
    void elementalBurst(Enemy *e);
};

#endif // DIONA_H
