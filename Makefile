#############################################################################
# Makefile for building: Tzura
# Generated by qmake (2.01a) (Qt 4.7.0) on: Fri May 13 13:49:54 2011
# Project:  Tzura.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ -unix -o Makefile Tzura.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		tzuraimage.cpp \
		expandingsquare.cpp \
		imagearray.cpp \
		help.cpp moc_mainwindow.cpp \
		moc_tzuraimage.cpp \
		moc_imagearray.cpp \
		moc_help.cpp \
		qrc_res.cpp
OBJECTS       = main.o \
		mainwindow.o \
		tzuraimage.o \
		expandingsquare.o \
		imagearray.o \
		help.o \
		moc_mainwindow.o \
		moc_tzuraimage.o \
		moc_imagearray.o \
		moc_help.o \
		qrc_res.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		Tzura.pro
QMAKE_TARGET  = Tzura
DESTDIR       = 
TARGET        = Tzura

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h ui_help.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: Tzura.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix -o Makefile Tzura.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix -o Makefile Tzura.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/Tzura1.0.0 || $(MKDIR) .tmp/Tzura1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/Tzura1.0.0/ && $(COPY_FILE) --parents mainwindow.h tzuraimage.h expandingsquare.h imagearray.h help.h .tmp/Tzura1.0.0/ && $(COPY_FILE) --parents res.qrc .tmp/Tzura1.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp tzuraimage.cpp expandingsquare.cpp imagearray.cpp help.cpp .tmp/Tzura1.0.0/ && $(COPY_FILE) --parents mainwindow.ui help.ui .tmp/Tzura1.0.0/ && (cd `dirname .tmp/Tzura1.0.0` && $(TAR) Tzura1.0.0.tar Tzura1.0.0 && $(COMPRESS) Tzura1.0.0.tar) && $(MOVE) `dirname .tmp/Tzura1.0.0`/Tzura1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/Tzura1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindow.cpp moc_tzuraimage.cpp moc_imagearray.cpp moc_help.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_tzuraimage.cpp moc_imagearray.cpp moc_help.cpp
moc_mainwindow.cpp: tzuraimage.h \
		expandingsquare.h \
		imagearray.h \
		mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_tzuraimage.cpp: expandingsquare.h \
		tzuraimage.h \
		imagearray.h \
		tzuraimage.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) tzuraimage.h -o moc_tzuraimage.cpp

moc_imagearray.cpp: imagearray.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) imagearray.h -o moc_imagearray.cpp

moc_help.cpp: help.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) help.h -o moc_help.cpp

compiler_rcc_make_all: qrc_res.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_res.cpp
qrc_res.cpp: res.qrc \
		Icons/next.png \
		Icons/button_accept.png \
		Icons/White.png \
		Icons/Black.png \
		Icons/cancel.png \
		Icons/previous.png
	/usr/bin/rcc -name res res.qrc -o qrc_res.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h ui_help.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h ui_help.h
ui_mainwindow.h: mainwindow.ui
	/usr/bin/uic-qt4 mainwindow.ui -o ui_mainwindow.h

ui_help.h: help.ui
	/usr/bin/uic-qt4 help.ui -o ui_help.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h \
		tzuraimage.h \
		expandingsquare.h \
		imagearray.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		tzuraimage.h \
		expandingsquare.h \
		imagearray.h \
		ui_mainwindow.h \
		help.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

tzuraimage.o: tzuraimage.cpp tzuraimage.h \
		expandingsquare.h \
		imagearray.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tzuraimage.o tzuraimage.cpp

expandingsquare.o: expandingsquare.cpp expandingsquare.h \
		tzuraimage.h \
		imagearray.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o expandingsquare.o expandingsquare.cpp

imagearray.o: imagearray.cpp imagearray.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o imagearray.o imagearray.cpp

help.o: help.cpp help.h \
		ui_help.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o help.o help.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_tzuraimage.o: moc_tzuraimage.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_tzuraimage.o moc_tzuraimage.cpp

moc_imagearray.o: moc_imagearray.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_imagearray.o moc_imagearray.cpp

moc_help.o: moc_help.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_help.o moc_help.cpp

qrc_res.o: qrc_res.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_res.o qrc_res.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

