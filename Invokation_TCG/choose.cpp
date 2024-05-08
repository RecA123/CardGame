#include "choose.h"
#include <QPixmap>
#include <QIcon>
#include <QTimer>
#include <mypushbutton.h>
#include <QLabel>
#include <battle.h>


choose::choose(QWidget *parent) : QWidget(parent)
{
    QPixmap back;
    back.load(":/new/C:/Users/33965/Desktop/resource/background.jpg");
    this->setFixedSize(back.width()*1.5, back.height()*1.5);
    this->setWindowIcon(QPixmap(":/new/C:/Users/33965/Desktop/resource/icon.webp"));

    QLabel *cha1 = new QLabel(this);
    QLabel *cha2 = new QLabel(this);
    QLabel *cha3 = new QLabel(this);
    cha1->setFixedSize(210,360);
    cha2->setFixedSize(210,360);
    cha3->setFixedSize(210,360);
    cha1->move(70,60);
    cha2->move(70,500);
    cha3->move(350,300);
    MyPushButton *begin = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/kaishi.png");
    begin->setParent(this);
    begin->move(150,950);
    begin->setEnabled(false);

    MyPushButton *diluc = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Diluc.png");
    diluc->setParent(this);
    diluc->move(800,100);
    connect(diluc, &QPushButton::clicked, this, [=](){
       diluc->zoom1();
       diluc->zoom2();
       QTimer::singleShot(500, this, [=](){
           QPixmap pix;
           pix.load(":/new/C:/Users/33965/Desktop/resource/Diluc.png");
           if(cha1->pixmap()!=nullptr && !cha1->pixmap()->isNull())
           {
               if(cha2->pixmap()!=nullptr && !cha2->pixmap()->isNull())
               {
                   if(cha3->pixmap()!=nullptr && !cha3->pixmap()->isNull()){
                       return;
                   }else{
                       cha3->setPixmap(pix);
                       cha3->setScaledContents(true);
                       diluc->setEnabled(false);
                       updateC3(1);
                       begin->setEnabled(true);
                   }
               }else{
                   cha2->setPixmap(pix);
                   cha2->setScaledContents(true);
                   diluc->setEnabled(false);
                   updateC2(1);
               }
           }else{
               cha1->setPixmap(pix);
               cha1->setScaledContents(true);
               diluc->setEnabled(false);
               updateC1(1);
           }
       });
    });

    MyPushButton *fischl =  new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Fischl.png");
    fischl->setParent(this);
    fischl->move(1150,100);
    connect(fischl, &QPushButton::clicked, this, [=](){
       fischl->zoom1();
       fischl->zoom2();
       QTimer::singleShot(500, this, [=](){
           QPixmap pix;
           pix.load(":/new/C:/Users/33965/Desktop/resource/Fischl.png");
           if(cha1->pixmap()!=nullptr && !cha1->pixmap()->isNull())
           {
               if(cha2->pixmap()!=nullptr && !cha2->pixmap()->isNull())
               {
                   if(cha3->pixmap()!=nullptr && !cha3->pixmap()->isNull()){
                       return;
                   }else{
                       cha3->setPixmap(pix);
                       cha3->setScaledContents(true);
                       fischl->setEnabled(false);
                       updateC3(2);
                       begin->setEnabled(true);
                   }
               }else{
                   cha2->setPixmap(pix);
                   cha2->setScaledContents(true);
                   fischl->setEnabled(false);
                   updateC2(2);
               }
           }else{
               cha1->setPixmap(pix);
               cha1->setScaledContents(true);
               fischl->setEnabled(false);
               updateC1(2);
           }
       });
    });

    MyPushButton *diona = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Diona.png");
    diona->setParent(this);
    diona->move(1500,100);
    connect(diona, &QPushButton::clicked, this, [=](){
       diona->zoom1();
       diona->zoom2();
       QTimer::singleShot(500, this, [=](){
           QPixmap pix;
           pix.load(":/new/C:/Users/33965/Desktop/resource/Diona.png");
           if(cha1->pixmap()!=nullptr && !cha1->pixmap()->isNull())
           {
               if(cha2->pixmap()!=nullptr && !cha2->pixmap()->isNull())
               {
                   if(cha3->pixmap()!=nullptr && !cha3->pixmap()->isNull()){
                       return;
                   }else{
                       cha3->setPixmap(pix);
                       cha3->setScaledContents(true);
                       diona->setEnabled(false);
                       updateC3(3);
                       begin->setEnabled(true);
                   }
               }else{
                   cha2->setPixmap(pix);
                   cha2->setScaledContents(true);
                   diona->setEnabled(false);
                   updateC2(3);
               }
           }else{
               cha1->setPixmap(pix);
               cha1->setScaledContents(true);
               diona->setEnabled(false);
               updateC1(3);
           }
       });
    });

    MyPushButton *jean = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Jean.png") ;
    jean->setParent(this);
    jean->move(800,580);
    connect(jean, &QPushButton::clicked, this, [=](){
       jean->zoom1();
       jean->zoom2();
       QTimer::singleShot(500, this, [=](){
           QPixmap pix;
           pix.load(":/new/C:/Users/33965/Desktop/resource/Jean.png");
           if(cha1->pixmap()!=nullptr && !cha1->pixmap()->isNull())
           {
               if(cha2->pixmap()!=nullptr && !cha2->pixmap()->isNull())
               {
                   if(cha3->pixmap()!=nullptr && !cha3->pixmap()->isNull()){
                       return;
                   }else{
                       cha3->setPixmap(pix);
                       cha3->setScaledContents(true);
                       jean->setEnabled(false);
                       updateC3(4);
                       begin->setEnabled(true);
                   }
               }else{
                   cha2->setPixmap(pix);
                   cha2->setScaledContents(true);
                   jean->setEnabled(false);
                   updateC2(4);
               }
           }else{
               cha1->setPixmap(pix);
               cha1->setScaledContents(true);
               jean->setEnabled(false);
               updateC1(4);
           }
       });
    });

    MyPushButton *kokomi = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/kokomi.png");
    kokomi->setParent(this);
    kokomi->move(1150, 580);
    connect(kokomi, &QPushButton::clicked, this, [=](){
       kokomi->zoom1();
       kokomi->zoom2();
       QTimer::singleShot(500, this, [=](){
           QPixmap pix;
           pix.load(":/new/C:/Users/33965/Desktop/resource/kokomi.png");
           if(cha1->pixmap()!=nullptr && !cha1->pixmap()->isNull())
           {
               if(cha2->pixmap()!=nullptr && !cha2->pixmap()->isNull())
               {
                   if(cha3->pixmap()!=nullptr && !cha3->pixmap()->isNull()){
                       return;
                   }else{
                       cha3->setPixmap(pix);
                       cha3->setScaledContents(true);
                       kokomi->setEnabled(false);
                       updateC3(5);
                       begin->setEnabled(true);
                   }
               }else{
                   cha2->setPixmap(pix);
                   cha2->setScaledContents(true);
                   kokomi->setEnabled(false);
                   updateC2(5);
               }
           }else{
               cha1->setPixmap(pix);
               cha1->setScaledContents(true);
               kokomi->setEnabled(false);
               updateC1(5);
           }
       });
    });

    MyPushButton *ningguang = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/ningguang.png");
    ningguang->setParent(this);
    ningguang->move(1500,580);
    connect(ningguang, &QPushButton::clicked, this, [=](){
       ningguang->zoom1();
       ningguang->zoom2();
       QTimer::singleShot(500, this, [=](){
           QPixmap pix;
           pix.load(":/new/C:/Users/33965/Desktop/resource/ningguang.png");
           if(cha1->pixmap()!=nullptr && !cha1->pixmap()->isNull())
           {
               if(cha2->pixmap()!=nullptr && !cha2->pixmap()->isNull())
               {
                   if(cha3->pixmap()!=nullptr && !cha3->pixmap()->isNull()){
                       return;
                   }else{
                       cha3->setPixmap(pix);
                       cha3->setScaledContents(true);
                       ningguang->setEnabled(false);
                       updateC3(6);
                       begin->setEnabled(true);
                   }
               }else{
                   cha2->setPixmap(pix);
                   cha2->setScaledContents(true);
                   ningguang->setEnabled(false);
                   updateC2(6);
               }
           }else{
               cha1->setPixmap(pix);
               cha1->setScaledContents(true);
               ningguang->setEnabled(false);
               updateC1(6);
           }
       });
    });



    connect(begin, &QPushButton::clicked, this, [=](){
        //弹起特效
        begin->zoom1();
        begin->zoom2();
        battleScence = new battle(getc1(), getc2(), getc3());
        //battleScence->setCharacter1(c1);
        //battleScence->setCharacter2(c2);
        //battleScence->setCharacter3(c3);
        //进入选择界面
        QTimer::singleShot(500,this,[=](){
            this->hide();
            battleScence->show();
        });
    });
}

void choose::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pixmap;
    pixmap.load(":/new/C:/Users/33965/Desktop/resource/background2.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
}

void choose::updateC1(int x)
{
    c1 = x;
}
void choose::updateC2(int x)
{
    c2 = x;
}
void choose::updateC3(int x)
{
    c3 = x;
}
int choose::getc1()
{
    return c1;
}
int choose::getc2()
{
    return c2;
}
int choose::getc3()
{
    return c3;
}
