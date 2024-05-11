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
    int touzi[8];
    QLabel label[8];
    int big_round;
    int small_round;
    Enemy *enemy;
    QPixmap fire;
    QPixmap water;
    QPixmap lightning;
    QPixmap ice;
    QPixmap grass;

    QLabel *e_hplable;
    QLabel *e_is_e;
    QLabel *p1_hp_label;
    QLabel *p1_energy_label;
    QLabel *p2_hp_label;
    QLabel *p2_energy_label;
    QLabel *p3_hp_label;
    QLabel *p3_energy_label;

    QLabel *e_state;
    QLabel *p1_state;
    QLabel *p2_state;
    QLabel *p3_state;

    QLabel *fischl_s;
    QLabel *diona_s;
    QLabel *jean_s;
    QLabel *kokomi_s;

    QPixmap aozi;
    int aozi_round = 0;
    QPixmap jiuwu;
    int jiuwu_round = 0;
    QPixmap fengchang;
    int fengchang_round = 0;
    QPixmap shuimu;
    int shuimu_round = 0;

    QPushButton *xiaoPi;
    QPushButton *tudou;

    Character *is_char;
    MyPushButton *is_charbtn;
    Diluc *diluc;
    Character *p1;
    Character *p2;
    Character *p3;
    MyPushButton *char1;
    MyPushButton *char2;
    MyPushButton *char3;
    MyPushButton *change_round;
    int character1;
    int character2;
    int character3;
    bool win = 0;
    QTextEdit *text;
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
