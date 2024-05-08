#ifndef NINGGUANG_H
#define NINGGUANG_H

#include "character.h"

class Ningguang : public Character
{
public:
    Ningguang(int life_value, int e, int ise, int w, bool isw);
    void normalAttack(Enemy *e);
    void elementalSkill(Enemy *e);
    void elementalBurst(Enemy *e);
};

#endif // NINGGUANG_H
