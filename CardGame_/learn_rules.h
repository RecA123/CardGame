#ifndef LEARN_RULES_H
#define LEARN_RULES_H

#include <QWidget>
#include "page.h"

namespace Ui {
class learn_rules;
}

class learn_rules : public QWidget
{
    Q_OBJECT

public:
    explicit learn_rules(QWidget *parent = nullptr);
    ~learn_rules();
private slots:
    void on_return_clicked();
signals:
    void sendsignal();
private:
    Ui::learn_rules *ui;
};

#endif // LEARN_RULES_H
