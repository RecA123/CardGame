#include "page.h"
#include "ui_page.h"
#include<QPainter>
#include<QPixmap>
#include<QPushButton>
#include"learn_cards.h"
#include"learn_rules.h"
#include"choose.h"
page::page(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //配置场景
    //设置固定窗口大小
    setFixedSize(1942, 1092);
    //设置图标
    //设置标题
    setWindowTitle("七圣召唤");
    QPixmap pix(300,300);
    QPainter painter(&pix);

    //退出按钮实现

    begin.setText("开始对局");
    begin.setParent(this);
    begin.setFixedSize(200, 75);
    begin.move(950, 700);
    card.setText("卡牌图鉴");
    card.setParent(this);
    card.setFixedSize(200, 75);
    card.move(950, 620);
    rule.setText("了解规则");
    rule.setParent(this);
    rule.setFixedSize(200, 75);
    rule.move(950, 540);

    connect(&card,&QPushButton::clicked,this,&page::on_cards_clicked);
    connect(&rule,&QPushButton::clicked,this,&page::on_rules_clicked);
    connect(&begin,&QPushButton::clicked,this,&page::on_begin_clicked);
}

void page::paintEvent(QPaintEvent *)
{
    //实例化画家对象 this指定的是绘图设备
    QPainter painter(this);
    QPixmap pix;
    pix.load("C:/Users/33965/Desktop/resource/background.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
void page::on_cards_clicked()
{
    this->close();
    Learn_cards *w=new Learn_cards();
    connect(w, SIGNAL(sendsignal()), this, SLOT(reshow()));
    w->show();
}
void page::on_rules_clicked()
{
    this->close();
    learn_rules *w=new learn_rules();
    connect(w, SIGNAL(sendsignal()), this, SLOT(reshow()));
    w->show();
}
void page::on_begin_clicked()
{
    this->close();
    Choose *w=new Choose();
    w->show();
}
void page::reshow()
{
    this->show();
}
page::~page()
{
    delete ui;
}

