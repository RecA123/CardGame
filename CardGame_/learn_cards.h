#ifndef LEARN_CARDS_H
#define LEARN_CARDS_H

#include <QWidget>
#include <QPaintEvent>
namespace Ui {
class Learn_cards;
}

class Learn_cards : public QWidget
{
    Q_OBJECT

public:
    explicit Learn_cards(QWidget *parent = nullptr);
    ~Learn_cards();
    void paintEvent(QPaintEvent *);
public slots:
    void on_return_clicked();
signals:
    void sendsignal();

private:
    Ui::Learn_cards *ui;
};

#endif // LEARN_CARDS_H
