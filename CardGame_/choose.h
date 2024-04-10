#ifndef CHOOSE_H
#define CHOOSE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class Choose;
}

class Choose : public QWidget
{
    Q_OBJECT

public:
    explicit Choose(QWidget *parent = nullptr);
    ~Choose();
    void paintEvent(QPaintEvent *);

public slots:
    void on_begin_clicked();
    void on_choose1_clicked();
    void on_choose2_clicked();
    void on_choose3_clicked();
    void on_choose4_clicked();
    void on_choose5_clicked();
    void on_choose6_clicked();
    void on_choose7_clicked();
    void on_choose8_clicked();
private:
    Ui::Choose *ui;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
};

#endif // CHOOSE_H
