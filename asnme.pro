#-------------------------------------------------
#
# Project created by QtCreator 2011-03-27T02:01:35
#
#-------------------------------------------------

QT       += core gui

TARGET = asnme
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mongoexplorermodel.cpp \
    preferences.cpp \
    serverdialog.cpp \
    mongoserver.cpp

HEADERS  += mainwindow.h \
    mongoexplorermodel.h \
    preferences.h \
    serverdialog.h \
    mongoserver.h

FORMS    += mainwindow.ui \
    serverdialog.ui

# Depending on your system you might not need the -mt suffix for the boos libraries so experiment.
LIBS += -lmongoclient \
    -lboost_thread-mt \
    -lboost_filesystem-mt \
    -lboost_program_options-mt

OTHER_FILES += \
    README.md \
    LICENSE \
    icons/server_add.png \
    icons/server_connect.png

RESOURCES += \
    resources.qrc
