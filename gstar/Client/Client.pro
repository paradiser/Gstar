
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app

RC_FILE = app.rc

SOURCES += main.cpp\
    mainInterface.cpp \
    md5.cpp \
    dealCsv.cpp \
    registerWindow.cpp \
    contentDialog.cpp \
    communication.cpp \
    sendString.cpp \
    acceptStringThenReply.cpp \
    renderWindow.cpp \
    userFunction.cpp \
    sendThread.cpp \
    cmysplashscreen.cpp

HEADERS  += \
    mainInterface.h \
    md5.h \
    dealCsv.h \
    registerWindow.h \
    contentDialog.h \
    communication.h \
    sendString.h \
    acceptStringThenReply.h \
    renderWindow.h \
    userFunction.h \
    sendThread.h \
    cmysplashscreen.h

FORMS    += \
    mainInterface.ui \
    registerWindow.ui \
    contentDialog.ui \
    communication.ui \
    renderWindow.ui \
    userFunction.ui

DISTFILES += \
    settings.csv \
    res/uploadAndRender.png \
    res/render.png \
    res/uploadAndRender.png

RESOURCES +=
