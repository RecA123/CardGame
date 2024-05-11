#include "battle.h"

#include <QPixmap>
#include <QString>
#include <QIcon>
#include <QTimer>
#include <mypushbutton.h>
#include <QDebug>
#include <QTextEdit>
#include <QFont>
#include <QRandomGenerator>
#include <QSound>
//火1 水2 雷3 冰4 草5 岩6 风7 物理0
//单手剑1 双手剑2 长枪3 法器4 弓箭5

battle::battle(int c1, int c2, int c3, QWidget *parent) : QWidget(parent)
{
    QSound *music = new QSound("C:/Users/33965/Desktop/resource/lnc04-lpp1p.wav");
    music->play();
    music->setLoops(-1);

    //初始化功能按钮
    xiaoPi = new QPushButton;
    xiaoPi->setParent(this);
    xiaoPi->move(150,700);
    xiaoPi->setFixedSize(140,240);
    xiaoPi->setIcon(QIcon(":/new/C:/Users/33965/Desktop/resource/xiaopi.webp"));
    xiaoPi->setIconSize(QSize(140,240));

    tudou = new QPushButton;
    tudou->setParent(this);
    tudou->move(350,700);
    tudou->setFixedSize(140,240);
    tudou->setIcon(QIcon(":/new/C:/Users/33965/Desktop/resource/ji.webp"));
    tudou->setIconSize(QSize(140,240));

    //初始化背景图片
    QPixmap back;
    back.load(":/new/C:/Users/33965/Desktop/resource/background.jpg");
    this->setFixedSize(back.width()*1.5, back.height()*1.5);
    this->setWindowIcon(QPixmap(":/new/C:/Users/33965/Desktop/resource/icon.webp"));

    //初始化召唤物图片
    aozi.load(":/new/C:/Users/33965/Desktop/resource/aozi.png");
    fischl_s = new QLabel(this);
    fischl_s->setFixedSize(128, 155);
    fischl_s->setScaledContents(true);
    fischl_s->move(this->width()*0.5+500, 600);

    jiuwu.load(":/new/C:/Users/33965/Desktop/resource/jiuwu.png");
    diona_s = new QLabel(this);
    diona_s->setFixedSize(128, 155);
    diona_s->setScaledContents(true);
    diona_s->move(this->width()*0.5+650, 600);

    shuimu.load(":/new/C:/Users/33965/Desktop/resource/shuimu.png");
    kokomi_s = new QLabel(this);
    kokomi_s->setFixedSize(128, 155);
    kokomi_s->setScaledContents(true);
    kokomi_s->move(this->width()*0.5+500, 800);

    fengchang.load(":/new/C:/Users/33965/Desktop/resource/jean_o.png");
    jean_s = new QLabel(this);
    jean_s->setFixedSize(128, 155);
    jean_s->setScaledContents(true);
    jean_s->move(this->width()*0.5+650, 800);

    //初始化状态栏
    QFont textEditfont("Microsoft YaHei", 14, 75);
    text = new QTextEdit;
    text->setFont(textEditfont);
    text->setParent(this);
    text->setFixedSize(550,500);
    text->move(this->width()*0.5+250, 50);

    //初始化角色、回合数、骰子位置
    character1 = c1;
    character2 = c2;
    character3 = c3;
    initial();

    p1_hp_label = new QLabel;
    p1_hp_label->setParent(this);
    p1_hp_label->setFixedSize(40,40);
    p1_hp_label->setFont(textEditfont);
    p1_hp_label->move(this->width()*0.5-450,700);
    p1_hp_label->setText((QString::number(p1->gethp())));

    p1_energy_label = new QLabel;
    p1_energy_label->setParent(this);
    p1_energy_label->setFixedSize(60,40);
    p1_energy_label->setFont(textEditfont);
    p1_energy_label->move(this->width()*0.5-460,740);
    p1_energy_label->setStyleSheet("color:rgb(255,215,0)");
    p1_energy_label->setText(QString::number(p1->is_energy)+"/"+QString::number(p1->energy));

    p2_hp_label = new QLabel;
    p2_hp_label->setParent(this);
    p2_hp_label->setFixedSize(40,40);
    p2_hp_label->setFont(textEditfont);
    p2_hp_label->move(this->width()*0.5-155,700);
    p2_hp_label->setText((QString::number(p2->gethp())));

    p2_energy_label = new QLabel;
    p2_energy_label->setParent(this);
    p2_energy_label->setFixedSize(60,40);
    p2_energy_label->setFont(textEditfont);
    p2_energy_label->setStyleSheet("color:rgb(255,215,0)");
    p2_energy_label->move(this->width()*0.5-165,740);
    p2_energy_label->setText(QString::number(p2->is_energy)+"/"+QString::number(p2->energy));

    p3_hp_label = new QLabel;
    p3_hp_label->setParent(this);
    p3_hp_label->setFixedSize(40,40);
    p3_hp_label->setFont(textEditfont);
    p3_hp_label->move(this->width()*0.5+150,700);
    p3_hp_label->setText((QString::number(p3->gethp())));

    p3_energy_label = new QLabel;
    p3_energy_label->setParent(this);
    p3_energy_label->setFixedSize(60,40);
    p3_energy_label->setFont(textEditfont);
    p3_energy_label->move(this->width()*0.5+140,740);
    p3_energy_label->setStyleSheet("color:rgb(255,215,0)");
    p3_energy_label->setText(QString::number(p3->is_energy)+"/"+QString::number(p3->energy));

    big_round = 1;
    small_round = 1;
    for(int i=0; i<8; i++){
        label[i].setParent(this);
        label[i].move(this->width()-100, 50+70*i);
        label[i].setFixedSize(60,60);
    }

    //实例化结束界面
    winScence = new Win;
    loseScence = new Lose;

    //初始化元素图片
    fire.load(":/new/C:/Users/33965/Desktop/resource/fire.png");
    water.load(":/new/C:/Users/33965/Desktop/resource/water.png");
    lightning.load(":/new/C:/Users/33965/Desktop/resource/lightning.png");
    ice.load(":/new/C:/Users/33965/Desktop/resource/ice.png");
    grass.load(":/new/C:/Users/33965/Desktop/resource/grass.png");


    //初始化结束回合按钮
    change_round = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/end.png");
    change_round->setParent(this);
    change_round->move(30, this->height()*0.5-30);

    //初始化敌人
    enemy = new Enemy(20);
    e_is_e = new QLabel(this);
    e_is_e->setFixedSize(60,67);
    e_is_e->move(this->width()*0.5+120, 50);

    //初始化敌人血条
    e_hplable = new QLabel;
    e_hplable->setParent(this);
    e_hplable->setFixedSize(40,40);
    e_hplable->setFont(textEditfont);
    e_hplable->move(this->width()*0.5-145, 50);
    e_hplable->setText(QString::number(enemy->gethp()));

    //初始化战斗按钮
    MyPushButton *normalatk = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/attack.png");
    normalatk->setParent(this);
    normalatk->move(1500,950);
    MyPushButton *elementalskl = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/skill.png");
    elementalskl->setParent(this);
    elementalskl->move(1650,950);
    MyPushButton *elementalbrst = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/burst.png");
    elementalbrst->setParent(this);
    elementalbrst->move(1800,950);

    //连接结束按钮和槽函数
    connect(change_round, &QPushButton::clicked, this, [=](){
        change_clicked();
    });

    //连接切人按钮和槽函数
    connect(char1, &QPushButton::clicked, this, [=](){
        if(otherTouzi()>=1){
            changeP1();
            int num = 0;
            for(int i=0; ; i++){
                for(int j=0; j<8; j++){
                    if(touzi[j]!=8){
                        if(touzi[j]!=is_char->getE_type()&&touzi[j]!=0){
                            if(touzi[j]!=p1->getE_type()&&touzi[j]!=p2->getE_type()&&touzi[j]!=p3->getE_type())
                            {
                                touzi[j]=8;
                                label[j].clear();
                                num++;
                                if(num>=1)
                                    break;
                            }
                        }
                    }
                }
                if(num>=1){
                    break;
                }else{
                    for(int j=0; j<8; j++){
                        if(touzi[j]!=8){
                            if(touzi[j]!=is_char->getE_type()&&touzi[j]!=0){
                                touzi[j]=8;
                                label[j].clear();
                                num++;
                                if(num>=1)
                                    break;
                            }
                        }
                    }
                    if(num>=1){
                        break;
                    }else{
                        for(int j=0; j<8; j++){
                            if(touzi[j]!=8){
                                touzi[j]=8;
                                label[j].clear();
                                num++;
                                if(num>=1)
                                    break;
                            }
                        }
                        break;
                    }
                }
                break;
            }
            small_round += 1;
            QTimer::singleShot(1500, this, [=](){
                  if(enemy->actTime<2 && !enemy->is_frozen){
                      if(big_round != 1 || small_round != 1){
                          if(enemy->burstRnd == 3){
                             enemy->Burst(is_char);
                             text->append("丘丘王释放元素爆发，攻击了"+is_char->name+", "+is_char->name+"血量为"+QString::number(is_char->gethp()));
                             text->append("敌方行动结束");
                             text->append(" ");
                         }else{
                             enemy->normalAtk(is_char);
                             text->append("丘丘王攻击了"+is_char->name+", "+is_char->name+"血量为"+QString::number(is_char->gethp()));
                             text->append("敌方行动结束");
                             text->append(" ");
                         }
                         enemy->actTime++;
                      }
                  updateNum();
                  is_dead();
                  }

                  if(is_win()){
                      QTimer::singleShot(1500, this, [=](){
                          this->hide();
                          winScence->show();
                      });
                  }
                  if(is_fail()){
                      QTimer::singleShot(1500, this, [=](){
                          this->hide();
                          loseScence->show();
                      });
                  }
            });
        }else{
            text->append("该类型元素骰子不足！！");
            text->append(" ");
        }
        if(is_win()){
            QTimer::singleShot(1500, this, [=](){
                this->hide();
                winScence->show();
            });
        }
        if(is_fail()){
            QTimer::singleShot(1500, this, [=](){
                this->hide();
                loseScence->show();
            });
        }
    });

    connect(char2, &QPushButton::clicked, this, [=](){
        if(otherTouzi()>=1){
            changeP2();
            int num = 0;
            for(int i=0; ; i++){
                for(int j=0; j<8; j++){
                    if(touzi[j]!=8){
                        if(touzi[j]!=is_char->getE_type()&&touzi[j]!=0){
                            if(touzi[j]!=p1->getE_type()&&touzi[j]!=p2->getE_type()&&touzi[j]!=p3->getE_type())
                            {
                                touzi[j]=8;
                                label[j].clear();
                                num++;
                                if(num>=1)
                                    break;
                            }
                        }
                    }
                }
                if(num>=1){
                    break;
                }else{
                    for(int j=0; j<8; j++){
                        if(touzi[j]!=8){
                            if(touzi[j]!=is_char->getE_type()&&touzi[j]!=0){
                                touzi[j]=8;
                                label[j].clear();
                                num++;
                                if(num>=1)
                                    break;
                            }
                        }
                    }
                    if(num>=1){
                        break;
                    }else{
                        for(int j=0; j<8; j++){
                            if(touzi[j]!=8){
                                touzi[j]=8;
                                label[j].clear();
                                num++;
                                if(num>=1)
                                    break;
                            }
                        }
                        break;
                    }
                }
                break;
            }
            small_round += 1;
            QTimer::singleShot(1500, this, [=](){
                if(enemy->actTime<2 && !enemy->is_frozen){
                    if(big_round != 1 || small_round != 1){
                        if(enemy->burstRnd == 3){
                           enemy->Burst(is_char);
                           text->append("丘丘王释放元素爆发，攻击了"+is_char->name+", "+is_char->name+"血量为"+QString::number(is_char->gethp()));
                           text->append("敌方行动结束");
                           text->append(" ");
                       }else{
                           enemy->normalAtk(is_char);
                           text->append("丘丘王攻击了"+is_char->name+", "+is_char->name+"血量为"+QString::number(is_char->gethp()));
                           text->append("敌方行动结束");
                           text->append(" ");
                       }
                       enemy->actTime++;
                    }
                  updateNum();
                  is_dead();
                }
                  if(is_win()){
                      QTimer::singleShot(1500, this, [=](){
                          this->hide();
                          winScence->show();
                      });
                  }
                  if(is_fail()){
                      QTimer::singleShot(1500, this, [=](){
                          this->hide();
                          loseScence->show();
                      });
                  }

            });
        }else{
            text->append("该类型元素骰子不足！！");
            text->append(" ");
        }
        if(is_win()){
            QTimer::singleShot(1500, this, [=](){
                this->hide();
                winScence->show();
            });
        }
        if(is_fail()){
            QTimer::singleShot(1500, this, [=](){
                this->hide();
                loseScence->show();
            });
        }
    });

    connect(char3, &QPushButton::clicked, this, [=](){
        if(otherTouzi()>=1){
            changeP3();

            int num = 0;
            for(int i=0; ; i++){
                for(int j=0; j<8; j++){
                    if(touzi[j]!=8){
                        if(touzi[j]!=is_char->getE_type()&&touzi[j]!=0){
                            if(touzi[j]!=p1->getE_type()&&touzi[j]!=p2->getE_type()&&touzi[j]!=p3->getE_type())
                            {
                                touzi[j]=8;
                                label[j].clear();
                                num++;
                                if(num>=1)
                                    break;
                            }
                        }
                    }
                }
                if(num>=1){
                    break;
                }else{
                    for(int j=0; j<8; j++){
                        if(touzi[j]!=8){
                            if(touzi[j]!=is_char->getE_type()&&touzi[j]!=0){
                                touzi[j]=8;
                                label[j].clear();
                                num++;
                                if(num>=1)
                                    break;
                            }
                        }
                    }
                    if(num>=1){
                        break;
                    }else{
                        for(int j=0; j<8; j++){
                            if(touzi[j]!=8){
                                touzi[j]=8;
                                label[j].clear();
                                num++;
                                if(num>=1)
                                    break;
                            }
                        }
                        break;
                    }
                }
                break;
            }
            small_round += 1;
            QTimer::singleShot(1500, this, [=](){
                if(enemy->actTime<2 && enemy->is_frozen){
                    if(big_round != 1 || small_round != 1){
                        if(enemy->burstRnd == 3){
                           enemy->Burst(is_char);
                           text->append("丘丘王释放元素爆发，攻击了"+is_char->name+", "+is_char->name+"血量为"+QString::number(is_char->gethp()));
                           text->append("敌方行动结束");
                           text->append(" ");
                       }else{
                           enemy->normalAtk(is_char);
                           text->append("丘丘王攻击了"+is_char->name+", "+is_char->name+"血量为"+QString::number(is_char->gethp()));
                           text->append("敌方行动结束");
                           text->append(" ");
                       }
                       enemy->actTime++;
                    }
                  updateNum();
                  is_dead();
                }
                  if(is_win()){
                      QTimer::singleShot(1500, this, [=](){
                          this->hide();
                          winScence->show();
                      });
                  }
                  if(is_fail()){
                      QTimer::singleShot(1500, this, [=](){
                          this->hide();
                          loseScence->show();
                      });
                  }
            });
        }else{
            text->append("该类型元素骰子不足！！");
            text->append(" ");
        }
        if(is_win()){
            QTimer::singleShot(1500, this, [=](){
                this->hide();
                winScence->show();
            });
        }
        if(is_fail()){
            QTimer::singleShot(1500, this, [=](){
                this->hide();
                loseScence->show();
            });
        }
    });

    //连接攻击按钮和槽函数
    connect(normalatk, &QPushButton::clicked, this, [=](){
        normalatk->zoom1();
        is_charbtn->zoom1();
        normalatk->zoom2();
        is_charbtn->zoom2();
        QTimer::singleShot(500, this, [=](){
            int is_match = 0;

            //判断骰子条件
            for(int i=0; i<8; i++){
                if(touzi[i]==0 || touzi[i] == is_char->getE_type()){
                    is_match ++;
                }
            }
            if(is_match >= 1&&otherTouzi()>=3){
                normalAttack_clicked();

                updateE();
                //更新参数
                if(is_char->is_energy<is_char->energy)
                    is_char->is_energy++;
                updateNum();

                //判断输赢条件
                if(is_win()){
                    QTimer::singleShot(1500, this, [=](){
                        this->hide();
                        winScence->show();
                    });
                }
                if(is_fail()){
                    QTimer::singleShot(1500, this, [=](){
                        this->hide();
                        loseScence->show();
                    });
                }

                //敌人反击
                QTimer::singleShot(1000, this, [=](){
                   if(enemy->gethp() != 0 && enemy->actTime<2 && !enemy->is_frozen){
                       if(enemy->burstRnd == 3){
                           enemy->Burst(is_char);
                           text->append("丘丘王释放元素爆发，攻击了"+is_char->name+", "+is_char->name+"血量为"+QString::number(is_char->gethp()));
                           text->append("敌方行动结束");
                           text->append(" ");
                           enemy->actTime++;
                       }else{
                           enemy->normalAtk(is_char);
                           text->append("丘丘王攻击了"+is_char->name+", "+is_char->name+"血量为"+QString::number(is_char->gethp()));
                           text->append("敌方行动结束");
                           text->append(" ");
                           enemy->actTime++;
                       }
                       updateNum();
                       is_dead();
                   }else if(enemy->is_frozen){
                       text->append("敌人被冻结了！");
                       updateNum();
                       is_dead();
                   }

                   if(is_win()){
                       QTimer::singleShot(1500, this, [=](){
                           this->hide();
                           winScence->show();
                       });
                   }
                   if(is_fail()){
                       QTimer::singleShot(1500, this, [=](){
                           this->hide();
                           loseScence->show();
                       });
                   }
                });

            }else{
                text->append("该类型元素骰子不足！！");
                text->append(" ");
            }

        });

        small_round += 1;
    });

    connect(elementalskl, &QPushButton::clicked, this, [=](){
        elementalskl->zoom1();
        is_charbtn->zoom1();
        elementalskl->zoom2();
        is_charbtn->zoom2();
        QTimer::singleShot(500, this, [=](){
            int is_match = 0;
            for(int i=0; i<8; i++){
                if(touzi[i]==0 || touzi[i] == is_char->getE_type()){
                    is_match ++;
                }
            }
            if(is_match >= 3){
                elementalSkill_clicked();
                if(is_char->is_energy<is_char->energy)
                    is_char->is_energy++;
                updateNum();
                if(is_win()){
                    QTimer::singleShot(1500, this, [=](){
                        this->hide();
                        winScence->show();
                    });
                }
                if(is_fail()){
                    QTimer::singleShot(1500, this, [=](){
                        this->hide();
                        loseScence->show();
                    });
                }

                QTimer::singleShot(1000, this, [=](){
                    if(enemy->gethp() != 0 && enemy->actTime<2 && !enemy->is_frozen){
                        if(enemy->burstRnd == 3){
                            enemy->Burst(is_char);
                            text->append("丘丘王释放元素爆发，攻击了"+is_char->name+", "+is_char->name+"血量为"+QString::number(is_char->gethp()));
                            text->append("敌方行动结束");
                            text->append(" ");
                            enemy->actTime++;
                        }else{
                            enemy->normalAtk(is_char);
                            text->append("丘丘王攻击了"+is_char->name+", "+is_char->name+"血量为"+QString::number(is_char->gethp()));
                            text->append("敌方行动结束");
                            text->append(" ");
                            enemy->actTime ++;
                        }
                        updateNum();
                        is_dead();
                    }else if(enemy->is_frozen){
                        text->append("敌人被冻结了！");
                        updateNum();
                        is_dead();
                    }

                   if(is_win()){
                       QTimer::singleShot(1500, this, [=](){
                           this->hide();
                           winScence->show();
                       });
                   }
                   if(is_fail()){
                       QTimer::singleShot(1500, this, [=](){
                           this->hide();
                           loseScence->show();
                       });
                   }
                });

            }else{
                text->append("该类型元素骰子不足！！");
                text->append(" ");
            }

        });


        small_round += 1;

        if(is_win()){
            QTimer::singleShot(1500, this, [=](){
                this->hide();
                winScence->show();
            });
        }
        if(is_fail()){
            QTimer::singleShot(1500, this, [=](){
                this->hide();
                loseScence->show();
            });
        }
    });

    connect(elementalbrst, &QPushButton::clicked, this, [=](){
        elementalbrst->zoom1();
        is_charbtn->zoom1();
        elementalbrst->zoom2();
        is_charbtn->zoom2();
        QTimer::singleShot(500, this, [=](){
            int is_match = 0;
            for(int i=0; i<8; i++){
                if(touzi[i]==0 || touzi[i] == is_char->getE_type()){
                    is_match ++;
                }
            }
            if(is_match >= is_char->burst_cost || is_char->is_energy == is_char->energy){
                elementalSkill_clicked();
                is_char->is_energy = 0;
                updateNum();
                QTimer::singleShot(1000, this, [=](){
                    if(enemy->gethp() != 0 && enemy->actTime<2 && !enemy->is_frozen){
                        if(enemy->burstRnd == 3){
                            enemy->Burst(is_char);
                            text->append("丘丘王释放元素爆发，攻击了"+is_char->name+", "+is_char->name+"血量为"+QString::number(is_char->gethp()));
                            text->append("敌方行动结束");
                            text->append(" ");
                            enemy->actTime++;
                        }else{
                            enemy->normalAtk(is_char);
                            text->append("丘丘王攻击了"+is_char->name+", "+is_char->name+"血量为"+QString::number(is_char->gethp()));
                            text->append("敌方行动结束");
                            text->append(" ");
                            enemy->actTime ++;
                        }
                        updateNum();
                        is_dead();
                    }else if(enemy->is_frozen){
                        text->append("敌人被冻结了！");
                        if(is_char->is_energy<is_char->energy)
                            is_char->is_energy++;
                        updateNum();
                        is_dead();
                    }
                       if(is_win()){
                           QTimer::singleShot(1500, this, [=](){
                               this->hide();
                               winScence->show();
                           });
                       }
                       if(is_fail()){
                           QTimer::singleShot(1500, this, [=](){
                               this->hide();
                               loseScence->show();
                           });
                       }

                });
            }else if(is_char->is_energy<is_char->energy){
                text->append("角色充能不足！！");
                text->append(" ");
            }else{
                text->append("该类型元素骰子不足");
            }

        });

        small_round += 1;

        if(is_win()){
            QTimer::singleShot(1500, this, [=](){
                this->hide();
                winScence->show();
            });
        }
        if(is_fail()){
            QTimer::singleShot(1500, this, [=](){
                this->hide();
                loseScence->show();
            });
        }
    });

    connect(xiaoPi, &QPushButton::clicked, this, [=](){
        xiaoPi_clicked();
        xiaoPi->setEnabled(false);
    });

    connect(tudou, &QPushButton::clicked, this, [=](){
        tudou_clicked();
        tudou->setEnabled(false);
    });

}

