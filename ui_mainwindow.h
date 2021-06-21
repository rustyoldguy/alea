/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *finito;
    QComboBox *Maxbits;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QPushButton *GenerateRandoms;
    QLineEdit *ist;
    QLabel *label_3;
    QLineEdit *soll;
    QLabel *label_4;
    QLineEdit *kdatname;
    QLabel *label_5;
    QPushButton *savekey;
    QPushButton *loadkey;
    QLineEdit *origfilelen;
    QLabel *label_6;
    QLineEdit *showtoprange;
    QLabel *label_7;
    QTextEdit *infoEdit;
    QPushButton *jumblekey;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(976, 459);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        finito = new QPushButton(centralWidget);
        finito->setObjectName(QString::fromUtf8("finito"));
        finito->setGeometry(QRect(410, 300, 51, 34));
        Maxbits = new QComboBox(centralWidget);
        Maxbits->setObjectName(QString::fromUtf8("Maxbits"));
        Maxbits->setGeometry(QRect(380, 230, 81, 32));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(360, 100, 101, 32));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(300, 240, 61, 18));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(250, 100, 81, 18));
        GenerateRandoms = new QPushButton(centralWidget);
        GenerateRandoms->setObjectName(QString::fromUtf8("GenerateRandoms"));
        GenerateRandoms->setGeometry(QRect(300, 300, 88, 34));
        ist = new QLineEdit(centralWidget);
        ist->setObjectName(QString::fromUtf8("ist"));
        ist->setGeometry(QRect(380, 40, 121, 32));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(430, 20, 31, 18));
        soll = new QLineEdit(centralWidget);
        soll->setObjectName(QString::fromUtf8("soll"));
        soll->setGeometry(QRect(240, 40, 121, 32));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(280, 20, 59, 18));
        kdatname = new QLineEdit(centralWidget);
        kdatname->setObjectName(QString::fromUtf8("kdatname"));
        kdatname->setGeometry(QRect(20, 40, 201, 32));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 20, 61, 18));
        savekey = new QPushButton(centralWidget);
        savekey->setObjectName(QString::fromUtf8("savekey"));
        savekey->setGeometry(QRect(180, 300, 88, 34));
        loadkey = new QPushButton(centralWidget);
        loadkey->setObjectName(QString::fromUtf8("loadkey"));
        loadkey->setGeometry(QRect(60, 300, 88, 34));
        origfilelen = new QLineEdit(centralWidget);
        origfilelen->setObjectName(QString::fromUtf8("origfilelen"));
        origfilelen->setGeometry(QRect(20, 150, 191, 32));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 120, 141, 18));
        showtoprange = new QLineEdit(centralWidget);
        showtoprange->setObjectName(QString::fromUtf8("showtoprange"));
        showtoprange->setGeometry(QRect(350, 150, 113, 32));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(250, 160, 71, 18));
        infoEdit = new QTextEdit(centralWidget);
        infoEdit->setObjectName(QString::fromUtf8("infoEdit"));
        infoEdit->setGeometry(QRect(530, 20, 391, 321));
        jumblekey = new QPushButton(centralWidget);
        jumblekey->setObjectName(QString::fromUtf8("jumblekey"));
        jumblekey->setGeometry(QRect(70, 230, 161, 34));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 976, 30));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        finito->setText(QCoreApplication::translate("MainWindow", "exit", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Maxbits:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "initrandom:", nullptr));
        GenerateRandoms->setText(QCoreApplication::translate("MainWindow", "getrandom", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "ist", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "soll:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Keyfile:", nullptr));
        savekey->setText(QCoreApplication::translate("MainWindow", "save key", nullptr));
        loadkey->setText(QCoreApplication::translate("MainWindow", "load key", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "original length of File:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "toprange:", nullptr));
        jumblekey->setText(QCoreApplication::translate("MainWindow", "Rejumble Key", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
