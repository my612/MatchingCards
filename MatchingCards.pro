QT       += core gui
QT += core gui widgets network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cursor.cpp \
    gameover.cpp \
    main.cpp \
    mainwindow.cpp \
    playing.cpp\
    loginwindow.cpp\
    users.cpp \
    won.cpp

HEADERS += \
    cursor.h \
    gameover.h \
    mainwindow.h \
    playing.h\
    loginwindow.h\
    users.h \
    won.h

FORMS += \
    gameover.ui \
    mainwindow.ui\
    loginwindow.ui \
    won.ui






# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    .gitignore \


RESOURCES += \
    imgs/imgs.qrc



