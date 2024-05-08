#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include <choose.h>
#include <learn_cards.h>
QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();
    void paintEvent(QPaintEvent*);
    choose *chooseScene = NULL;
    Learn_cards *cardScene = NULL;
private:
    Ui::login *ui;
};
#endif // LOGIN_H
