#-------------------------------------------------
#
# Project created by QtCreator 2012-12-12T00:58:10
#
# creater:liusong
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = sqltest
TEMPLATE = app



SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    search.cpp

HEADERS  += mainwindow.h \
    login.h \
    search.h

FORMS    += mainwindow.ui \
    login.ui \
    search.ui
