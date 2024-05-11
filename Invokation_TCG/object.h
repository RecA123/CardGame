#ifndef OBJECT_H
#define OBJECT_H

class Character;
#include <enemy.h>

class Object
{
public:
    int round;
    int is_round;

    Object(int n);
    void addIs_round();
    void updateO();
    virtual void effect(Character *c, Enemy *e) = 0;
};

class Aozi :public Object
{
public:
    Aozi(int n);
    void addIs_round();
    void updateO();
    void effect(Character *c, Enemy *e);

};

#endif // OBJECT_H
