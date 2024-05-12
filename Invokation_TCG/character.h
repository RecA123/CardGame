#ifndef CHARACTER_H
#define CHARACTER_H
#include <QString>
#include <enemy.h>
//火1 水2 雷3 冰4 草5 岩6 风7 物理0
class Character
{
private:
    int hp;//血量
    int e_type;//元素类型
    int is_e;//附着元素
    int w_type;
    bool is_w;
    bool is_dead = 0;//死亡状态

public:
    QString name;//名字
    int burst_cost = 0;//元素爆发花费
    int energy;//能量上限
    int is_energy;//当前能量值
    //构造函数
    Character(int life_value, int e, int ise, int w, bool isw);
    //获取角色血量
    int gethp();
    //更新角色血量
    void updatehp(int n);
    //获取角色元素类型
    int getE_type();
    //角色回血
    void addHp(int n);
    //普通攻击
    virtual void normalAttack(Enemy *e) = 0;
    //元素战技
    virtual void elementalSkill(Enemy *e) = 0;
    //元素爆发
    virtual void elementalBurst(Enemy *e) = 0;
};

#endif // CHARACTER_H
