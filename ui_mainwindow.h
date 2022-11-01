/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableView *tableau;
    QLineEdit *recherche;
    QGroupBox *groupBox;
    QComboBox *client;
    QSpinBox *code;
    QLineEdit *nom_2;
    QPushButton *add;
    QPushButton *delete_2;
    QPushButton *update;
    QLabel *label;
    QLabel *nomlabel;
    QLabel *label_4;
    QLabel *label_6;
    QComboBox *emp;
    QLabel *label_7;
    QComboBox *salle;
    QLabel *label_3;
    QTextEdit *description;
    QComboBox *type;
    QDateEdit *dateEdit;
    QLabel *label_8;
    QLabel *label_5;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(255, 239, 220);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableau = new QTableView(centralwidget);
        tableau->setObjectName(QStringLiteral("tableau"));
        tableau->setGeometry(QRect(350, 61, 451, 421));
        tableau->setSortingEnabled(true);
        tableau->horizontalHeader()->setCascadingSectionResizes(true);
        tableau->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableau->horizontalHeader()->setStretchLastSection(false);
        recherche = new QLineEdit(centralwidget);
        recherche->setObjectName(QStringLiteral("recherche"));
        recherche->setGeometry(QRect(590, 20, 191, 24));
        recherche->setClearButtonEnabled(true);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 60, 321, 421));
        client = new QComboBox(groupBox);
        client->setObjectName(QStringLiteral("client"));
        client->setGeometry(QRect(110, 260, 191, 22));
        code = new QSpinBox(groupBox);
        code->setObjectName(QStringLiteral("code"));
        code->setEnabled(true);
        code->setGeometry(QRect(110, 20, 191, 22));
        code->setFrame(true);
        code->setButtonSymbols(QAbstractSpinBox::NoButtons);
        code->setKeyboardTracking(true);
        code->setMaximum(999999);
        nom_2 = new QLineEdit(groupBox);
        nom_2->setObjectName(QStringLiteral("nom_2"));
        nom_2->setGeometry(QRect(110, 60, 191, 20));
        add = new QPushButton(groupBox);
        add->setObjectName(QStringLiteral("add"));
        add->setGeometry(QRect(20, 380, 75, 23));
        delete_2 = new QPushButton(groupBox);
        delete_2->setObjectName(QStringLiteral("delete_2"));
        delete_2->setGeometry(QRect(230, 380, 75, 23));
        update = new QPushButton(groupBox);
        update->setObjectName(QStringLiteral("update"));
        update->setGeometry(QRect(130, 380, 75, 23));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 81, 16));
        nomlabel = new QLabel(groupBox);
        nomlabel->setObjectName(QStringLiteral("nomlabel"));
        nomlabel->setGeometry(QRect(20, 60, 71, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 260, 47, 14));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 300, 47, 14));
        emp = new QComboBox(groupBox);
        emp->setObjectName(QStringLiteral("emp"));
        emp->setGeometry(QRect(110, 300, 191, 22));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 340, 47, 14));
        salle = new QComboBox(groupBox);
        salle->setObjectName(QStringLiteral("salle"));
        salle->setGeometry(QRect(110, 340, 191, 22));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 100, 81, 16));
        description = new QTextEdit(groupBox);
        description->setObjectName(QStringLiteral("description"));
        description->setGeometry(QRect(110, 100, 191, 61));
        type = new QComboBox(groupBox);
        type->setObjectName(QStringLiteral("type"));
        type->setGeometry(QRect(110, 180, 191, 22));
        dateEdit = new QDateEdit(groupBox);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(110, 220, 191, 22));
        dateEdit->setCalendarPopup(true);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 180, 47, 14));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 230, 47, 14));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 20, 75, 23));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(471, 20, 111, 22));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(140, 20, 75, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        recherche->setPlaceholderText(QApplication::translate("MainWindow", "Recherche", Q_NULLPTR));
        groupBox->setTitle(QString());
        nom_2->setText(QApplication::translate("MainWindow", "kj", Q_NULLPTR));
        add->setText(QApplication::translate("MainWindow", "ADD", Q_NULLPTR));
        delete_2->setText(QApplication::translate("MainWindow", "DELETE", Q_NULLPTR));
        update->setText(QApplication::translate("MainWindow", "UPDATE", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Code", Q_NULLPTR));
        nomlabel->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "ID Client", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "ID Emp", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Salle", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Description", Q_NULLPTR));
        type->clear();
        type->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "sportif", Q_NULLPTR)
         << QApplication::translate("MainWindow", "culturel", Q_NULLPTR)
         << QApplication::translate("MainWindow", "marriage", Q_NULLPTR)
         << QApplication::translate("MainWindow", "congre", Q_NULLPTR)
        );
        label_8->setText(QApplication::translate("MainWindow", "Type", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Date", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Stat Type", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Tous", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Code", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Nom", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Description", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Type", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Date", Q_NULLPTR)
         << QApplication::translate("MainWindow", "ID_Client", Q_NULLPTR)
         << QApplication::translate("MainWindow", "ID_Emp", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Salle", Q_NULLPTR)
        );
        pushButton_2->setText(QApplication::translate("MainWindow", "pdf", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
