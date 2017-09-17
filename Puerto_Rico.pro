#-------------------------------------------------
#
# Project created by QtCreator 2015-04-11T12:52:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++11

TARGET = Puerto_Rico
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    pelimalli.cpp \
    Gui/guirakennus.cpp \
    Gui/guiPlantaasi.cpp \
    presenter.cpp \
    pelaaja.cpp \
    Rakennukset/pieniindigo.cpp \
    Rakennukset/suuriindigo.cpp \
    Rakennukset/pienisokeri.cpp \
    Rakennukset/suurisokeri.cpp \
    Rakennukset/tupakka.cpp \
    Rakennukset/kahvi.cpp \
    Rakennukset/pienitori.cpp \
    Rakennukset/hacienda.cpp \
    Rakennukset/rakennusvaja.cpp \
    Rakennukset/pienivarasto.cpp \
    Rakennukset/majatalo.cpp \
    Rakennukset/toimisto.cpp \
    Rakennukset/suuritori.cpp \
    Rakennukset/suurivarasto.cpp \
    Rakennukset/tehdas.cpp \
    Rakennukset/yliopisto.cpp \
    Rakennukset/satama.cpp \
    Rakennukset/laituri.cpp \
    Rakennukset/linnoitus.cpp \
    Rakennukset/kaupungintalo.cpp \
    Rakennukset/tullikamari.cpp \
    Rakennukset/kartano.cpp \
    Rakennukset/kiltatalo.cpp \
    Gui/bonusresurssidialogi.cpp \
    Gui/kauppiasdialogi.cpp \
    Gui/kapteenidialogi.cpp

HEADERS  += mainwindow.h \
    pelimalli.h \
    Gui/guirakennus.h \
    Gui/guiPlantaasi.h \
    presenter.h \
    consts.h \
    PresenterAPI.h \
    IkkunaAPI.h \
    pelaaja.h \
    rakennus.h \
    Rakennukset/pieniindigo.h \
    Rakennukset/suuriindigo.h \
    Rakennukset/pienisokeri.h \
    Rakennukset/suurisokeri.h \
    Rakennukset/tupakka.h \
    Rakennukset/kahvi.h \
    Rakennukset/pienitori.h \
    Rakennukset/hacienda.h \
    Rakennukset/rakennusvaja.h \
    Rakennukset/pienivarasto.h \
    Rakennukset/majatalo.h \
    Rakennukset/toimisto.h \
    Rakennukset/suuritori.h \
    Rakennukset/suurivarasto.h \
    Rakennukset/tehdas.h \
    Rakennukset/yliopisto.h \
    Rakennukset/satama.h \
    Rakennukset/laituri.h \
    Rakennukset/linnoitus.h \
    Rakennukset/kaupungintalo.h \
    Rakennukset/tullikamari.h \
    Rakennukset/kartano.h \
    Rakennukset/kiltatalo.h \
    Gui/bonusresurssidialogi.h \
    Gui/kauppiasdialogi.h \
    Gui/kapteenidialogi.h

FORMS    += Gui/mainwindow.ui \
         Gui/guirakennus.ui \
    Gui/guiPlantaasi.ui \
    Gui/bonusresurssidialogi.ui \
    Gui/kauppiasdialogi.ui \
    Gui/kapteenidialogi.ui

RESOURCES += \
    Gui/kuvat.qrc
