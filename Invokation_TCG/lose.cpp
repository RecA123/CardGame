#include "lose.h"

#include <QPainter>
Lose::Lose(QWidget *parent) : QWidget(parent)
{
    QPixmap background;
    background.load(":/new/C:/Users/33965/Desktop/resource/background2.png");
    this->setFixedSize(background.width()*1.5, background.height()*1.5);
    this->setWindowIcon(QPixmap(":/new/C:/Users/33965/Desktop/resource/icon.webp"));

    back = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/back.png");
    back->setParent(this);
    back->move(this->width()*0.5-back->width()*0.5, 800);

}

void Lose::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pixmap;
    pixmap.load(":/new/C:/Users/33965/Desktop/resource/lose.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
}
