QT += core gui
QT += sql
QT += svg
#QT += widgets svg
QT += opengl
QT += xml
QT += serialport

QT       += core gui sql charts
QT += printsupport network serialport widgets axcontainer multimedia multimediawidgets

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
    arduino_fournisseur.cpp \
    arduino_parking.cpp \
    arduino_salle.cpp \
    authentification.cpp \
    chat.cpp \
    client.cpp \
    client_workspace.cpp \
    connection.cpp \
    dialog.cpp \
    employe.cpp \
    evenement.cpp \
    event_workspace.cpp \
    exportexcelobject.cpp \
    facture.cpp \
    fournisseur.cpp \
    fournisseur_workspace.cpp \
    image_salle.cpp \
    main.cpp \
    mainwindow.cpp \
    pie.cpp \
    piechartwidget.cpp \
    qcustomplot.cpp \
    qrcode_salle.cpp \
    qrcodegen_salle.cpp \
    rechercher_salle.cpp \
    regulateur_temperature_salle.cpp \
    salle.cpp \
    salle_workspace.cpp \
    smtp.cpp \
    smtp_fournisseur.cpp \
    stat_combo.cpp \
    stat_evenement.cpp \
    statistique.cpp \
    statistique_salle.cpp \
    trier_salle.cpp

HEADERS += \
    arduino.h \
    arduino_fournisseur.h \
    arduino_parking.h \
    arduino_salle.h \
    authentification.h \
    client.h \
    client_workspace.h \
    connection.h \
    date.h \
    dialog.h \
    employe.h \
    evenement.h \
    event_workspace.h \
    exportexcelobject.h \
    facture.h \
    fournisseur.h \
    fournisseur_workspace.h \
    image_salle.h \
    mainwindow.h \
    pie.h \
    piechartwidget.h \
    qcustomplot.h \
    qrcode_salle.h \
    qrcodegen_salle.h \
    regulateur_temperature_salle.h \
    salle.h \
    salle_workspace.h \
    smtp.h \
    smtp_fournisseur.h \
    stat_combo.h \
    stat_evenement.h \
    statistique.h \
    statistique_salle.h \
    webaxwidget.h

FORMS += \
    client_workspace.ui \
    dialog.ui \
    event_workspace.ui \
    fournisseur_workspace.ui \
    mainwindow.ui \
    pie.ui \
    piechartwidget.ui \
    regulateur_temperature_salle.ui \
    salle_workspace.ui \
    stat_combo.ui \
    stat_evenement.ui \
    statistique.ui \
    statistique_salle.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
