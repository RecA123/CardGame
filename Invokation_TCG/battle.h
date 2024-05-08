#ifndef BATTLE_H
#define BATTLE_H

#include <QWidget>
#include <QWidget>
#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include <mypushbutton.h>
#include <enemy.h>
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
class battle : public QWidget
{
    Q_OBJECT
private:
    Enemy *enemy;
    QPixmap fire;
    QLabel *e_hplable;
    QLabel *e_is_e;
    Character *is_char;
    MyPushButton *is_charbtn;
    Diluc *diluc;
    Character *p1;
    Character *p2;
    Character *p3;
    MyPushButton *char1;
    MyPushButton *char2;
    MyPushButton *char3;
    int character1;
    int character2;
    int character3;
    QTextEdit *text;
public:
    void setCharacter1(int x);
    void setCharacter2(int y);
    void setCharacter3(int z);
    explicit battle(int c1, int c2, int c3, QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    void initial();
    void changeP1();
    void changeP2();
    void changeP3();
public slots:
    void normalAttack_clicked();
    void elementalSkill_clicked();
    void elementalBurst_clicked();

signals:

};

#endif // BATTLE_H
