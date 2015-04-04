#-------------------------------------------------
#
# Project created by QtCreator 2015-04-03T23:46:40
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TiasProject
TEMPLATE = app


SOURCES += main.cpp\
        clientsocket.cpp \
    dialogmakanan.cpp \
    daftarminuman.cpp

HEADERS  += clientsocket.h \
    dialogmakanan.h \
    daftarminuman.h

FORMS    += clientsocket.ui \
    dialogmakanan.ui \
    daftarminuman.ui
