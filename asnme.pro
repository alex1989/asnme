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
    src/widgets/serverdialog.cpp \
    mongoserver.cpp \
    mongoexplorerview.cpp \
    mongoexploreraction.cpp \
    mongodatabase.cpp \
    mongocollection.cpp

HEADERS  += mainwindow.h \
    mongoexplorermodel.h \
    preferences.h \
    src/widgets/serverdialog.h \
    mongoserver.h \
    mongoexplorerview.h \
    mongoexploreraction.h \
    mongodatabase.h \
    mongocollection.h

FORMS    += mainwindow.ui \
    ui/serverdialog.ui

# Depending on your system you might not need the -mt suffix for the boos libraries so experiment.
LIBS += -lmongoclient \
    -lboost_thread-mt \
    -lboost_filesystem-mt \
    -lboost_program_options-mt

OTHER_FILES += \
    README.md \
    LICENSE \
    Doxyfile \
    resources/icons/table.png \
    resources/icons/server.png \
    resources/icons/server_go.png \
    resources/icons/server_delete.png \
    resources/icons/server_connect.png \
    resources/icons/server_add.png \
    resources/icons/database.png

RESOURCES += \
    resources/resources.qrc
