#ifndef ENEMY_H
#define ENEMY_H


class Enemy
{
private:
    int hp;
    int is_e = 0;
public:
    Enemy(int life_value);
    int gethp();
    void updateHp(int newhp);
    void updateE(int newe);
    int getE();
};

#endif // ENEMY_H
