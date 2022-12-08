QT       += core gui sql charts
QT += printsupport network serialport widgets axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    arduino_parking.cpp \
    authentification.cpp \
    chat.cpp \
    connection.cpp \
    dialog.cpp \
    employe.cpp \
    evenement.cpp \
    event_workspace.cpp \
    main.cpp \
    mainwindow.cpp \
    stat_combo.cpp \
    stat_evenement.cpp

HEADERS += \
    arduino.h \
    arduino_parking.h \
    authentification.h \
    connection.h \
    dialog.h \
    employe.h \
    evenement.h \
    event_workspace.h \
    mainwindow.h \
    stat_combo.h \
    stat_evenement.h \
    webaxwidget.h

FORMS += \
    dialog.ui \
    event_workspace.ui \
    mainwindow.ui \
    stat_combo.ui \
    stat_evenement.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc