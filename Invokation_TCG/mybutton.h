#ifndef MYBUTTON_H
#define MYBUTTON_H
#include <QPushButton>
#include <QString>

class Mybutton:public QPushButton
{
public:
    Mybutton(QString normalImg, QString pressImg);
};

#endif // MYBUTTON_H
