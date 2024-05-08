#ifndef CHOOSE_H
#define CHOOSE_H

#include <QWidget>
#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include <battle.h>
class choose : public QWidget
{
    Q_OBJECT
    int c1;
    int c2;
    int c3;
public:
    void updateC1(int x);
    void updateC2(int x);
    void updateC3(int x);
    int getc1();
    int getc2();
    int getc3();
    battle *battleScence = NULL;
    explicit choose(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);

signals:

};

#endif // CHOOSE_H
