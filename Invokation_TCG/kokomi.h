#ifndef KOKOMI_H
#define KOKOMI_H

#include "character.h"

class Kokomi : public Character
{
public:
    bool nbstate = 0;
    int cd = 2;
    Kokomi(int life_value, int e, int ise, int w, bool isw);
    void normalAttack(Enemy *e);
    void elementalSkill(Enemy *e);
    void elementalBurst(Enemy *e);
};

#endif // KOKOMI_H
