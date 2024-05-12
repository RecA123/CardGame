#ifndef ENEMY_H
#define ENEMY_H


class Character;

class Enemy
{
private:
    int hp;//血量
    int is_e = 0;//元素附着
public:
    int actTime = 0;//行动次数
    int burstRnd = 0;//爆发冷却回合
    bool is_frozen = 0;//是否冻结判断
    //构造函数
    Enemy(int life_value);
    //获取当前血量
    int gethp();
    //更新血量
    void updateHp(int newhp);
    //更新元素附着
    void updateE(int newe);
    //获取当前元素附着
    int getE();
    //更新冻结状态
    void updateIs_fronzen();
    //普通攻击
    void normalAtk(Character *c);
    //爆发攻击
    void Burst(Character *c);
};

#endif // ENEMY_H
