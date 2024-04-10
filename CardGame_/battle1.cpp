#include "battle1.h"
#include "ui_battle1.h"
#include <QPainter>
#include <QPixmap>
#include "character.h"
#include<QPushButton>
#include"character.h"
#include"enemy.h"
extern int chara1;
extern int chara2;
extern int chara3;

AbstractCharacter * is_character;
AbstractEnemy * is_enemy;
Diluc diluc;
battle1::battle1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::battle1)
{
    ui->setupUi(this);
    setFixedSize(1942, 1092);

    QPushButton *charac1 = new QPushButton(this);
    charac1->setFixedSize(150,50);
    charac1->setText("选择");
    charac1->move(635,1010);
    QPushButton *charac2 = new QPushButton(this);
    charac2->setFixedSize(150,50);
    charac2->setText("选择");
    charac2->move(885,1010);
    QPushButton *charac3 = new QPushButton(this);
    charac3->setFixedSize(150,50);
    charac3->setText("选择");
    charac3->move(1135,1010);
    connect(charac1, &QPushButton::clicked, this, &battle1::charac1_clicked);
    connect(charac2, &QPushButton::clicked, this, &battle1::charac2_clicked);
    connect(charac3, &QPushButton::clicked, this, &battle1::charac3_clicked);
    QPushButton *end = new QPushButton(this);
    end->setFixedSize(150,50);
    end->setText("结束回合");
    end->move(50,510);
    QPushButton *normal_Atk = new QPushButton(this);
    normal_Atk->setFixedSize(180,67);
    normal_Atk->setText("普通攻击");
    normal_Atk->move(1340,950);
    QPushButton *elemen_Skil = new QPushButton(this);
    elemen_Skil->setFixedSize(180,67);
    elemen_Skil->setText("元素战技");
    elemen_Skil->move(1530,950);
    QPushButton *elemen_Burst = new QPushButton(this);
    elemen_Burst->setFixedSize(180,67);
    elemen_Burst->setText("元素爆发");
    elemen_Burst->move(1720,950);
}

void battle1::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap background;
    background.load(":/new/character/C:/Users/33965/Desktop/resource/background2.png");
    painter.drawPixmap(0,0,1942,1092,background);
    QPixmap enemy1;
    enemy1.load(":/new/character/C:/Users/33965/Desktop/resource/enemy/BingDun.webp");
    painter.drawPixmap(600,50,210,360,enemy1);
    QPixmap enemy2;
    enemy2.load(":/new/character/C:/Users/33965/Desktop/resource/enemy/HuoFu.webp");
    painter.drawPixmap(850,50,210,360,enemy2);
    QPixmap enemy3;
    enemy3.load(":/new/character/C:/Users/33965/Desktop/resource/enemy/LeiFu.webp");
    painter.drawPixmap(1100,50,210,360,enemy3);
    if(chara1 == 1){
        QPixmap diluc;
        diluc.load(":/new/character/C:/Users/33965/Desktop/resource/character/Diluc.jpg");
        painter.drawPixmap(600,650,210,360,diluc);
    }else if(chara1 == 2){
        QPixmap Collei;
        Collei.load(":/new/character/C:/Users/33965/Desktop/resource/character/Collei.webp");
        painter.drawPixmap(600,650,210,360,Collei);
    }else if(chara1 == 3){
        QPixmap diona;
        diona.load(":/new/character/C:/Users/33965/Desktop/resource/character/Diona.jpg");
        painter.drawPixmap(600,650,210,360,diona);
    }else if(chara1 == 4){
        QPixmap fischl;
        fischl.load(":/new/character/C:/Users/33965/Desktop/resource/character/Fischl.jpg");
        painter.drawPixmap(600,650,210,360,fischl);
    }else if(chara1 == 5){
        QPixmap kokomi;
        kokomi.load(":/new/character/C:/Users/33965/Desktop/resource/character/Kokomi.jpg");
        painter.drawPixmap(600,650,210,360,kokomi);
    }else if(chara1 == 6){
        QPixmap xingqiu;
        xingqiu.load(":/new/character/C:/Users/33965/Desktop/resource/character/Xingqiu.webp");
        painter.drawPixmap(600,650,210,360,xingqiu);
    }else if(chara1 == 7){
        QPixmap ningguang;
        ningguang.load(":/new/character/C:/Users/33965/Desktop/resource/character/Ningguang.jpg");
        painter.drawPixmap(600,650,210,360,ningguang);
    }else{
        QPixmap cangjing;
        cangjing.load(":/new/character/C:/Users/33965/Desktop/resource/character/cangjing.jpg");
        painter.drawPixmap(600,650,210,360,cangjing);
    }


    if(chara2 == 1){
        QPixmap diluc;
        diluc.load(":/new/character/C:/Users/33965/Desktop/resource/character/Diluc.jpg");
        painter.drawPixmap(850,650,210,360,diluc);
    }else if(chara2 == 2){
        QPixmap Collei;
        Collei.load(":/new/character/C:/Users/33965/Desktop/resource/character/Collei.webp");
        painter.drawPixmap(850,650,210,360,Collei);
    }else if(chara2 == 3){
        QPixmap diona;
        diona.load(":/new/character/C:/Users/33965/Desktop/resource/character/Diona.jpg");
        painter.drawPixmap(850,650,210,360,diona);
    }else if(chara2 == 4){
        QPixmap fischl;
        fischl.load(":/new/character/C:/Users/33965/Desktop/resource/character/Fischl.jpg");
        painter.drawPixmap(850,650,210,360,fischl);
    }else if(chara2 == 5){
        QPixmap kokomi;
        kokomi.load(":/new/character/C:/Users/33965/Desktop/resource/character/Kokomi.jpg");
        painter.drawPixmap(850,650,210,360,kokomi);
    }else if(chara2 == 6){
        QPixmap xingqiu;
        xingqiu.load(":/new/character/C:/Users/33965/Desktop/resource/character/Xingqiu.webp");
        painter.drawPixmap(850,650,210,360,xingqiu);
    }else if(chara2 == 7){
        QPixmap ningguang;
        ningguang.load(":/new/character/C:/Users/33965/Desktop/resource/character/Ningguang.jpg");
        painter.drawPixmap(850,650,210,360,ningguang);
    }else{
        QPixmap cangjing;
        cangjing.load(":/new/character/C:/Users/33965/Desktop/resource/character/cangjing.jpg");
        painter.drawPixmap(850,650,210,360,cangjing);
    }

    if(chara3 == 1){
        QPixmap diluc;
        diluc.load(":/new/character/C:/Users/33965/Desktop/resource/character/Diluc.jpg");
        painter.drawPixmap(1100,650,210,360,diluc);
    }else if(chara3 == 2){
        QPixmap Collei;
        Collei.load(":/new/character/C:/Users/33965/Desktop/resource/character/Collei.webp");
        painter.drawPixmap(1100,650,210,360,Collei);
    }else if(chara3 == 3){
        QPixmap diona;
        diona.load(":/new/character/C:/Users/33965/Desktop/resource/character/Diona.jpg");
        painter.drawPixmap(1100,650,210,360,diona);
    }else if(chara3 == 4){
        QPixmap fischl;
        fischl.load(":/new/character/C:/Users/33965/Desktop/resource/character/Fischl.jpg");
        painter.drawPixmap(1100,650,210,360,fischl);
    }else if(chara3 == 5){
        QPixmap kokomi;
        kokomi.load(":/new/character/C:/Users/33965/Desktop/resource/character/Kokomi.jpg");
        painter.drawPixmap(1100,650,210,360,kokomi);
    }else if(chara3 == 6){
        QPixmap xingqiu;
        xingqiu.load(":/new/character/C:/Users/33965/Desktop/resource/character/Xingqiu.webp");
        painter.drawPixmap(1100,650,210,360,xingqiu);
    }else if(chara3 == 7){
        QPixmap ningguang;
        ningguang.load(":/new/character/C:/Users/33965/Desktop/resource/character/Ningguang.jpg");
        painter.drawPixmap(1100,650,210,360,ningguang);
    }else{
        QPixmap cangjing;
        cangjing.load(":/new/character/C:/Users/33965/Desktop/resource/character/cangjing.jpg");
        painter.drawPixmap(1150,600,252,432,cangjing);
    }
}

void battle1::charac1_clicked()
{
    if(chara1==1){
        is_character = &diluc;
    }else if(chara1 == 2){

    }else if(chara1 == 3){

    }else if(chara1 == 4){

    }else if(chara1 == 5){

    }else if(chara1 == 6){

    }else if(chara1 == 7){

    }else{

    }
}

void battle1::charac2_clicked()
{
    if(chara2==1){
        is_character = &diluc;
    }else if(chara2 == 2){

    }else if(chara2 == 3){

    }else if(chara2 == 4){

    }else if(chara2 == 5){

    }else if(chara2 == 6){

    }else if(chara2 == 7){

    }else{

    }
}

void battle1::charac3_clicked()
{
    if(chara3==1){
        is_character = &diluc;
    }else if(chara3 == 2){

    }else if(chara3 == 3){

    }else if(chara3 == 4){

    }else if(chara3 == 5){

    }else if(chara3 == 6){

    }else if(chara3 == 7){

    }else{

    }
}

void battle1::normal_Atk_clicked()
{

}

void battle1::elemen_Skil_clicked()
{

}

void battle1::elemen_Burst_clicked()
{

}

battle1::~battle1()
{
    delete ui;
}
