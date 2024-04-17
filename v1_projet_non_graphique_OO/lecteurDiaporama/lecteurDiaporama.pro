TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ImageDansDiaporama.cpp \
        diaporama.cpp \
        image.cpp \
        lecteur.cpp \
        main.cpp \
        sousProgrammes.cpp

HEADERS += \
    ImageDansDiaporama.h \
    image.h \
    lecteur.h \
    sousProgrammes.h \
    typeDiaporama.h
