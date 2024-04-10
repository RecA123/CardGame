#include "learn_cards.h"
#include "ui_learn_cards.h"
#include <QPushButton>
#include <QPainter>
#include <QPixmap>
Learn_cards::Learn_cards(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Learn_cards)
{
    ui->setupUi(this);
    setFixedSize(1942, 1092);
    QPushButton *retr = new QPushButton(this);
    retr->setText("返回主界面");
    connect(retr, &QPushButton::clicked, this, &Learn_cards::on_return_clicked);

    QPushButton *diluc = new QPushButton(this);
    diluc->setFixedSize(150,50);
    diluc->move(750,500);
    diluc->setText("查看");
    QPushButton *collei = new QPushButton(this);
    collei->setFixedSize(150,50);
    collei->move(750+262,500);
    collei->setText("查看");
    QPushButton *diona = new QPushButton(this);
    diona->setFixedSize(150,50);
    diona->move(750+262*2,500);
    diona->setText("查看");
    QPushButton *fischl = new QPushButton(this);
    fischl->setFixedSize(150,50);
    fischl->move(750+262*3,500);
    fischl->setText("查看");
    QPushButton *kokomi = new QPushButton(this);
    kokomi->setFixedSize(150,50);
    kokomi->move(750,950);
    kokomi->setText("查看");
    QPushButton *xingqiu = new QPushButton(this);
    xingqiu->setFixedSize(150,50);
    xingqiu->move(750+262,950);
    xingqiu->setText("查看");
    QPushButton *ningguang = new QPushButton(this);
    ningguang->setFixedSize(150,50);
    ningguang->move(750+262*2,950);
    ningguang->setText("查看");
    QPushButton *cangjing = new QPushButton(this);
    cangjing->setFixedSize(150,50);
    cangjing->move(750+262*3,950);
    cangjing->setText("查看");
}

Learn_cards::~Learn_cards()
{
    delete ui;
}

void Learn_cards::on_return_clicked(){
    emit sendsignal();
    this->close();
}

void Learn_cards::paintEvent(QPaintEvent *)
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
