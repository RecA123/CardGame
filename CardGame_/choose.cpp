#include "choose.h"
#include "ui_choose.h"
#include<QPushButton>
#include<QPainter>
#include<QPixmap>
#include<QPicture>
#include<QLabel>
#include "character.h"
#include "battle1.h"

int chara1;
int chara2;
int chara3;

Choose::Choose(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Choose)
{
    ui->setupUi(this);
    label1 = new QLabel;
    label2 = new QLabel;
    label3 = new QLabel;
    label1->setParent(this);
    label1->setFixedSize(252,432);
    label1->move(20+50,30);
    label2->setParent(this);
    label2->setFixedSize(252,432);
    label2->move(20+50,442+30);
    label3->setParent(this);
    label3->setFixedSize(252,432);
    label3->move(292+50,216+30);

    setFixedSize(1942, 1092);
    setWindowTitle("选择角色");
    QPushButton *retr = new QPushButton(this);
    retr->setText("开始对局");
    retr->setFixedSize(200,80);
    retr->move(200,950);
    connect(retr,&QPushButton::clicked,this,&Choose::on_begin_clicked);

    QPushButton *diluc = new QPushButton(this);
    diluc->setFixedSize(150,50);
    diluc->move(750,500);
    diluc->setText("选择");
    connect(diluc,&QPushButton::clicked,this,&Choose::on_choose1_clicked);

    QPushButton *collei = new QPushButton(this);
    collei->setFixedSize(150,50);
    collei->move(750+262,500);
    collei->setText("选择");
    connect(collei,&QPushButton::clicked,this,&Choose::on_choose2_clicked);

    QPushButton *diona = new QPushButton(this);
    diona->setFixedSize(150,50);
    diona->move(750+262*2,500);
    diona->setText("选择");
    connect(diona,&QPushButton::clicked,this,&Choose::on_choose3_clicked);

    QPushButton *fischl = new QPushButton(this);
    fischl->setFixedSize(150,50);
    fischl->move(750+262*3,500);
    fischl->setText("选择");
    connect(fischl,&QPushButton::clicked,this,&Choose::on_choose4_clicked);

    QPushButton *kokomi = new QPushButton(this);
    kokomi->setFixedSize(150,50);
    kokomi->move(750,950);
    kokomi->setText("选择");
    connect(kokomi,&QPushButton::clicked,this,&Choose::on_choose5_clicked);

    QPushButton *xingqiu = new QPushButton(this);
    xingqiu->setFixedSize(150,50);
    xingqiu->move(750+262,950);
    xingqiu->setText("选择");
    connect(xingqiu,&QPushButton::clicked,this,&Choose::on_choose6_clicked);

    QPushButton *ningguang = new QPushButton(this);
    ningguang->setFixedSize(150,50);
    ningguang->move(750+262*2,950);
    ningguang->setText("选择");
    connect(ningguang,&QPushButton::clicked,this,&Choose::on_choose7_clicked);

    QPushButton *cangjing = new QPushButton(this);
    cangjing->setFixedSize(150,50);
    cangjing->move(750+262*3,950);
    cangjing->setText("选择");
    connect(cangjing,&QPushButton::clicked,this,&Choose::on_choose8_clicked);


}