void battle::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pixmap;
    pixmap.load(":/new/C:/Users/33965/Desktop/resource/background2.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
    QPixmap enemy;
    enemy.load(":/new/C:/Users/33965/Desktop/resource/yankui.webp");
    painter.drawPixmap(this->width()*0.5-105, 50, 210, 360, enemy);


}

void battle::updateE()
{
    if(enemy->getE()==1){
        fire.scaled(e_is_e->size(), Qt::KeepAspectRatio);
        e_is_e->setScaledContents(true);
        e_is_e->setPixmap(fire);
    }else if(enemy->getE()==2){
        water.scaled(e_is_e->size(), Qt::KeepAspectRatio);
        e_is_e->setScaledContents(true);
        e_is_e->setPixmap(water);
    }else if(enemy->getE()==3){
        lightning.scaled(e_is_e->size(), Qt::KeepAspectRatio);
        e_is_e->setScaledContents(true);
        e_is_e->setPixmap(lightning);
    }else if(enemy->getE()==4){
        ice.scaled(e_is_e->size(), Qt::KeepAspectRatio);
        e_is_e->setScaledContents(true);
        e_is_e->setPixmap(ice);
    }else if(enemy->getE() == 0){
        e_is_e->clear();
    }

}

void battle::updateNum()
{
    p1_hp_label->setText((QString::number(p1->gethp())));
    p1_energy_label->setText(QString::number(p1->is_energy)+"/"+QString::number(p1->energy));
    p2_hp_label->setText((QString::number(p2->gethp())));
    p2_energy_label->setText(QString::number(p2->is_energy)+"/"+QString::number(p2->energy));
    p3_hp_label->setText((QString::number(p3->gethp())));
    p3_energy_label->setText(QString::number(p3->is_energy)+"/"+QString::number(p3->energy));
}

