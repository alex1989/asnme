#-------------------------------------------------
#
# Project created by QtCreator 2011-03-27T02:01:35
#
#-------------------------------------------------

QT       += core gui

TARGET = asnme
TEMPLATE = app


SOURCES += src/main.cpp\
        src/widgets/mainwindow.cpp \
        src/mongo-model/mongoexplorermodel.cpp \
        preferences.cpp \
        src/widgets/serverdialog.cpp \
        src/mongo-model/mongoserver.cpp \
        src/widgets/mongoexplorerview.cpp \
        mongoexploreraction.cpp \
        src/mongo-model/mongodatabase.cpp \
        src/mongo-model/mongocollection.cpp

HEADERS  += src/widgets/mainwindow.h \
        src/mongo-model/mongoexplorermodel.h \
        preferences.h \
        src/widgets/serverdialog.h \
        src/mongo-model/mongoserver.h \
        src/widgets/mongoexplorerview.h \
        mongoexploreraction.h \
        src/mongo-model/mongodatabase.h \
        src/mongo-model/mongocollection.h

FORMS    += ui/mainwindow.ui \
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
