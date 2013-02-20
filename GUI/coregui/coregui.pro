#-------------------------------------------------
#
# Project created by QtCreator 2013-02-11T18:32:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = coregui
TEMPLATE = app


# making standard shared library extension
QMAKE_EXTENSION_SHLIB = so
#CONFIG  -= app_bundle
OBJECTS_DIR = obj
MOC_DIR = obj
#UI_DIR  = obj
#RCC_DIR = obj

SOURCES += \
    mainwindow/imode.cpp \
    mainwindow/main.cpp \
    mainwindow/mainwindow.cpp \
    mainwindow/welcomemode.cpp \
    Views/designercomponents.cpp \
    mainwindow/taskselectorwidget.cpp \
    utils/ba_fancytabbar.cpp \
    utils/ba_stylehelper.cpp \
    utils/rootcanvas.cpp \
    Models/SimulationDataModel.cpp \
    Views/InstrumentView.cpp \
    Views/FitView.cpp \
    Views/SampleView.cpp \
    Views/SimulationView.cpp \
    Views/WelcomeView.cpp

HEADERS  += \
    mainwindow/imode.h \
    mainwindow/mainwindow.h \
    mainwindow/welcomemode.h \
    Views/designercomponents.h \
    mainwindow/taskselectorwidget.h \
    utils/ba_fancytabbar.h \
    utils/ba_stylehelper.h \
    utils/rootcanvas.h \
    Models/SimulationDataModel.h \
    Models/SelectionListModel.h \
    Views/FitView.h \
    Views/InstrumentView.h \
    Views/SampleView.h \
    Views/SimulationView.h \
    Views/WelcomeView.h


INCLUDEPATH += $$PWD/mainwindow $$PWD/utils $$PWD/Views $$PWD/Models
LIBS += $$PWD/../../lib/libqt-manhattan-style.so
INCLUDEPATH += $$PWD/../externals/qt-manhattan-style
LIBS += $$PWD/../../lib/libQtRoot.so $$PWD/../../lib/libGQt.so
INCLUDEPATH += $$PWD/../externals/qt-root/inc
INCLUDEPATH += $$PWD/../../Core/Algorithms/inc \
    $$PWD/../../Core/Fitting/inc \
    $$PWD/../../Core/FormFactors/inc \
    $$PWD/../../Core/Geometry/inc \
    $$PWD/../../Core/Samples/inc \
    $$PWD/../../Core/Tools/inc

#include(/opt/local/include/root/rootcint.pri)
MYROOT = $$(ROOTSYS)
isEmpty(MYROOT) {
  message("Warning, ROOTSYS environment variable doesn't exist, trying to guess location")
  ROOT_CONFIG_FILE = root-config
  ROOT_CONFIG_FILE_LOCATIONS = /opt/local /usr/local /usr
  for(dir, ROOT_CONFIG_FILE_LOCATIONS): isEmpty(MYROOT): exists($${dir}/bin/$${ROOT_CONFIG_FILE}): MYROOT = $${dir}
  isEmpty(MYROOT): error("Can't find" $${ROOT_CONFIG_FILE} "in" $${ROOT_CONFIG_FILE_LOCATIONS})
  message("Probable ROOTSYS is" $${MYROOT})
}
!isEmpty(MYROOT) {
  !exists($${MYROOT}/bin/root-config): error("No config file "$${MYROOT}/bin/root-config)
  INCLUDEPATH += $$system($${MYROOT}/bin/root-config --incdir)
  #LIBS += -L$$system($${MYROOT}/bin/root-config --libdir ) -lGui -lCore -lCint -lRIO -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lMathMore -lMinuit2 -lGeom -lEve -lRGL -lThread -lpthread -lm -ldl
  #LIBS += -L$$system($${MYROOT}/bin/root-config --libdir ) -lGui -lCore -lCint -lRIO -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lMathMore -lMinuit2 -lGeom -lEve -lRGL -lThread -lpthread -lm -ldl
  LIBS += $$system($${MYROOT}/bin/root-config --glibs )
  MYROOTCINT = $${MYROOT}/bin/rootcint
}
