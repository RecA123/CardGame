#ifndef DILUC_H
#define DILUC_H
#include <character.h>
#include <QString>
class Diluc : public Character
{

public:
    bool nbstate = 0;
    int round = 3;
    Diluc(int life_value, int e, int ise, int w, bool isw);
    void normalAttack(Enemy *e);
    void elementalSkill(Enemy *e);
    void elementalBurst(Enemy *e);
};

#endif // DILUC_H
