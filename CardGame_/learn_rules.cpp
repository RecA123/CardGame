#include "learn_rules.h"
#include "ui_learn_rules.h"
#include "page.h"
#include <QPushButton>
learn_rules::learn_rules(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::learn_rules)
{
    ui->setupUi(this);
    setFixedSize(1942, 1092);
    QPushButton *retr = new QPushButton(this);
    retr->setText("返回主界面");
    connect(retr, &QPushButton::clicked, this, &learn_rules::on_return_clicked);
}

learn_rules::~learn_rules()
{
    delete ui;
}

void learn_rules::on_return_clicked(){
    emit sendsignal();
    this->close();
}
