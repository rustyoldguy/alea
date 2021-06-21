// mainwindow.cpp von Alea3
// Alea::Alea(QMainWindow *parent) : QMainWindow(parent), lowerlimit(0), upperlimit(32) // initrandom(0), lowerlimit(0), upperlimit(32)
// Alea::~Alea()
// void Alea::ReadKeyfile(void)
//  int Alea::keyDateitest(void)
// void Alea::zeigefenster(void)
// void Alea::getSFileValues(void)
// void Alea::MakeRandoms(void)
// void Alea::about() ......300
//  int Alea::getrand(int min, int max)
// void Alea::initarreale(void)
// void Alea::rejumblekey(void)
// void Alea::kuerzearreal(int zuza, int og,  int stelle)
// void Alea::generateRandoms(void)
// void Alea::testeareal(void)
// ab ca. Zeile 400
//  int Alea::schreibedatei(void)
//  int getint(std::fstream *datei)
// void putint(std::ofstream *datei, int letter)
// char inttochar(int letter)
//  int Alea::lesedateiein(void)
// ab ca Zeile 550
//  int Alea::Maxbitlimit(void)
// SourceFile::SourceFile(class Alea& talar, QMainWindow *parent) : QMainWindow(parent), ui(new Ui::SourceFile)
//  int SourceFile::getrand(int min, int max)....ca 620
//  int SourceFile::GenRandomByts(void)
// void SourceFile::PrepareFile(void)
//  int SourceFile::SaveOrgDatlen(unsigned long srcdatlen)
// void putint( int letter, std::ofstream *datei)
//  int SourceFile::SetDifBytesInFile(void)
//  int Alea::GetOrgDatlen(void) // long (*datlen))
//  int Alea::fgetDWORD(FILE *fz)......ca 840
//---------------------------------------Ende Inhaltsverzeichnis--------------------------------------------------------
#include <time.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qstring.h>
#include <QListView>
#include <fcntl.h>      // wegen open
#include <errno.h>      // wegen errno
#include <unistd.h>     // wegen close
//#include <dos_fcntl.h>  // wegen BINARY
#include <QTextEdit>
#include "dialog.h"
#include "handledata.h"

//globale Variablen zum Datenaustausch
//unsigned int zuzaar[MAXBITLIMIT];
//unsigned int *zuzaar = new unsigned int[MAXBITLIMIT];
//unsigned int *schluessel = new unsigned int[MAXBITLIMIT];
//unsigned int *wuerfel = new unsigned int[MAXBITLIMIT];


Alea::Alea(QMainWindow *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
   setupUi(this);
   this->setWindowTitle("Alea V 0.71 Beta");
   this->move(150,100); //Setzt die Widget-Ausgabeposition

   dateilaenge = 0;
   srcdatlen = 0;
   blockrest = 0;
   origdatlen = 0;
   lowerlimit = 0;
   upperlimit = 32;
   initrandom = 0;
   keydatlen = 0;
   srcdatflag = 0;
   toprange = 0;
   QMenuBar *fimen = new QMenuBar(this);
   setMenuBar(fimen);


   QAction *getkeydatname = new QAction("Load Key_File", fimen);
   QAction *setkeydatname = new QAction("Save Key_File", fimen);
   QAction *sourceinfo    = new QAction("Source Info",   fimen);
   QAction *tarname       = new QAction("Targetname",   fimen);
   QAction *newa = new QAction("&Autor", fimen);
   fimen->addAction(getkeydatname);
   fimen->addAction(setkeydatname);
   fimen->addAction(newa);
   fimen->addAction(sourceinfo);
   fimen->addAction(tarname);

   Maxbits->addItem("64");
   Maxbits->addItem("128");
   Maxbits->addItem("256");
   Maxbits->addItem("512");
   Maxbits->addItem("1024");
   Maxbits->addItem("2048");
   Maxbits->addItem("4096");
   Maxbits->addItem("8192");
   Maxbits->addItem("16384");
   Maxbits->addItem("32768");
   Maxbits->addItem("65536");
   Maxbits->addItem("131072");

   dummy = QString::number(initrandom);
   lineEdit -> setText(dummy);

   dummy = Maxbits->currentText(); // liest Wert aus Box
   toprange= dummy.toInt();         // String zu eingestellten int-Wert
   // toprange = maxrnd;              // Kopiere Einstellung nach toprange
   showtoprange -> setText(dummy);


   connect(sourceinfo,      SIGNAL(triggered()), this, SLOT (zeigefenster()));
   connect(tarname,         SIGNAL(triggered()), this, SLOT (GetTargetname()));
   connect(newa,            SIGNAL(triggered()), this, SLOT(about()));
   connect(setkeydatname,   SIGNAL(triggered()), this, SLOT(setKeyDatname()));
   connect(getkeydatname,   SIGNAL(triggered()), this, SLOT(getkeyfilename()));
   connect(loadkey,         SIGNAL(clicked()),   this, SLOT(ReadKeyfile() ) );
   connect(savekey,         SIGNAL(clicked()),   this, SLOT(schreibedatei() ) );
   connect(GenerateRandoms, SIGNAL(clicked()),   this, SLOT(MakeRandoms() ) );
   connect(jumblekey,       SIGNAL(clicked()),   this, SLOT(rejumblekey() ) );
   connect(finito,          SIGNAL(clicked()),   qApp, SLOT(quit() ) );
}