void Choose::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap background2;
    background2.load(":/new/character/C:/Users/33965/Desktop/resource/background2.png");
    painter.drawPixmap(0,0,1942,1092,background2);
    QPixmap diluc;
    diluc.load(":/new/character/C:/Users/33965/Desktop/resource/character/Diluc.jpg");
    painter.drawPixmap(700,100,252,432,diluc);
    QPixmap Collei;
    Collei.load(":/new/character/C:/Users/33965/Desktop/resource/character/Collei.webp");
    painter.drawPixmap(700+(10+252)*1,100,252,432,Collei);
    QPixmap diona;
    diona.load(":/new/character/C:/Users/33965/Desktop/resource/character/Diona.jpg");
    painter.drawPixmap(700+(10+252)*2,100,252,432,diona);
    QPixmap fischl;
    fischl.load(":/new/character/C:/Users/33965/Desktop/resource/character/Fischl.jpg");
    painter.drawPixmap(700+(10+252)*3,100,252,432,fischl);
    QPixmap kokomi;
    kokomi.load(":/new/character/C:/Users/33965/Desktop/resource/character/Kokomi.jpg");
    painter.drawPixmap(700,550,252,432,kokomi);
    QPixmap xingqiu;
    xingqiu.load(":/new/character/C:/Users/33965/Desktop/resource/character/Xingqiu.webp");
    painter.drawPixmap(700+(10+252)*1,550,252,432,xingqiu);
    QPixmap ningguang;
    ningguang.load(":/new/character/C:/Users/33965/Desktop/resource/character/Ningguang.jpg");
    painter.drawPixmap(700+(10+252)*2,550,252,432,ningguang);
    QPixmap cangjing;
    cangjing.load(":/new/character/C:/Users/33965/Desktop/resource/character/cangjing.jpg");
    painter.drawPixmap(700+(10+252)*3,550,252,432,cangjing);
}

void Choose::on_begin_clicked()
{
    battle1 *w = new battle1();
    this->close();
    w->show();
}

