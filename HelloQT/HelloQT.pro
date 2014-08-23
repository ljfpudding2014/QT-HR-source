#-------------------------------------------------
#
# Project created by QtCreator 2014-04-28T08:48:01
#
#-------------------------------------------------

QT      += core gui
QT      += sql


TARGET = HelloQT
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    chellodatabase.cpp \
    logindialog.cpp \
	mysplashscreen.cpp \
    hrmainwindow.cpp

HEADERS  += mainwindow.h \
    chellodatabase.h \
    logindialog.h \
    createdbtable.h\
	mysplashscreen.h \
    hrmainwindow.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    hrmainwindow.ui

RESOURCES += \
    helloQT.qrc