Alea::~Alea()
{
 delete msgBox;
 //delete zuzaar;
 //delete schluessel;
 //delete wuerfel;

 //zuzaar = 0;
 //schluessel = 0;
 //wuerfel = 0;

}

void Alea::ReadKeyfile(void)
{
 keydatlen = getdatlen();            // Stellt die Länge der Schlüsseldatei fest
 toprange = keydatlen / 4;           // Errechnet die Schlüssellänge und speichert sie in toprange

 toprange = keyDateitest();          // Testet die key-Datei ob diese schon benutzt wurde und welche Schlüsseltiefe benutzt wurde
 //maxrnd = toprange;                  // Wenn Schlüsseldatei eingelesen wird, toprande nach maxrnd kopieren

 dummy = QString::number(toprange);
 showtoprange->setText(dummy);

 lesedateiein();

 dummy = QString::number(toprange);
 lineEdit->setText(dummy);

 testeareal();
 dummy = QString::number(sollsumme);
 soll->setText(dummy);

 dummy = QString::number(istsumme);
 ist->setText(dummy);
 QMessageBox::about( this, "Key-File", "Schluesseldatei wurde geladen");
}


//Testet die key-Datei ob diese schon benutzt wurde und welche Schlüsseltiefe benutzt wurde
int Alea::keyDateitest(void)
{
  int slei;
    long keyfiletest[14] = {131072, 65536, 32768, 16384, 8192, 4096, 2048, 1024, 512, 256, 128, 64, 32, 16};

    //QMessageBox *msgBox = new QMessageBox(this);


    //-------------cout << "Teste Schlüsseldatei mit " << dateilaenge << " Bytes" << endl;
    Teila = QString("Teste Schluesseldatei %1\n").arg(keyfilename);
    Teilb = QString(" mit %1 Bytes Dateilaenge\n").arg(keydatlen);
    Nachricht = Teila + Teilb;
    //QMessageBox::about( this, "Key-File", Nachricht);
    infoEdit->append("Key-File:");
    infoEdit->append(Nachricht);
    dateilaenge = keydatlen;

   // Stelle fest ob Dateilänge abgespeichert wurde und welche Schlüsseltiefe benutzt wurde
   for (slei = 0; slei < 14; slei++)
    {
    if ((keydatlen - 4) == (keyfiletest[slei] * 4))
     {
       toprange = (int)((dateilaenge -4)/ 4);
       dummy = GetOrgDatlen();
       QMessageBox::about( this, "Datei wurde bereits benutzt:",
                                 "Schluesseldatei mit Orginaldateilaenge!");
       infoEdit->append("Datei wurde bereits benutzt: Schluesseldatei mit Orginaldateilaenge!");
       break;
     }
     else if (dateilaenge == (keyfiletest[slei] * 4))
      {
       toprange = (int)((dateilaenge)/ 4);
       QMessageBox::about( this, "Datei-Info:" ,
                                 "Schluesseldatei noch ohne Datei-Laengen-Anhang");
       infoEdit->append("Schluesseldatei noch ohne Datei-Laengen-Anhang");
       break;
      }
     }

   //toprange = maxrnd;
   Nachricht = QString(" bei else: Groesse toprange: %1").arg(toprange);
   //QMessageBox::about( this, "Schluessellaenge:", Nachricht);
   infoEdit->append("Schluessellaenge:");
   infoEdit->append(Nachricht);

 return toprange;
}

