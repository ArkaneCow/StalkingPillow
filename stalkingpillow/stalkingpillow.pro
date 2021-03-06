#-------------------------------------------------
#
# Project created by QtCreator 2014-12-03T22:34:18
#
#-------------------------------------------------

QT       += core gui network xml androidextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = stalkingpillow
TEMPLATE = app


SOURCES += main.cpp\
    rosterscreen.cpp \
    settingsscreen.cpp \
    monitorscreen.cpp \
    mainscreen.cpp \
    xmppclient.cpp \
    mainwindow.cpp \
    notificationclient.cpp

HEADERS  += \
    rosterscreen.h \
    settingsscreen.h \
    monitorscreen.h \
    mainscreen.h \
    xmppclient.h \
    mainwindow.h \
    notificationclient.h

win32 {
INCLUDEPATH += \
    /Users/jwpilly/Documents/QtProjects/qxmpp-master/src/base \
    /Users/jwpilly/Documents/QtProjects/qxmpp-master/src/client
}
android {
INCLUDEPATH += \
    /Users/jwpilly/Documents/QtProjects/qxmpp-master/src/base \
    /Users/jwpilly/Documents/QtProjects/qxmpp-master/src/client
}
unix {
INCLUDEPATH += \
    /home/jwpilly/Git/qxmpp/src/base \
    /home/jwpilly/Git/qxmpp/src/client
}

win32 {
    LIBS += -L/Users/jwpilly/Documents/QtProjects/build-qxmpp-Desktop_Qt_5_3_0_MinGW_32bit-Release/src
}
linux {
    LIBS += -L/home/jwpilly/Git/qxmpp/src/
}
android {
    LIBS += -L/home/jwpilly/Git/build-qxmpp-Android_for_x86_GCC_4_9_Qt_5_4_0-Release/src
    #LIBS += -L/Users/jwpilly/Documents/QtProjects/build-qxmpp-Android_for_armeabi_v7a_GCC_4_9_Qt_5_3_0-Release/src
}

win32 {
    LIBS += -lqxmpp0
}
linux {
    LIBS += -lqxmpp
}
android {
    LIBS += -lqxmpp
}

CONFIG += mobility
MOBILITY = 

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

OTHER_FILES += \
    android/AndroidManifest.xml \
    android/src/com/PillowSoft/PillowStalk/NotificationClient.java

