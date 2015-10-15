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
QMAKE_EXTRA_TARGETS += ability_selector
TEMPLATE = app


SOURCES += main.cpp\
        ffrk_abilities.cpp \
    base/spell_parser.cpp \
    base/orb_statistics_parser.cpp \
    ability_selector.cpp

HEADERS  += ffrk_abilities.h \
    base/ability_base.h \
    base/orb_base.h \
    base/spell_parser.h \
    base/orb_ranks.h \
    base/orb_statistics_parser.h \
    ability_selector.h \
    ability_list_item.h \
    ability_table_item.h

FORMS    += ffrk_abilities.ui \
    ability_selector.ui