void Alea::zeigefenster(void)
{
   srcfilename = QFileDialog::getOpenFileName(this, tr("Open File..."),
                                                     QString(), tr("All Files (*);;HTML-Files (*.htm *.html)"));

 //Dialog *fensterb = new Dialog(this);
  //  fensterb->setModal(true);
  // fensterb->exec();

 if (!tarfilename.isEmpty())
  {
   if (!srcfilename.isEmpty())
    {
     //erge = srcfilename.toAscii().data();  // kopiert einen QString in einen ASCII-String
     Dialog *sf = new Dialog(this);
     getCHname(srcfilename, quelldatei);
     sf->setModal(true);
     infoEdit->append("Name Source-File:");
     infoEdit->append(srcfilename);
     Nachricht = QString("Orginaldateilaenge: %1 Byte").arg(origdatlen);
     infoEdit->append(Nachricht);
     //msgBox->setText(Nachricht);
     //msgBox->show();
     sf->exec();
    }
   else
    {
     Nachricht = QString("Keine Source-Datei ausgewaehlt!");
     msgBox->setText(Nachricht);
     msgBox->show();
     infoEdit->append(Nachricht);
    }
 }
 else
  {
   Nachricht = QString("Keine Ziel-Datei ausgewaehlt!");
   msgBox->setText(Nachricht);
   msgBox->show();
   infoEdit->append(Nachricht);
  }

}


void Alea::getSFileValues(void)
{
 //char *sourcedatei = sourcefilename.toAscii().data();  // kopiert einen QString in einen ASCII-String
 QByteArray sourcedatei = sourcefilename.toLatin1();
 std::fstream dat_ein;  // std::fstream

  //QMessageBox *msgBox = new QMessageBox(this);
  //Grundinformationen einlesen

 /* Initialisiert die Dateilänge, einser, und Nuller mit Null, um richtig zäehlen zu können*/
  sourcelength = 0;

  dat_ein.open(sourcedatei, std::fstream::in | std::fstream::binary);

 if (!dat_ein )
  {
   msgBox->setText("Datei konnte nicht geoeffnet werden!");
   msgBox->show();
   infoEdit->append("Datei konnte nicht geoeffnet werden!");
  }

 dat_ein.seekg(0, std::fstream::end);

 sourcelength = dat_ein.tellg();

 dat_ein.close();

 // cout << "\nDateilänge: " << dateilaenge << "  Obergrenze: %d" << toprange;
 bloecke = (sourcelength * 8) / (long)toprange;
 //cout << "\nDateiläenge x 8 : Obergrenze = " << bloecke << " Blöcke" << bloecke;
 blockrest = (int)((sourcelength * 8) % (long)toprange);
 blockdifferenz = (toprange - blockrest) / 8;
//cout << "\nRest: " << blockrest << "  Differenz zu toprange: %d Bytes" << blockdifferenz;
}


void Alea::MakeRandoms(void)
{
 MaxRandom = Maxbits->currentText();
 toprange  = MaxRandom.toInt();
 //maxrnd    = toprange;
 Nachricht = QString::number(toprange);
 lineEdit->setText(Nachricht);

 dummy = QString::number(toprange);
 showtoprange -> setText(dummy);


 initarreale(); // Arreale vorbereiten
 generateRandoms(); // generiere Zufallszahlen
 testeareal();

 dummy = QString::number(sollsumme);
 soll->setText(dummy);

 dummy = QString::number(istsumme);
 ist->setText(dummy);

}

