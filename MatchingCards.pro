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
    image.cpp \
    main.cpp \
    mainwindow.cpp \
    playing.cpp\
    loginwindow.cpp\
    users.cpp

HEADERS += \
    cursor.h \
    gameover.h \
    image.h \
    mainwindow.h \
    playing.h\
    loginwindow.h\
    users.h

FORMS += \
    gameover.ui \
    mainwindow.ui\
    loginwindow.ui






# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    .gitignore \
    img0.png
