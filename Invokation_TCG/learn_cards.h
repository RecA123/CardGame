#ifndef LEARN_CARDS_H
#define LEARN_CARDS_H

#include <QWidget>
#include <QWidget>
#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
class Learn_cards : public QWidget
{
    Q_OBJECT
public:
    explicit Learn_cards(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
signals:

};

#endif // LEARN_CARDS_H
