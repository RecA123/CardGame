#ifndef WIN_H
#define WIN_H

#include <QWidget>
#include <mypushbutton.h>

class Win : public QWidget
{
    Q_OBJECT
public:
    explicit Win(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    MyPushButton *back;
signals:

};

#endif // WIN_H
