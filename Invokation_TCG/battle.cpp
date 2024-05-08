#include "battle.h"

#include <QPixmap>
#include <QString>
#include <QIcon>
#include <QTimer>
#include <mypushbutton.h>
#include <enemy.h>
#include <QDebug>
#include <QTextEdit>
//火1 水2 雷3 冰4 草5 岩6 风7 物理0
//单手剑1 双手剑2 长枪3 法器4 弓箭5
void battle::setCharacter1(int x)
{
    character1 = x;
}

void battle::setCharacter2(int y)
{
    character2 = y;
}

void battle::setCharacter3(int z)
{
    character3 = z;
}


battle::battle(int c1, int c2, int c3, QWidget *parent) : QWidget(parent)
{
    character1 = c1;
    character2 = c2;
    character3 = c3;
    qDebug()<<character1<<character2<<character3;
    QPixmap back;
    back.load(":/new/C:/Users/33965/Desktop/resource/background.jpg");
    this->setFixedSize(back.width()*1.5, back.height()*1.5);
    this->setWindowIcon(QPixmap(":/new/C:/Users/33965/Desktop/resource/icon.webp"));

    fire.load(":/new/C:/Users/33965/Desktop/resource/fire.png");
    text = new QTextEdit;
    text->setParent(this);
    text->setFixedSize(650,600);
    text->move(this->width()*0.5+250, 50);


    enemy = new Enemy(30);
    e_is_e = new QLabel(this);
    e_is_e->setFixedSize(80,90);
    e_is_e->move(this->width()*0.5-40, 50);

    e_hplable = new QLabel;
    e_hplable->setParent(this);
    e_hplable->setFixedSize(20,20);
    e_hplable->move(this->width()*0.5-145, 50);
    e_hplable->setText(QString::number(enemy->gethp()));

    initial();
    changeP1();

    MyPushButton *normalatk = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/attack.png");
    normalatk->setParent(this);
    normalatk->move(1500,950);
    MyPushButton *elementalskl = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/skill.png");
    elementalskl->setParent(this);
    elementalskl->move(1650,950);
    MyPushButton *elementalbrst = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/burst.png");
    elementalbrst->setParent(this);
    elementalbrst->move(1800,950);


    connect(char1, &QPushButton::clicked, this, &battle::changeP1);
    connect(char2, &QPushButton::clicked, this, &battle::changeP2);
    connect(char3, &QPushButton::clicked, this, &battle::changeP3);
    connect(normalatk, &QPushButton::clicked, this, [=](){
        normalatk->zoom1();
        is_charbtn->zoom1();
        normalatk->zoom2();
        is_charbtn->zoom2();
        QTimer::singleShot(500, this, [=](){
             normalAttack_clicked();
        });
    });

    connect(elementalskl, &QPushButton::clicked, this, [=](){
        elementalskl->zoom1();
        is_charbtn->zoom1();
        elementalskl->zoom2();
        is_charbtn->zoom2();
        QTimer::singleShot(500, this, [=](){
             elementalSkill_clicked();
        });
    });

    connect(elementalbrst, &QPushButton::clicked, this, [=](){
        elementalbrst->zoom1();
        is_charbtn->zoom1();
        elementalbrst->zoom2();
        is_charbtn->zoom2();
        QTimer::singleShot(500, this, [=](){
             elementalBurst_clicked();
        });
    });

}

void battle::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pixmap;
    pixmap.load(":/new/C:/Users/33965/Desktop/resource/background2.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
    QPixmap enemy;
    enemy.load(":/new/C:/Users/33965/Desktop/resource/yankui.webp");
    painter.drawPixmap(this->width()*0.5-105, 50, 210, 360, enemy);
}

void battle::normalAttack_clicked()
{
    is_char->normalAttack(enemy);
    text->append(is_char->name+"攻击了丘丘王，丘丘王血量为"+QString::number(enemy->gethp()));
    e_hplable->setText(QString::number(enemy->gethp()));
}

