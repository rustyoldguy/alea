//mainwindow.h von Alea
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ui_mainwindow.h"
#include  <stdio.h> // wegen fopen
#include <QMenuBar>
#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>
#include "handledata.h"

#define MAXBITLIMIT 135000

extern QString tarfilename;
extern QString keyfilename;
extern QString Nachricht;

extern char zieldatei[600];
extern long orginaldateilaenge;

QString chartoqstring(QByteArray quelle);

class Alea : public QMainWindow, public Ui::MainWindow
{
  Q_OBJECT
  public:
  Alea (QMainWindow *parent = nullptr);
 ~Alea();
  QString dummy;
  QString MaxRandom;
  //int initrandom;
  int lowerlimit;
  int upperlimit;
  long sollsumme; // int
  long istsumme;  // int
  int testergebnis;
  QString sourcefilename;
  QString tarfilename;
  QString keyfilename;
  unsigned char intteile[4];
  QString sdummy;
  QString Nachricht;
  // Werte für die Sourcedatei
  long sourcelength;
  long bloecke;
  long blockrest;
  long blockdifferenz;
  int  Maxbitlimit(void);
  int toprange;
  int initrandom;
  int srcdatflag;
  long orginaldateilaenge;

  unsigned int schluessel[MAXBITLIMIT];
  unsigned int wuerfel[MAXBITLIMIT];

  QString srcfilename;
  long srcdatlen;
  long dateilaenge;
  long keydatlen;
  QString Teila;
  QString Teilb;
  QString Teilc;
  int maxrnd;
  long origdatlen;
  char quelldatei[600];
  char slusseldatei[600];
  char zieldatei[600];

private:
  Ui::MainWindow *ui;
  QMessageBox *msgBox = new QMessageBox(this);

private slots:
  void about();
  void MakeRandoms();
  int  getrand (int ug, int og);
  void initarreale(void);
  void rejumblekey(void);
  void kuerzearreal(int zuza, int og,  int stelle);
  void generateRandoms(void);
  void testeareal(void);
  int  schreibedatei(void);
  void intzuchar(int zuza);
  int  charzuint(unsigned char intteile[4]);
  long getdatlen(void);
  int  lesedateiein(void);
  void getkeyfilename(void);
  void setKeyDatname(void);
  void ReadKeyfile(void);
  void getSFileValues(void);
  void zeigefenster(void);
  void GetTargetname(void);
  int keyDateitest(void);
  int GetOrgDatlen(void);
  int fgetDWORD(std::fstream *datei); //(FILE *fz);



};

namespace Ui {
class Alea;
}


#endif // MAINWINDOW_H