void battle::getTouzi()
{

    for(int i=0; i<8; i++){
        touzi[i] = QRandomGenerator::global()->bounded(8);
    }
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            int temp = touzi[i];
            if(touzi[i]<touzi[j])
            {
                touzi[i] = touzi[j];
                touzi[j] = temp;
            }
        }
    }

    for(int i=0; i<8; i++){
        if(touzi[i] == 0){
            label[i].setPixmap(QPixmap(":/new/C:/Users/33965/Desktop/resource/all_touzi.png"));
        }else if(touzi[i] == 1){
            label[i].setPixmap(QPixmap(":/new/C:/Users/33965/Desktop/resource/fire_touzi.png"));
        }else if(touzi[i] == 2){
            label[i].setPixmap(QPixmap(":/new/C:/Users/33965/Desktop/resource/water_touzi.png"));
        }else if(touzi[i] == 3){
            label[i].setPixmap(QPixmap(":/new/C:/Users/33965/Desktop/resource/lightning_touzi.png"));
        }else if(touzi[i] == 4){
            label[i].setPixmap(QPixmap(":/new/C:/Users/33965/Desktop/resource/ice_touzi.png"));
        }else if(touzi[i] == 5){
            label[i].setPixmap(QPixmap(":/new/C:/Users/33965/Desktop/resource/grass_touzi.png"));
        }else if(touzi[i] == 6){
            label[i].setPixmap(QPixmap(":/new/C:/Users/33965/Desktop/resource/rock_touzi.png"));
        }else if(touzi[i] == 7){
            label[i].setPixmap(QPixmap(":/new/C:/Users/33965/Desktop/resource/wind_touzi.png"));
        }
    }
}