void Alea::about()
{
  QMessageBox::about( this, "Autor",
                        "Alea V 0.71 Beta\n"
                        "von Josef Wismeth\n"
                        );
}

//generiert Zufallszahlen von 0 bis 32767;
int Alea::getrand(int min, int max)
{
int zuza, zuza2, zuza3, rewer;
// bis 32767
 //srand (time (NULL));
 if (initrandom == 0)
  {
  srand (time (NULL));
  initrandom = 1;
  }

zuza  = rand();
zuza2 = (max - min); //+1); <- wird nur verwendet, wenn die Untergrenze >= 1 sein soll
zuza3 = zuza % zuza2;
rewer = zuza3 + min;
return rewer;
}

// initialisiert die Zufallszahlenarrays mit den Startwerten
void Alea::initarreale(void)
{
int slei;
if (toprange > MAXBITLIMIT) toprange = MAXBITLIMIT;

 for (slei = 0; slei < MAXBITLIMIT; slei++)
  {
   //zuzaar[slei] = 0;
   wuerfel[slei] = 0;
   schluessel[slei] = 0;
  }

 for (slei = 0; slei < toprange; slei++)
   wuerfel[slei] = slei;

}

void Alea::rejumblekey(void)
{
int slei;
if (toprange > MAXBITLIMIT) toprange = MAXBITLIMIT;

for (slei = 0; slei < toprange; slei++)
 {
  //zuzaar[slei] = 0;
  wuerfel[slei] = schluessel[slei];
 }
for (slei = 0; slei < toprange; slei++)
 {
  schluessel[slei] = 0;
 }

// neuen Schlüssel testen
 testeareal();
 dummy = QString::number(sollsumme);
 soll->setText(dummy);
 dummy = QString::number(istsumme);
 ist->setText(dummy);
}


void Alea::kuerzearreal(int zuza, int og,  int stelle)
{
int slei;

schluessel[stelle] = wuerfel[zuza];
for (slei = zuza; slei < og; slei++)
  wuerfel[slei] = wuerfel [slei + 1];

}

void Alea::generateRandoms(void)
{
int slei, dmog, sleia, zuza;
    dmog = toprange;

    if (toprange > MAXBITLIMIT) toprange = MAXBITLIMIT;
    /* Initialisiere Arreale */

      dmog = toprange;
      sleia = 0;

      for (slei = 0; slei < toprange; slei++)
       {
        //zuzaar[slei] = getrand(lowerlimit, dmog);
        //zuza = zuzaar[slei];
        zuza = getrand(lowerlimit, dmog);
        kuerzearreal(zuza, toprange, sleia);
        sleia++;
        dmog--;
        if (dmog == 0 ) break;
       }
}

// Errechnet die Prüfsumme der Zufallszahlenarrays um die Richtigkeit zu überprüfen
void Alea::testeareal(void)
{
 long slei;
 sollsumme = 0;
 istsumme = 0;

 for (slei = 0; slei < toprange; slei++)
  {
   sollsumme += slei;
   istsumme  += schluessel[slei];
  }
 if (sollsumme == istsumme)
    testergebnis = 0;
  else testergebnis = 1;
}

int Alea::schreibedatei(void)
{
  std::ofstream dat_aus;  // std::fstream
  int slei, sleib, zeimen = 0;

  //std::string keydname;
  //keydname= keyfilename.toAscii().data();  // kopiert einen QString in einen ASCII-String
  QByteArray keydname = keyfilename.toLatin1();

  dat_aus.open(keydname, std::ofstream::out | std::ofstream::binary);
   if (!dat_aus)
    {
     QMessageBox::about( this, "Key-File", "Schluesseldatei konnte nicht geschrieben werden");
     return zeimen;
    }
   else
     for (slei = 0; slei < toprange; slei++)
     {
      intzuchar(schluessel[slei]);           // speichet einen 4Byte-Integer-Wert in unsigned char-array
      for (sleib = 0; sleib <= 3; sleib++)
       {
        dat_aus.put(intteile[sleib]);
        zeimen++;
       }
     }
   dat_aus.close();
   //QMessageBox::about( this, "Key-File", "Schluesseldatei wurde gespeichert");
   infoEdit->append("Key-File:");
   infoEdit->append("Schluesseldatei wurde gespeichert");

return zeimen;
}

