#include "login.h"
#include "ui_login.h"

#include "mypushbutton.h"
#include <QPixmap>
#include <QIcon>
#include <QTimer>
login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
    QIcon icon(":/new/C:/Users/33965/Desktop/resource/icon.webp");
    this->setWindowIcon(icon);
    QPixmap back;
    back.load(":/new/C:/Users/33965/Desktop/resource/background.jpg");
    this->setFixedSize(back.width()*1.5, back.height()*1.5);
    //this->setFixedSize()
    MyPushButton *begin = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/kaishi.png");
    begin->setParent(this);
    begin->move(this->width()*0.44, this->height()*0.5);
    chooseScene = new choose;
    connect(begin, &QPushButton::clicked, this, [=](){
        //弹起特效
        begin->zoom1();
        begin->zoom2();

        //进入选择界面
        QTimer::singleShot(500,this,[=](){
            this->hide();
            chooseScene->show();
        });

    });

    MyPushButton *learncards = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/tujian.png");
    learncards->setParent(this);
    learncards->move(this->width()*0.44, this->height()*0.5+100);
    cardScene = new Learn_cards;
    connect(learncards, &QPushButton::clicked, [=](){
        learncards->zoom1();
        learncards->zoom2();

        QTimer::singleShot(500,this,[=](){
            this->hide();
            cardScene->show();
        });
    });

    MyPushButton *learnrule = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/guize.png");
    learnrule->setParent(this);
    learnrule->move(this->width()*0.44, this->height()*0.5+200);
    connect(learnrule, &QPushButton::clicked, [=](){
        learnrule->zoom1();
        learnrule->zoom2();
    });
}

void login::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap back;
    back.load(":/new/C:/Users/33965/Desktop/resource/background.jpg");
    painter.drawPixmap(0,0,this->width(), this->height(),back);
}
login::~login()
{
    delete ui;
}

