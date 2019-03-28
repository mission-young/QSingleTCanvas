#-------------------------------------------------
#
# Project created by QtCreator 2016-12-13T19:19:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QSingleTCanvas
TEMPLATE = app

INCLUDEPATH += $(ROOTSYS)/include

LIBS += -L$(ROOTSYS)/lib -lCore -lImt -lRIO -lNet -lHist -lGraf \
    -lGraf3d -lGpad -lTree -lTreePlayer -lRint -lPostscript -lMatrix \
    -lPhysics -lMathCore -lThread -lMultiProc -pthread -lm -ldl -rdynamic

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
