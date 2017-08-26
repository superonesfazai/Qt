#-------------------------------------------------
#
# Project created by QtCreator 2015-06-25T22:36:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EasyManager
TEMPLATE = app


SOURCES += main.cpp\
    preview.cpp \
    logindialog.cpp \
    datamanager.cpp

HEADERS  += \
    preview.h \
    connection.h \
    logindialog.h \
    datamanager.h

FORMS    += \
    logindialog.ui \
    datamanager.ui