int battle::otherTouzi()
{
    int number=0;
    for(int i=0; i<8; i++){
        if(touzi[i]!=8){
            number++;
        }
    }
    return number;
}

void battle::change_clicked()
{
    if(fischl_s->pixmap() != nullptr && !fischl_s->pixmap()->isNull()){
        int damage = 1;
        if(enemy->getE() == 1 || enemy->getE() == 2 || enemy->getE() == 4){
            damage += 1;
            enemy->updateE(0);
        }else{
            enemy->updateE(3);
        }
        int new_e_hp = enemy->gethp()-damage;
        if(new_e_hp < 0)
            new_e_hp = 0;
        enemy->updateHp(new_e_hp);
        e_hplable->setText(QString::number(enemy->gethp()));
        updateE();
        text->append("奥兹攻击了丘丘王，丘丘王血量为"+QString::number(enemy->gethp()));
        text->append(" ");
        aozi_round ++;
        if(aozi_round == 2){
            fischl_s->clear();
        }
    }
    if(diona_s->pixmap() != nullptr && !diona_s->pixmap()->isNull()){
        int damage = 1;
        if(enemy->getE() == 1 || enemy->getE() == 3){
            damage += 1;
            enemy->updateE(0);
        }else if(enemy->getE() == 2){
            enemy->is_frozen = 1;
            enemy->updateE(0);
            text->append("触发冻结反应，敌人被冻结了");
        }else{
            enemy->updateE(4);
        }
        int new_e_hp = enemy->gethp()-damage;
        if(new_e_hp < 0)
            new_e_hp = 0;
        is_char->addHp(1);
        text->append("我方角色恢复生命值");
        updateNum();
        updateE();
        enemy->updateHp(new_e_hp);
        e_hplable->setText(QString::number(enemy->gethp()));
        text->append("酒雾领域攻击了丘丘王，丘丘王血量为"+QString::number(enemy->gethp()));
        text->append(" ");
        jiuwu_round ++;
        if(jiuwu_round == 2){
            diona_s->clear();
        }
    }
    if(jean_s->pixmap() != nullptr && !jean_s->pixmap()->isNull()){
        int damage = 1;
        if(enemy->getE() == 1 || enemy->getE() == 3 || enemy->getE() == 2 ||enemy->getE() == 4){
            damage += 1;
            enemy->updateE(0);
        }
        int new_e_hp = enemy->gethp()-damage;
        if(new_e_hp < 0)
            new_e_hp = 0;

        is_char->addHp(1);
        text->append("我方角色恢复生命值");
        updateNum();
        updateE();
        enemy->updateHp(new_e_hp);
        e_hplable->setText(QString::number(enemy->gethp()));
        text->append("蒲公英领域攻击了丘丘王，丘丘王血量为"+QString::number(enemy->gethp()));
        text->append(" ");
        fengchang_round ++;
        if(fengchang_round == 2){
            jean_s->clear();
        }
    }
    if(kokomi_s->pixmap() != nullptr && !kokomi_s->pixmap()->isNull()){
        int damage = 1;
        if(enemy->getE() == 1 || enemy->getE() == 3){
            damage += 1;
            enemy->updateE(0);
        }else if(enemy->getE() == 4){
            enemy->is_frozen = 1;
            enemy->updateE(0);
            text->append("触发冻结反应，敌人被冻结了");
        }else{
            enemy->updateE(2);
        }
        int new_e_hp = enemy->gethp()-damage;
        if(new_e_hp < 0)
            new_e_hp = 0;
        is_char->addHp(1);
        text->append("我方角色恢复生命值");
        updateNum();
        updateE();
        enemy->updateHp(new_e_hp);
        e_hplable->setText(QString::number(enemy->gethp()));
        text->append("化海月攻击了丘丘王，丘丘王血量为"+QString::number(enemy->gethp()));
        text->append(" ");
        shuimu_round ++;
        if(shuimu_round == 2){
            kokomi_s->clear();
        }
    }

    xiaoPi->setEnabled(true);
    tudou->setEnabled(true);
    enemy->is_frozen = 0;

    text->append("第"+QString::number(big_round)+"回合结束，我方先手");
    big_round ++;
    enemy->actTime = 0;

    text->append("投骰子中……");
    QTimer::singleShot(1500, this, [=](){
        getTouzi();
        text->append("投掷完成，我方行动");
    });
}

