#-------------------------------------------------
#
# Tzura - A super primitive document layout analyzer for detection of the Gmara's Tzurat Hadaf
#
# Author: Moshe Wagner. <moshe.wagner@gmail.com>
#
#-------------------------------------------------

TARGET = Tzura
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tzuraimage.cpp \
    expandingsquare.cpp \
    imagearray.cpp \
    help.cpp

HEADERS  += mainwindow.h \
    tzuraimage.h \
    expandingsquare.h \
    imagearray.h \
    help.h

FORMS    += mainwindow.ui \
    help.ui

RESOURCES += res.qrc
