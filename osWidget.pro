#-------------------------------------------------
#
# Project created by QtCreator 2014-06-19T10:25:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION,5)
{
    QT += widgets
}

TARGET = osWidget

TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    painters/performancepainter.cpp \
    painters/graphpainter.cpp \
    painters/painterutils.cpp \
    dataQuery/dataquery.cpp \
    dataQuery/cpudataquery.cpp \
    painters/barspainter.cpp \
    painters/graphmulticolorpainter.cpp \
    widgets/cpuwidget.cpp \
    widgets/performancewidget.cpp \
    dataQuery/queryresource.cpp \
    widgets/ramwidget.cpp \
    dataQuery/ramdataquery.cpp

HEADERS  += mainwindow.h \
    painterutils.h \
    performancewidget.h \
    painters/performancepainter.h \
    painters/graphpainter.h \
    painters/painterutils.h \
    dataQuery/dataquery.h \
    dataQuery/cpudataquery.h \
    painters/barspainter.h \
    painters/graphmulticolorpainter.h \
    widgets/cpuwidget.h \
    widgets/performancewidget.h \
    dataQuery/queryresource.h \
    widgets/ramwidget.h \
    dataQuery/ramdataquery.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    mainpage.dox
