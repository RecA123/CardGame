#ifndef CHARACTER_H
#define CHARACTER_H
#include <QPixmap>
#include <enemy.h>


class AbstractCharacter
{
    public:
        int element;
        int weapon;
        int hp=10;
        bool is_weapon=0;
        int attached_e;
    public:
        virtual void normalAttack(AbstractEnemy *){

        }
        virtual void elementalSkill(AbstractEnemy *){

        }
        virtual void elementalBurst(AbstractEnemy *){

        }
    public:

};

class Diluc:public AbstractCharacter
{
public:
    Diluc();
    virtual void normalAttack(AbstractEnemy *enemy);
    virtual void elementalSkill(AbstractEnemy *enemy);
    virtual void elementalBurst(AbstractEnemy *enemy);
};

/*class Diona:public AbstractCharacter
{
public:
    Diona();
    virtual void normalAttack();
    virtual void elementalSkill();
    virtual void elementalBurst();
};

class Kokomi:public AbstractCharacter
{
public:
    Kokomi();
    virtual void normalAttack();
    virtual void elementalSkill();
    virtual void elementalBurst();
};

class Xingqiu:public AbstractCharacter
{

public:
    Xingqiu();
    virtual void normalAttack();
    virtual void elementalSkill();
    virtual void elementalBurst();
};

class Ningguang:public AbstractCharacter
{
public:
    Ningguang();
    virtual void normalAttack();
    virtual void elementalSkill();
    virtual void elementalBurst();
};

class Fischl:public AbstractCharacter
{
public:
    Fischl();
    virtual void normalAttack();
    virtual void elementalSkill();
    virtual void elementalBurst();
};
*/


#endif // CHARACTER_H
