#-------------------------------------------------
#
# Project created by QtCreator 2015-10-13T11:02:49
#
#-------------------------------------------------

QT       += core gui
CONFIG   += static
#win32-msvc* {
#    QMAKE_CXXFLAGS += -std=c++11
#}
#g++* {
#    QMAKE_CXXFLAGS += -std=c++0x
#}

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ffrk_abilities
QMAKE_EXTRA_TARGETS += ability_selector \
                        orb_stash_table
TEMPLATE = app


SOURCES += main.cpp\
        ffrk_abilities.cpp \
    base/spell_parser.cpp \
    base/orb_statistics_parser.cpp \
    ability_selector.cpp \
    orb_stash_table.cpp

HEADERS  += ffrk_abilities.h \
    ability_selector.h \
    ability_list_item.h \
    ability_table_item.h \
    orb_stash_table.h \
    base/AbilityBase.h \
    base/OrbBase.h \
    base/OrbRanks.h \
    base/OrbStatisticsParser.h \
    base/SpellParser.h

FORMS    += ffrk_abilities.ui \
    ability_selector.ui \
    orb_stash_table.ui
