QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    battle1.cpp \
    character.cpp \
    choose.cpp \
    enemy.cpp \
    learn_cards.cpp \
    learn_rules.cpp \
    main.cpp \
    page.cpp

HEADERS += \
    battle1.h \
    character.h \
    choose.h \
    enemy.h \
    learn_cards.h \
    learn_rules.h \
    page.h

FORMS += \
    battle1.ui \
    choose.ui \
    learn_cards.ui \
    learn_rules.ui \
    page.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    C:/Users/33965/Desktop/background.png

RESOURCES += \
    pic.qrc