void battle::normalAttack_clicked()
{
    is_char->normalAttack(enemy);
    text->append(is_char->name+"攻击了丘丘王，丘丘王血量为"+QString::number(enemy->gethp()));
    e_hplable->setText(QString::number(enemy->gethp()));
    text->append("我方行动结束，敌方行动");
    text->append(" ");
    int num0 = 0;
    for(int i=0; i<8; i++){
        if(touzi[i] == is_char->getE_type()){
            touzi[i] = 8;
            label[i].clear();
            num0++;
            if(num0>=1)
                break;
            else
                for(int i=0; i<8; i++){
                    if(touzi[i] == 0){
                        touzi[i] = 8;
                        label[i].clear();
                    }
                }
        }
    }
    int num = 0;
    for(int i=0; ; i++){
        for(int j=0; j<8; j++){
            if(touzi[j]!=8){
                if(touzi[j]!=is_char->getE_type()&&touzi[j]!=0){
                    if(touzi[j]!=p1->getE_type()&&touzi[j]!=p2->getE_type()&&touzi[j]!=p3->getE_type())
                    {
                        touzi[j]=8;
                        label[j].clear();
                        num++;
                        if(num >= 2){
                            break;
                        }
                    }
                }
            }
        }
        if(num >= 2){
            break;
        }else{
            for(int j=0; j<8; j++){
                if(touzi[j]!=8){
                    if(touzi[j]!=is_char->getE_type()&&touzi[j]!=0){
                        touzi[j]=8;
                        label[j].clear();
                        num++;
                        if(num >= 2){
                            break;
                        }
                    }
                }
            }
            if(num>=2){
                break;
            }else{
                for(int j=0; j<8; j++){
                    if(touzi[j]!=8){
                        touzi[j]=8;
                        label[j].clear();
                        num++;
                        if(num >= 2){
                            break;
                        }
                    }
                }
                break;
            }
        }
    }
}

