#ifndef PAGE_H
#define PAGE_H

#include <QMainWindow>
#include <QPushButton>
#include "learn_rules.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class page : public QMainWindow
{
    Q_OBJECT

public:
    page(QWidget *parent = nullptr);
    ~page();

    //重写paintEvent事件，画背景图
    void paintEvent(QPaintEvent*);
private slots:
    void on_cards_clicked();
    void on_rules_clicked();
    void on_begin_clicked();
    void reshow();
private:
    Ui::MainWindow *ui;
    QPushButton begin;
    QPushButton card;
    QPushButton rule;
};
#endif // PAGE_H
