/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *setkodemodus;
    QPushButton *docode;
    QLabel *label_7;
    QLineEdit *targetfile;
    QLabel *label_3;
    QLabel *label_8;
    QLineEdit *kodiermodus;
    QLabel *label_5;
    QPushButton *preparesrcfile;
    QLabel *label;
    QLineEdit *srcblkdif;
    QLineEdit *srclnge;
    QLineEdit *showmaxrnd;
    QLabel *label_9;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *sizeofblockrest;
    QTextEdit *textEdit;
    QLineEdit *sizeofblocks;
    QPushButton *srcaus;
    QLabel *label_2;
    QLineEdit *quelldateiname;
    QLineEdit *sdatlen;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(986, 502);
        setkodemodus = new QPushButton(Dialog);
        setkodemodus->setObjectName(QString::fromUtf8("setkodemodus"));
        setkodemodus->setGeometry(QRect(50, 390, 161, 34));
        docode = new QPushButton(Dialog);
        docode->setObjectName(QString::fromUtf8("docode"));
        docode->setGeometry(QRect(390, 330, 88, 34));
        label_7 = new QLabel(Dialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(50, 340, 101, 18));
        targetfile = new QLineEdit(Dialog);
        targetfile->setObjectName(QString::fromUtf8("targetfile"));
        targetfile->setGeometry(QRect(192, 100, 271, 32));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 170, 101, 20));
        label_8 = new QLabel(Dialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(80, 100, 81, 18));
        kodiermodus = new QLineEdit(Dialog);
        kodiermodus->setObjectName(QString::fromUtf8("kodiermodus"));
        kodiermodus->setGeometry(QRect(180, 330, 113, 32));
        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 220, 71, 20));
        preparesrcfile = new QPushButton(Dialog);
        preparesrcfile->setObjectName(QString::fromUtf8("preparesrcfile"));
        preparesrcfile->setGeometry(QRect(240, 390, 111, 34));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(280, 170, 61, 18));
        srcblkdif = new QLineEdit(Dialog);
        srcblkdif->setObjectName(QString::fromUtf8("srcblkdif"));
        srcblkdif->setGeometry(QRect(200, 280, 101, 32));
        srclnge = new QLineEdit(Dialog);
        srclnge->setObjectName(QString::fromUtf8("srclnge"));
        srclnge->setGeometry(QRect(150, 160, 101, 32));
        showmaxrnd = new QLineEdit(Dialog);
        showmaxrnd->setObjectName(QString::fromUtf8("showmaxrnd"));
        showmaxrnd->setGeometry(QRect(400, 280, 91, 32));
        label_9 = new QLabel(Dialog);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(320, 290, 61, 18));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(290, 230, 51, 18));
        label_6 = new QLabel(Dialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 290, 151, 20));
        sizeofblockrest = new QLineEdit(Dialog);
        sizeofblockrest->setObjectName(QString::fromUtf8("sizeofblockrest"));
        sizeofblockrest->setGeometry(QRect(160, 220, 101, 32));
        textEdit = new QTextEdit(Dialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(520, 80, 421, 381));
        sizeofblocks = new QLineEdit(Dialog);
        sizeofblocks->setObjectName(QString::fromUtf8("sizeofblocks"));
        sizeofblocks->setGeometry(QRect(380, 230, 81, 32));
        srcaus = new QPushButton(Dialog);
        srcaus->setObjectName(QString::fromUtf8("srcaus"));
        srcaus->setGeometry(QRect(390, 390, 91, 34));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 70, 71, 18));
        quelldateiname = new QLineEdit(Dialog);
        quelldateiname->setObjectName(QString::fromUtf8("quelldateiname"));
        quelldateiname->setGeometry(QRect(190, 60, 271, 32));
        sdatlen = new QLineEdit(Dialog);
        sdatlen->setObjectName(QString::fromUtf8("sdatlen"));
        sdatlen->setGeometry(QRect(380, 160, 81, 32));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        setkodemodus->setText(QCoreApplication::translate("Dialog", "kodieren / dekodieren", nullptr));
        docode->setText(QCoreApplication::translate("Dialog", "do code", nullptr));
        label_7->setText(QCoreApplication::translate("Dialog", "Kodier-Modus:", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "length soucefile:", nullptr));
        label_8->setText(QCoreApplication::translate("Dialog", "Target-File:", nullptr));
        label_5->setText(QCoreApplication::translate("Dialog", "block-Rest:", nullptr));
        preparesrcfile->setText(QCoreApplication::translate("Dialog", "Prepare File", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Maxbits:", nullptr));
        label_9->setText(QCoreApplication::translate("Dialog", "toprange:", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "blocks:", nullptr));
        label_6->setText(QCoreApplication::translate("Dialog", "blockdifference in byte:", nullptr));
        srcaus->setText(QCoreApplication::translate("Dialog", "Beenden", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Sourcefile:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
