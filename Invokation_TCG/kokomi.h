#ifndef KOKOMI_H
#define KOKOMI_H

#include "character.h"

class Kokomi : public Character
{
public:
    Kokomi(int life_value, int e, int ise, int w, bool isw);
    void normalAttack(Enemy *e);
    void elementalSkill(Enemy *e);
    void elementalBurst(Enemy *e);
};

#endif // KOKOMI_H
