#-------------------------------------------------
#
# Project created by QtCreator 2015-10-13T11:02:49
#
#-------------------------------------------------

QT       += core gui
CONFIG += static
QMAKE_CXXFLAGS += -std=c++0x

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ffrk_abilities
TEMPLATE = app


SOURCES += main.cpp\
        ffrk_abilities.cpp \
    base/spell_parser.cpp

HEADERS  += ffrk_abilities.h \
    base/ability_base.h \
    base/orb_base.h \
    base/spells_base.h \
    base/spell_parser.h \
    ability_table_entry.h \
    base/orb_ranks.h \

FORMS    += ffrk_abilities.ui

DISTFILES += \
    black_magic/blm_list