void battle::elementalSkill_clicked()
{
    is_char->elementalSkill(enemy);
    if(is_char->getE_type() == 3){
        fischl_s->setPixmap(aozi);
        aozi_round = 0;
    }else if(is_char->getE_type() == 2){
        kokomi_s->setPixmap(shuimu);

    }
    text->append(is_char->name+"攻击了丘丘王，丘丘王血量为"+QString::number(enemy->gethp()));
    e_hplable->setText(QString::number(enemy->gethp()));
    updateE();
    text->append("我方行动结束，敌方行动");
    text->append(" ");

    int num=0;
    for(int i=0; i<8; i++){
        if(touzi[i] == is_char->getE_type()){
            touzi[i] = 8;
            label[i].clear();
            num++;
            if(num == 3){
                break;
            }
        }
    }
    if(num<3){
        for (int i=0; i<8; i++ ) {
            if(touzi[i] == 0){
                touzi[i] = 8;
                label[i].clear();
                num++;
                if(num == 3){
                    break;
                }
            }
        }
    }

}

void battle::elementalBurst_clicked()
{
    is_char->elementalBurst(enemy);
    if(is_char->getE_type() == 4){
        diona_s->setPixmap(jiuwu);
        jiuwu_round = 0;
    }else if(is_char->getE_type() == 5){
        p1->addHp(2);
        p2->addHp(2);
        p3->addHp(2);
        updateNum();
        text->append("我方恢复血量");
        text->append(" ");

        jean_s->setPixmap(fengchang);
        fengchang_round = 0;
    }

    text->append(is_char->name+"攻击了丘丘王，丘丘王血量为"+QString::number(enemy->gethp()));
    e_hplable->setText(QString::number(enemy->gethp()));
    updateE();
    text->append("我方行动结束，敌方行动");
    text->append(" ");

    int num=0;
    for(int i=0; i<8; i++){
        if(touzi[i]==0 || touzi[i] == is_char->getE_type()){
            touzi[i] = 8;
            label[i].clear();
            num++;
            if(num == is_char->burst_cost){
                break;
            }
        }
    }
    is_char->is_energy = 0;

    if(is_win()){
        QTimer::singleShot(1500, this, [=](){
            this->hide();
            winScence->show();
        });
    }
    if(is_fail()){
        QTimer::singleShot(1500, this, [=](){
            this->hide();
            loseScence->show();
        });
    }

}

