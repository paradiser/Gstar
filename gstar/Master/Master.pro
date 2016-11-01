TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    acceptStringThenReply.cpp \
    dealCsv.cpp \
    sendString.cpp \
    dealServerInfo.cpp

HEADERS += \
    acceptStringThenReply.h \
    dealCsv.h \
    sendString.h \
    dealServerInfo.h

DISTFILES += \
    settings.csv \
    users.csv \
    servers.csv
