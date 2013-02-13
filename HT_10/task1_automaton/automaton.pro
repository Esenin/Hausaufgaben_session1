TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
    stateAutomaton.cpp \
    charLine.cpp \
    stringList.cpp

HEADERS += \
    stateAutomaton.h \
    charLine.h \
    stringList.h

OTHER_FILES += \
    rules.txt