void Choose::on_choose1_clicked()
{
    QPixmap diluc;
    diluc.load(":/new/character/C:/Users/33965/Desktop/resource/character/Diluc.jpg");
    if(label1->pixmap()!=nullptr && !label1->pixmap()->isNull())
    {
        if(label2->pixmap()!=nullptr && !label2->pixmap()->isNull())
        {
            if(label3->pixmap()!=nullptr && !label3->pixmap()->isNull()){
                return;
            }else{
                label3->setPixmap(diluc);
                label3->setScaledContents(true);
                chara3 = 1;
            }
        }else{
            label2->setPixmap(diluc);
            label2->setScaledContents(true);
            chara2 = 1;
        }
    }else{
        label1->setPixmap(diluc);
        label1->setScaledContents(true);
        chara1 = 1;
    }

    return;
}
void Choose::on_choose2_clicked()
{
    QPixmap Collei;
    Collei.load(":/new/character/C:/Users/33965/Desktop/resource/character/Collei.webp");
    if(label1->pixmap()!=nullptr && !label1->pixmap()->isNull())
    {
        if(label2->pixmap()!=nullptr && !label2->pixmap()->isNull())
        {
            if(label3->pixmap()!=nullptr && !label3->pixmap()->isNull()){
                return;
            }else{
                label3->setPixmap(Collei);
                label3->setScaledContents(true);
                chara3 = 2;
            }
        }else{
            label2->setPixmap(Collei);
            label2->setScaledContents(true);
            chara2 = 2;
        }
    }else{
        label1->setPixmap(Collei);
        label1->setScaledContents(true);
        chara1 = 2;
    }

    return;
}
void Choose::on_choose3_clicked()
{
    QPixmap diona;
    diona.load(":/new/character/C:/Users/33965/Desktop/resource/character/Diona.jpg");
    if(label1->pixmap()!=nullptr && !label1->pixmap()->isNull())
    {
        if(label2->pixmap()!=nullptr && !label2->pixmap()->isNull())
        {
            if(label3->pixmap()!=nullptr && !label3->pixmap()->isNull()){
                return;
            }else{
                label3->setPixmap(diona);
                label3->setScaledContents(true);
                chara3 = 3;
            }
        }else{
            label2->setPixmap(diona);
            label2->setScaledContents(true);
            chara2 = 3;
        }
    }else{
        label1->setPixmap(diona);
        label1->setScaledContents(true);
        chara1 = 3;
    }

    return;
}
void Choose::on_choose4_clicked()
{
    QPixmap fischl;
    fischl.load(":/new/character/C:/Users/33965/Desktop/resource/character/Fischl.jpg");
    if(label1->pixmap()!=nullptr && !label1->pixmap()->isNull())
    {
        if(label2->pixmap()!=nullptr && !label2->pixmap()->isNull())
        {
            if(label3->pixmap()!=nullptr && !label3->pixmap()->isNull()){
                return;
            }else{
                label3->setPixmap(fischl);
                label3->setScaledContents(true);
                chara3 = 4;
            }
        }else{
            label2->setPixmap(fischl);
            label2->setScaledContents(true);
            chara2 = 4;
        }
    }else{
        label1->setPixmap(fischl);
        label1->setScaledContents(true);
        chara1 = 4;
    }

    return;
}
void Choose::on_choose5_clicked()
{
    QPixmap kokomi;
    kokomi.load(":/new/character/C:/Users/33965/Desktop/resource/character/Kokomi.jpg");
    if(label1->pixmap()!=nullptr && !label1->pixmap()->isNull())
    {
        if(label2->pixmap()!=nullptr && !label2->pixmap()->isNull())
        {
            if(label3->pixmap()!=nullptr && !label3->pixmap()->isNull()){
                return;
            }else{
                label3->setPixmap(kokomi);
                label3->setScaledContents(true);
                chara3 = 5;
            }
        }else{
            label2->setPixmap(kokomi);
            label2->setScaledContents(true);
            chara2 = 5;
        }
    }else{
        label1->setPixmap(kokomi);
        label1->setScaledContents(true);
        chara1 = 5;
    }

    return;
}
void Choose::on_choose6_clicked()
{
    QPixmap xingqiu;
    xingqiu.load(":/new/character/C:/Users/33965/Desktop/resource/character/Xingqiu.webp");
    if(label1->pixmap()!=nullptr && !label1->pixmap()->isNull())
    {
        if(label2->pixmap()!=nullptr && !label2->pixmap()->isNull())
        {
            if(label3->pixmap()!=nullptr && !label3->pixmap()->isNull()){
                return;
            }else{
                label3->setPixmap(xingqiu);
                label3->setScaledContents(true);
                chara3 = 6;
            }
        }else{
            label2->setPixmap(xingqiu);
            label2->setScaledContents(true);
            chara2 = 6;
        }
    }else{
        label1->setPixmap(xingqiu);
        label1->setScaledContents(true);
        chara1 = 6;
    }

    return;
}
void Choose::on_choose7_clicked()
{
    QPixmap ningguang;
    ningguang.load(":/new/character/C:/Users/33965/Desktop/resource/character/Ningguang.jpg");
    if(label1->pixmap()!=nullptr && !label1->pixmap()->isNull())
    {
        if(label2->pixmap()!=nullptr && !label2->pixmap()->isNull())
        {
            if(label3->pixmap()!=nullptr && !label3->pixmap()->isNull()){
                return;
            }else{
                label3->setPixmap(ningguang);
                label3->setScaledContents(true);
                chara3 = 7;
            }
        }else{
            label2->setPixmap(ningguang);
            label2->setScaledContents(true);
            chara2 = 7;
        }
    }else{
        label1->setPixmap(ningguang);
        label1->setScaledContents(true);
        chara1 = 7;
    }

    return;
}
void Choose::on_choose8_clicked()
{
    QPixmap cangjing;
    cangjing.load(":/new/character/C:/Users/33965/Desktop/resource/character/cangjing.jpg");
    if(label1->pixmap()!=nullptr && !label1->pixmap()->isNull())
    {
        if(label2->pixmap()!=nullptr && !label2->pixmap()->isNull())
        {
            if(label3->pixmap()!=nullptr && !label3->pixmap()->isNull()){
                return;
            }else{
                label3->setPixmap(cangjing);
                label3->setScaledContents(true);
            }
        }else{
            label2->setPixmap(cangjing);
            label2->setScaledContents(true);
        }
    }else{
        label1->setPixmap(cangjing);
        label1->setScaledContents(true);
    }

    return;
}

Choose::~Choose()
{
    delete ui;
}
