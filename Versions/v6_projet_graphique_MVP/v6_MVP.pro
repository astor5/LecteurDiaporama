QT       += core gui
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ImageDansDiaporama.cpp \
    choixdiaporama.cpp \
    database.cpp \
    diaporama.cpp \
    image.cpp \
    main.cpp \
    lecteurvue.cpp \
    modele.cpp \
    presentation.cpp \
    vitessedefilement.cpp

HEADERS += \
    ImageDansDiaporama.h \
    choixdiaporama.h \
    database.h \
    diaporama.h \
    image.h \
    lecteurvue.h \
    modele.h \
    presentation.h \
    vitessedefilement.h

FORMS += \
    choixdiaporama.ui \
    lecteurvue.ui \
    vitessedefilement.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../cartesDisney/images.qrc
