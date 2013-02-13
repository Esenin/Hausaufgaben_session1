TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
    parser.cpp \
    charLine.cpp \
    stateAutomaton.cpp \
    stringList.cpp

HEADERS += \
    parser.h \
    charLine.h \
    stateAutomaton.h \
    stringList.h

OTHER_FILES += \
    rules.txt

