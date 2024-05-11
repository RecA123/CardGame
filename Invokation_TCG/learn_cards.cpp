#include "learn_cards.h"
#include <mypushbutton.h>
#include <QTimer>
#include <QLabel>
Learn_cards::Learn_cards(QWidget *parent) : QWidget(parent)
{
    QPixmap back;
    back.load(":/new/C:/Users/33965/Desktop/resource/background.jpg");
    this->setFixedSize(back.width()*1.5, back.height()*1.5);
    this->setWindowIcon(QPixmap(":/new/C:/Users/33965/Desktop/resource/icon.webp"));
    QPixmap diluc_skill;
    diluc_skill.load(":/new/C:/Users/33965/Desktop/resource/diluc_skill.png");
    QPixmap fischl_skill;
    fischl_skill.load(":/new/C:/Users/33965/Desktop/resource/fischl_skill.png");
    QPixmap jean_skill;
    jean_skill.load(":/new/C:/Users/33965/Desktop/resource/jean_skill.png");
    QPixmap diona_skill;
    diona_skill.load(":/new/C:/Users/33965/Desktop/resource/diona_skill.png");
    QLabel *skil_label = new QLabel(this);
    skil_label->move(120,20);
    MyPushButton *backward = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/back.png");
    backward->setParent(this);
    backward->move(150,1000);
    connect(backward, &QPushButton::clicked, this, [=](){

    });

    MyPushButton *diluc = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Diluc.png");
    diluc->setParent(this);
    diluc->move(800,100);
    connect(diluc, &QPushButton::clicked, this, [=](){
       diluc->zoom1();
       diluc->zoom2();
       QTimer::singleShot(500, this, [=](){
            skil_label->setPixmap(diluc_skill);
            skil_label->setFixedSize(400,950);
            skil_label->setScaledContents(true);
       });

    });

    MyPushButton *fischl =  new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Fischl.png");
    fischl->setParent(this);
    fischl->move(1150,100);
    connect(fischl, &QPushButton::clicked, this, [=](){
       fischl->zoom1();
       fischl->zoom2();
       QTimer::singleShot(500, this, [=](){
           skil_label->setPixmap(fischl_skill);
           skil_label->setFixedSize(400,950);
           skil_label->setScaledContents(true);
       });

    });

    MyPushButton *diona = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Diona.png");
    diona->setParent(this);
    diona->move(1500,100);
    connect(diona, &QPushButton::clicked, this, [=](){
       diona->zoom1();
       diona->zoom2();
       QTimer::singleShot(500, this, [=](){
           skil_label->setPixmap(diona_skill);
           skil_label->setFixedSize(400,950);
           skil_label->setScaledContents(true);
       });

    });

    MyPushButton *jean = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Jean.png") ;
    jean->setParent(this);
    jean->move(800,580);
    connect(jean, &QPushButton::clicked, this, [=](){
       jean->zoom1();
       jean->zoom2();
       QTimer::singleShot(500, this, [=](){
           skil_label->setPixmap(jean_skill);
           skil_label->setFixedSize(400,950);
           skil_label->setScaledContents(true);
       });
    });

    MyPushButton *kokomi = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/kokomi.png");
    kokomi->setParent(this);
    kokomi->move(1150, 580);
    connect(kokomi, &QPushButton::clicked, this, [=](){
       kokomi->zoom1();
       kokomi->zoom2();

    });

    MyPushButton *ningguang = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/ningguang.png");
    ningguang->setParent(this);
    ningguang->move(1500,580);
    connect(ningguang, &QPushButton::clicked, this, [=](){
       ningguang->zoom1();
       ningguang->zoom2();

    });

}

void Learn_cards::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pixmap;
    pixmap.load(":/new/C:/Users/33965/Desktop/resource/background2.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
}
