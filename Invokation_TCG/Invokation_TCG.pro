QT       += core gui
QT += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    battle.cpp \
    character.cpp \
    choose.cpp \
    diluc.cpp \
    diona.cpp \
    enemy.cpp \
    fischl.cpp \
    jean.cpp \
    kokomi.cpp \
    learn_cards.cpp \
    lose.cpp \
    main.cpp \
    login.cpp \
    mypushbutton.cpp \
    ningguang.cpp \
    win.cpp

HEADERS += \
    battle.h \
    character.h \
    choose.h \
    diluc.h \
    diona.h \
    enemy.h \
    fischl.h \
    jean.h \
    kokomi.h \
    learn_cards.h \
    login.h \
    lose.h \
    mypushbutton.h \
    ningguang.h \
    win.h

FORMS += \
    login.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    picture.qrc


DISTFILES += \
    C:/Users/33965/Desktop/resource/bgm.mp3 \
    C:/Users/33965/Desktop/resource/jiuwu.png \
    C:/Users/33965/Desktop/resource/lnc04-lpp1p.wav
