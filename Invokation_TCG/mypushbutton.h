#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QPixmap>
#include <QDebug>
#include <QPropertyAnimation>
class MyPushButton : public QPushButton
{
    Q_OBJECT

public:
    MyPushButton(QString normalImg);
    QPixmap Img;
    void zoom1();
    void zoom2();
signals:

};

#endif // MYPUSHBUTTON_H
