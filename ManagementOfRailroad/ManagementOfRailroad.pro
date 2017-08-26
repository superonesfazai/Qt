#-------------------------------------------------
#
# Project created by QtCreator 2015-06-26T13:46:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ManagementOfRailroad
TEMPLATE = app


SOURCES += main.cpp\
        logindialog.cpp \
    admindialog.cpp \
    userdialog.cpp \
    train.cpp \
    tourist.cpp \
    buyticketdialog.cpp \
    passenger.cpp \
    traininformation.cpp

HEADERS  += logindialog.h \
    admindialog.h \
    userdialog.h \
    train.h \
    tourist.h \
    buyticketdialog.h \
    passenger.h \
    traininformation.h

FORMS    += logindialog.ui \
    admindialog.ui \
    userdialog.ui \
    tourist.ui \
    buyticketdialog.ui \
    traininformation.ui

RESOURCES += \
    pictures.qrc
