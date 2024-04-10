#ifndef BATTLE1_H
#define BATTLE1_H

#include <QWidget>

namespace Ui {
class battle1;
}

class battle1 : public QWidget
{
    Q_OBJECT

public:
    explicit battle1(QWidget *parent = nullptr);
    ~battle1();
    void paintEvent(QPaintEvent*);
    void charac1_clicked();
    void charac2_clicked();
    void charac3_clicked();
    void normal_Atk_clicked();
    void elemen_Skil_clicked();
    void elemen_Burst_clicked();
private:
    Ui::battle1 *ui;
};

#endif // BATTLE1_H
