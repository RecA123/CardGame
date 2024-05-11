#ifndef ENEMY_H
#define ENEMY_H


class Character;

class Enemy
{
private:
    int hp;
    int is_e = 0;
public:
    int actTime = 0;
    int burstRnd = 0;
    bool is_frozen = 0;
    Enemy(int life_value);
    int gethp();
    void updateHp(int newhp);
    void updateE(int newe);
    int getE();
    void updateIs_fronzen();
    void normalAtk(Character *c);
    void Burst(Character *c);
};

#endif // ENEMY_H
