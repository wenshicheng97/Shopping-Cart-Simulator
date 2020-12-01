#-------------------------------------------------
#
# Project created by QtCreator 2018-04-14T17:17:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    loaddata.cpp \
    pet.cpp \
    bundle.cpp \
    addbutton.cpp \
    cartdialog.cpp \
    cartbutton.cpp \
    deletebutton.cpp \
    checkout.cpp

HEADERS += \
        mainwindow.h \
    loaddata.h \
    visitor.h \
    pet.h \
    bundle.h \
    builder.h \
    bubblesort.h \
    dog.h \
    cat.h \
    bird.h \
    fish.h \
    petdatabasesortable.h \
    petdatabasesortbyprice.h \
    bubblesortincreasing.h \
    petdatabasesearchablesortbyname.h \
    binarysearch.h \
    petlistbuilder.h \
    totalpricevisitor.h \
    petlistparser.h \
    bundlelistparser.h \
    addbutton.h \
    cartdialog.h \
    cartbutton.h \
    deletebutton.h \
    checkout.h

FORMS += \
        mainwindow.ui \
    cartdialog.ui