// Einlesen der Schlüsseldatei
// Einlesen der Schlüsseldatei
int Alea::lesedateiein(void)
{
  std::fstream dat_ein;
  int sleia, slei, sleic = -1, dummy, groesse, intzahl;
  unsigned char intteile[4];

  groesse = keydatlen;

   //(keyfilename,  slusseldatei); // kopiert einen QString in einen ASCII-String
   //std::string keydname;
   //keydname= keyfilename.toAscii().data();  // kopiert einen QString in einen ASCII-String
   QByteArray keydname = keyfilename.toLatin1();

   ///Nachricht = QString::fromStdString(keydname);
   Nachricht = QString(keydname);

   //Nachricht = QString("*Lese Key-Datei\n%1\n ein").arg(slusseldatei);
   //Nachricht = QString(keydname);//("*Lese Keydatei\n%1\n ein").arg(keydname);
   QMessageBox::about( this, "Key-Datei", Nachricht);
   infoEdit->append("Key-File:");
   infoEdit->append(keyfilename);

   dat_ein.open(keydname, std::fstream::in | std::fstream::binary);
   //fz = fopen(slusseldatei, "rb");
   if (!dat_ein)
    {
     Nachricht = QString("%1 Kann nicht geladen werden").arg(slusseldatei);
     infoEdit->append("Key-File kann nicht galaden werden");
     QMessageBox::about( this, "Key-Datei", Nachricht);
     return sleic;
    }
    else
     {
      slei = sleic = 0;

      for (sleia = 0; sleia < groesse; sleia++)
       {
        dummy = getint(&dat_ein);
        if (dat_ein.eof()) break;

        intteile[slei++] = dummy;
        if (slei >= 4)
         {
          intzahl = charzuint(intteile);
          schluessel[sleic++] = intzahl;
          slei = 0;
        }
       }

      dat_ein.close();

      Nachricht = QString("%1 Bytes wurden eingelesen").arg(sleia);
      QMessageBox::about( this, "Key-Datei", Nachricht);
      infoEdit->append("Key-Datei");
      infoEdit->append(Nachricht);

      //maxrnd = sleic;
      sdummy = QString::number(sleic);
      lineEdit->setText(sdummy);
     }
return sleic;
}

int Alea::Maxbitlimit(void)
{
 return toprange;
}


/// holt nach dem komprimieren aus der Code-Datei die Orginaldateilaenge
int Alea::GetOrgDatlen(void)
{
  int rewer = -1;
  unsigned long datlendummy;
  std::fstream dat_ein;  // std::fstream

  //char *keyfile  = keyfilename.toAscii().data();  // kopiert einen QString in einen ASCII-String
   QByteArray keyfile = keyfilename.toLatin1();
   dat_ein.open(keyfile, std::fstream::in | std::fstream::binary);

    if (!dat_ein) return 0; // bei Fehler eine 0 als Rückgabewert, bei Erfolg eine -1;

     dat_ein.seekg(-4, std::fstream::end);
     datlendummy = fgetDWORD(&dat_ein);
     origdatlen = datlendummy;
     orginaldateilaenge = origdatlen;

     dummy = QString::number(datlendummy);
     origfilelen -> setText(dummy);

     dat_ein.close();

return rewer;
}


/** Liest vom Filestream 4 Bytes als 4Byte-Integer ein */
int Alea::fgetDWORD(std::fstream *datei)
{
 int slei;
 char buchs;

 union QCHAR
 {
  int izahl;
  unsigned char DWTeile[4];
 } dword;

 dword.izahl = 0;
 for (slei = 3; slei >= 0; slei--)
  dword.DWTeile[slei] = 0;
 for (slei = 3; slei >= 0; slei--)
  {
   datei->get(buchs);
   if (datei->eof()) break;
   dword.DWTeile[slei] = atoint(buchs);
  }

 return dword.izahl;
}