void battle::xiaoPi_clicked()
{
    int num = 0;
    for(int i=0; i<8; i++){
        if(touzi[i]!=8 && touzi[i]!=0 && touzi[i]!=p1->getE_type() && touzi[i]!=p2->getE_type() && touzi[i]!=p3->getE_type()){
            touzi[i] = 0;
            label[i].setPixmap(QPixmap(":/new/C:/Users/33965/Desktop/resource/all_touzi.png"));
            num ++;
            if(num == 1){
                break;
            }
        }
    }
    if(num<1)
    {
        for(int i=0; i<8; i++){
            if(touzi[i]!=0 && touzi[i]!=8){
                touzi[i] = 0;
                label[i].setPixmap(QPixmap(":/new/C:/Users/33965/Desktop/resource/all_touzi.png"));
                num ++;
                if(num == 1){
                    break;
                }
            }
        }
    }
}

void battle::tudou_clicked()
{
    is_char->addHp(1);
    updateNum();
}

void battle::initial()
{
    if(character1 == 1){
        p1 = new Diluc(10, 1, 0, 2, 0);
        char1 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Diluc.png");
    }else if(character1 == 2){
        p1 = new Fischl(10, 3, 0, 5, 0);
        char1 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Fischl.png");
    }else if(character1 == 3){
        p1 = new Diona(10, 4, 0, 5, 0);
        char1 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Diona.png");
    }else if(character1 == 4){
        p1 = new Jean(10, 7, 0, 1, 0);
        char1 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Jean.png");
    }else if(character1 == 5){
        p1 = new Kokomi(10, 2, 0, 4, 0);
        char1 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/kokomi.png");
    }else if(character1 == 6){
        p1 = new Diona(10, 6, 0, 4, 0);
        char1 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/ningguang.png");
    }
    char1->setParent(this);
    char1->move(this->width()*0.5-400,700);
    p1_state = new QLabel(this);
    p1_state->move(this->width()*0.5-380,780);
    p1_state->setFixedSize(182,178);

    if(character2 == 1){
        p2 = new Diluc(10, 1, 0, 2, 0);
        char2 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Diluc.png");
    }else if(character2 == 2){
        p2 = new Fischl(10, 3, 0, 5, 0);
        char2 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Fischl.png");
    }else if(character2 == 3){
        p2 = new Diona(10, 4, 0, 5, 0);
        char2 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Diona.png");
    }else if(character2 == 4){
        p2 = new Jean(10, 7, 0, 1, 0);
        char2 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Jean.png");
    }else if(character2 == 5){
        p2 = new Kokomi(10, 2, 0, 4, 0);
        char2 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/kokomi.png");
    }else if(character2 == 6){
        p2 = new Diona(10, 6, 0, 4, 0);
        char2 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/ningguang.png");
    }
    char2->setParent(this);
    char2->move(this->width()*0.5-105,700);
    p2_state = new QLabel(this);
    p2_state->move(this->width()*0.5-85,780);
    p2_state->setFixedSize(182,178);

    if(character3 == 1){
        p3 = new Diluc(10, 1, 0, 2, 0);
        char3= new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Diluc.png");
    }else if(character3 == 2){
        p3 = new Fischl(10, 3, 0, 5, 0);
        char3 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Fischl.png");
    }else if(character3 == 3){
        p3 = new Diona(10, 4, 0, 5, 0);
        char3 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Diona.png");
    }else if(character3 == 4){
        p3 = new Jean(10, 7, 0, 1, 0);
        char3 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/Jean.png");
    }else if(character3 == 5){
        p3 = new Kokomi(10, 2, 0, 4, 0);
        char3 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/kokomi.png");
    }else if(character3 == 6){
        p3 = new Diona(10, 6, 0, 4, 0);
        char3 = new MyPushButton(":/new/C:/Users/33965/Desktop/resource/ningguang.png");
    }
    char3->setParent(this);
    char3->move(this->width()*0.5+200,700);
    p3_state = new QLabel(this);
    p3_state->move(this->width()*0.5+220,780);
    p3_state->setFixedSize(182,178);

    char2->move(this->width()*0.5-105,700);
    char3->move(this->width()*0.5+200,700);
    char1->move(this->width()*0.5-400,650);
    is_char = p1;
    is_charbtn = char1;
    getTouzi();
}

