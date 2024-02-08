QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ConsuppliersData.cpp \
    consuppliersdatafile.cpp \
    consuppliersdatatablemodel.cpp \
    consuppliersdialog.cpp \
    dialogsorting.cpp \
    main.cpp \
    mainwindow.cpp \
    qtabform.cpp

HEADERS += \
    ConsuppliersData.h \
    consuppliersdatafile.h \
    consuppliersdatatablemodel.h \
    consuppliersdialog.h \
    dialogsorting.h \
    mainwindow.h \
    qtabform.h

FORMS += \
    consuppliersdialog.ui \
    dialogsorting.ui \
    mainwindow.ui \
    qtabform.ui

TRANSLATIONS += \
    kurs_ru_RU.ts \
    kurs_en_US.ts \
    kurs_de_GE.ts

CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    kurs_de_GE.ts \
    kurs_de_GE.ts \
    kurs_en_US.ts \
    kurs_en_US.ts \
    kurs_ru_RU.ts \
    translation/kurs_de_GE.ts \
    translation/kurs_en_US.ts \
    translation/kurs_ru_RU.ts

