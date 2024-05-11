#ifndef LOSE_H
#define LOSE_H

#include <QWidget>
#include <mypushbutton.h>
class Lose : public QWidget
{
    Q_OBJECT
    MyPushButton *back;
public:
    explicit Lose(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
signals:

};

#endif // LOSE_H
