#-------------------------------------------------
#
# Project created by QtCreator 2014-12-03T22:34:18
#
#-------------------------------------------------

QT       += core gui network xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = stalkingpillow
TEMPLATE = app


SOURCES += main.cpp\
    rosterscreen.cpp \
    settingsscreen.cpp \
    monitorscreen.cpp \
    mainscreen.cpp

HEADERS  += \
    rosterscreen.h \
    settingsscreen.h \
    monitorscreen.h \
    mainscreen.h

INCLUDEPATH += \
    /Users/jwpilly/Documents/QtProjects/qxmpp-master/src/base \
    /Users/jwpilly/Documents/QtProjects/qxmpp-master/src/client

win32 {
    LIBS += -L/Users/jwpilly/Documents/QtProjects/build-qxmpp-Desktop_Qt_5_3_0_MinGW_32bit-Release/src
}
android {
    LIBS += -L/Users/jwpilly/Documents/QtProjects/build-qxmpp-Android_for_armeabi_v7a_GCC_4_9_Qt_5_3_0-Release/src
}

win32 {
    LIBS += -lqxmpp0
}
android {
    LIBS += -lqxmpp
}

CONFIG += mobility
MOBILITY = 

