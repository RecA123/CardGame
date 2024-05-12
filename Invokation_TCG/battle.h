#ifndef BATTLE_H
#define BATTLE_H

#include <QWidget>
#include <QWidget>
#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include <mypushbutton.h>
#include <character.h>
#include <QTextEdit>
#include <QPixmap>
#include <QLabel>
#include <diluc.h>
#include <diona.h>
#include <fischl.h>
#include <jean.h>
#include <kokomi.h>
#include <ningguang.h>
#include <win.h>
#include <lose.h>
#include <QSoundEffect>
class battle : public QWidget
{
    Q_OBJECT
private:
    //骰子数组
    int touzi[8];
    //骰子图标
    QLabel label[8];

    //回合数
    int big_round;
    int small_round;

    //敌人
    Enemy *enemy;

    //元素图片
    QPixmap fire;
    QPixmap water;
    QPixmap lightning;
    QPixmap ice;
    QPixmap grass;

    //血量栏、能量栏
    QLabel *e_hplable;
    QLabel *e_is_e;
    QLabel *p1_hp_label;
    QLabel *p1_energy_label;
    QLabel *p2_hp_label;
    QLabel *p2_energy_label;
    QLabel *p3_hp_label;
    QLabel *p3_energy_label;

    //角色及敌人状态标签
    QLabel *e_state;
    QLabel *p1_state;
    QLabel *p2_state;
    QLabel *p3_state;

    //召唤物标签
    QLabel *fischl_s;
    QLabel *diona_s;
    QLabel *jean_s;
    QLabel *kokomi_s;

    //召唤物及冷却回合
    QPixmap aozi;
    int aozi_round = 0;
    QPixmap jiuwu;
    int jiuwu_round = 0;
    QPixmap fengchang;
    int fengchang_round = 0;
    QPixmap shuimu;
    int shuimu_round = 0;

    //功能按钮
    QPushButton *xiaoPi;
    QPushButton *tudou;

    //角色实现
    int character1;
    int character2;
    int character3;
    Character *is_char;//当前出战角色
    MyPushButton *is_charbtn;
    Character *p1;
    Character *p2;
    Character *p3;
    MyPushButton *char1;
    MyPushButton *char2;
    MyPushButton *char3;

    //回合结束按钮
    MyPushButton *change_round;

    //信息栏
    QTextEdit *text;

    //子界面实现
    Win *winScence;
    Lose *loseScence;
public:
    explicit battle(int c1, int c2, int c3, QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    //初始化
    void initial();
    //切换角色
    void changeP1();
    void changeP2();
    void changeP3();
    void is_dead();
    //判断胜利条件
    bool is_fail();
    bool is_win();
    //更新敌人头上元素
    void updateE();
    //更新血量和充能；
    void updateNum();
    //掷色子
    void getTouzi();
    int otherTouzi();
    //结束回合
    void change_clicked();

public slots:
    void normalAttack_clicked();
    void elementalSkill_clicked();
    void elementalBurst_clicked();
    void xiaoPi_clicked();
    void tudou_clicked();
    //void end_round();

signals:

};

#endif // BATTLE_H
