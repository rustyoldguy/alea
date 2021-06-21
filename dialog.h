#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QByteArray>
#include <qmessagebox.h>
#include "mainwindow.h"
#include <unistd.h>
#include <fstream>


#define MAXBITLIMIT 135000

void putint( int letter, std::ofstream *datei);

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    QString dummystring;
    int intdummy;
    long dummy;
    int kodieren;  //  wenn kodieren ==1 dann Dekodiermodus, wenn 0 dann Kodiermodus
    long difbytes;
    unsigned char satzgecodet[66000];
    unsigned char satzteil[66000];
    int fehlbytes[66000];

    int toprange;
    int initrandom;
    long blockdifferenz;
    long srcdatlen;
    long dateilaenge;
    long bloecke;
    long blockrest;
    long keydatlen;
    QString srcfilename;
    QString Teila;
    QString Teilb;
    QString Teilc;
    QString tarfilename;
    QString keyfilename;
    QString Nachricht;
    int maxrnd;
    long origdatlen;
    char quelldatei[600];
    char slusseldatei[600];
    char zieldatei[600];
    int slei;
    int srcdatflag;
    long orginaldateilaenge;

    unsigned int schluessel[MAXBITLIMIT];
    unsigned int wuerfel[MAXBITLIMIT];

private:
    Ui::Dialog *ui;
    QMessageBox *WmsgBox = new QMessageBox(this);

private slots:
     int loadSRCDatei(void);
     void Setkodiermodus(void);
     int getrand(int min, int max);
     int GenRandomByts(void);
     void PrepareFile(void);
     int SaveOrgDatlen(unsigned long srcdatlen);
       int fputDWORD(unsigned int letter, std::ofstream *datei);
     int SetDifBytesInFile(void);
     void NewsBox(QString Newstext);
     void Koden(void);
     long srcgetdatlen(void);
     void initglobvariable(QWidget *parent);

};

#endif // DIALOG_H