void battle::changeP1()
{
    char2->move(this->width()*0.5-105,700);
    char3->move(this->width()*0.5+200,700);
    char1->move(this->width()*0.5-400,650);
    is_char = p1;
    is_charbtn = char1;
    text->append("我方切换角色"+is_char->name);
    if(big_round != 1 || small_round != 1)
        text->append("我方行动结束，敌方行动");
    text->append(" ");
}

void battle::changeP2()
{
    char1->move(this->width()*0.5-400,700);
    char3->move(this->width()*0.5+200,700);
    char2->move(this->width()*0.5-105,650);
    is_char = p2;
    is_charbtn = char2;
    text->append("我方切换角色"+is_char->name);
    if(big_round != 1 || small_round != 1)
        text->append("我方行动结束，敌方行动");
    text->append(" ");
}

void battle::changeP3()
{
    char1->move(this->width()*0.5-400,700);
    char2->move(this->width()*0.5-105,700);
    char3->move(this->width()*0.5+200,650);
    is_char = p3;
    is_charbtn = char3;
    text->append("我方切换角色"+is_char->name);
    if(big_round != 1 || small_round != 1)
        text->append("我方行动结束，敌方行动");
    text->append(" ");
}

void battle::is_dead()
{
    if(is_char->gethp() == 0){
        text->append(is_char->name+"已阵亡");
        is_charbtn->setEnabled(false);
        if(is_char == p1){
            char1->move(this->width()*0.5-400,700);
            p1_state->setPixmap(QPixmap(":/new/C:/Users/33965/Desktop/resource/dead.png"));
        }else if(is_char == p2){
            char2->move(this->width()*0.5-105,700);
            p2_state->setPixmap(QPixmap(":/new/C:/Users/33965/Desktop/resource/dead.png"));
        }else if(is_char == p3){
            char3->move(this->width()*0.5+200,700);
            p3_state->setPixmap(QPixmap(":/new/C:/Users/33965/Desktop/resource/dead.png"));
        }
        text->append("请切换角色：");
    }
}

bool battle::is_fail()
{
  if(p1->gethp()==0 && p2->gethp()==0 && p3->gethp() == 0)
  {
      return true;
      qDebug()<<"你输了！";
  }
  return false;
}

bool battle::is_win()
{
    if(enemy->gethp() == 0){
        return true;
        qDebug()<<"你赢了!";
    }
    return false;
}
