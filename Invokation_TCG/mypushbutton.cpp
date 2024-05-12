#include "mypushbutton.h"

MyPushButton::MyPushButton(QString normalImg)
{
    Img = normalImg;
    QPixmap pixmap;
    bool ret = pixmap.load(normalImg);
    if(!ret){
        qDebug()<<normalImg<<"加载图片失败";
    }
    this->setFixedSize(pixmap.width(), pixmap.height());
    //设置按钮图标及格式
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(), pixmap.height()));
}

void MyPushButton::zoom1()
{
    //按钮移动
    QPropertyAnimation *animationa1 = new QPropertyAnimation(this, "geometry");
    animationa1->setDuration(200);
    animationa1->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    animationa1->setEndValue(QRect(this->x(), this->y()+10, this->width(), this->height()));
    //设置动画曲线
    animationa1->setEasingCurve(QEasingCurve::OutBounce);
    animationa1->start();
}

void MyPushButton::zoom2()
{
    QPropertyAnimation *animationa1 = new QPropertyAnimation(this, "geometry");
    animationa1->setDuration(200);
    animationa1->setStartValue(QRect(this->x(), this->y()+10, this->width(), this->height()));
    animationa1->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
    animationa1->setEasingCurve(QEasingCurve::OutBounce);
    animationa1->start();
}