void battle::elementalSkill_clicked()
{
    is_char->elementalSkill(enemy);
    text->append(is_char->name+"攻击了丘丘王，丘丘王血量为"+QString::number(enemy->gethp()));
    e_hplable->setText(QString::number(enemy->gethp()));

    if(enemy->getE()==1){
        fire.scaled(e_is_e->size(), Qt::KeepAspectRatio);
        e_is_e->setScaledContents(true);
        e_is_e->setPixmap(fire);
    }
}

void battle::elementalBurst_clicked()
{
    is_char->elementalBurst(enemy);
    text->append(is_char->name+"攻击了丘丘王，丘丘王血量为"+QString::number(enemy->gethp()));
    e_hplable->setText(QString::number(enemy->gethp()));

    if(enemy->getE()==1){
        fire.scaled(e_is_e->size(), Qt::KeepAspectRatio);
        e_is_e->setScaledContents(true);
        e_is_e->setPixmap(fire);
    }
}

void battle::initial()
{
    if(character1 == 1){
        p1 = new Diluc(10, 1, 0, 2, 0);
        char1 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Diluc.png");
    }else if(character1 == 2){
        p1 = new Fischl(10, 3, 0, 5, 0);
        char1 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Fischl.png");
    }else if(character1 == 3){
        p1 = new Diona(10, 4, 0, 5, 0);
        char1 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Diona.png");
    }else if(character1 == 4){
        p1 = new Jean(10, 7, 0, 1, 0);
        char1 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Jean.png");
    }else if(character1 == 5){
        p1 = new Kokomi(10, 2, 0, 4, 0);
        char1 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/kokomi.png");
    }else if(character1 == 6){
        p1 = new Diona(10, 6, 0, 4, 0);
        char1 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/ningguang.png");
    }
    char1->setParent(this);
    char1->move(this->width()*0.5-400,700);

    if(character2 == 1){
        p2 = new Diluc(10, 1, 0, 2, 0);
        char2 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Diluc.png");
    }else if(character2 == 2){
        p2 = new Fischl(10, 3, 0, 5, 0);
        char2 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Fischl.png");
    }else if(character2 == 3){
        p2 = new Diona(10, 4, 0, 5, 0);
        char2 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Diona.png");
    }else if(character2 == 4){
        p2 = new Jean(10, 7, 0, 1, 0);
        char2 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Jean.png");
    }else if(character2 == 5){
        p2 = new Kokomi(10, 2, 0, 4, 0);
        char2 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/kokomi.png");
    }else if(character2 == 6){
        p2 = new Diona(10, 6, 0, 4, 0);
        char2 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/ningguang.png");
    }
    char2->setParent(this);
    char2->move(this->width()*0.5-105,700);

    if(character3 == 1){
        p3 = new Diluc(10, 1, 0, 2, 0);
        char3= new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Diluc.png");
    }else if(character3 == 2){
        p3 = new Fischl(10, 3, 0, 5, 0);
        char3 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Fischl.png");
    }else if(character3 == 3){
        p3 = new Diona(10, 4, 0, 5, 0);
        char3 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Diona.png");
    }else if(character3 == 4){
        p3 = new Jean(10, 7, 0, 1, 0);
        char3 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Jean.png");
    }else if(character3 == 5){
        p3 = new Kokomi(10, 2, 0, 4, 0);
        char3 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/kokomi.png");
    }else if(character3 == 6){
        p3 = new Diona(10, 6, 0, 4, 0);
        char3 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/ningguang.png");
    }
    char3->setParent(this);
    char3->move(this->width()*0.5+200,700);
}

void battle::changeP1()
{
    char2->move(this->width()*0.5-105,700);
    char3->move(this->width()*0.5+200,700);
    char1->move(this->width()*0.5-400,650);
    is_char = p1;
    is_charbtn = char1;
}

void battle::changeP2()
{
    char1->move(this->width()*0.5-400,700);
    char3->move(this->width()*0.5+200,700);
    char2->move(this->width()*0.5-105,650);
    is_char = p2;
    is_charbtn = char2;
}

void battle::changeP3()
{
    char1->move(this->width()*0.5-400,700);
    char2->move(this->width()*0.5-105,700);
    char3->move(this->width()*0.5+200,650);
    is_char = p3;
    is_charbtn = char3;
}
