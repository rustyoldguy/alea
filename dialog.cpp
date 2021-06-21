// Dialog::Dialog(QWidget *parent)
// Dialog::~Dialog()
// int Dialog::getrand(int min, int max)
// void Dialog::PrepareFile(void)
// int Dialog::GenRandomByts(void)
// int Dialog::SetDifBytesInFile(void)
// void Dialog::NewsBox(QString Newstext)
// void Dialog::Koden(void)
// long Dialog::srcgetdatlen(void)
// void Dialog::Setkodiermodus(void)
// int Dialog::loadSRCDatei(void)
// int Dialog::SaveOrgDatlen(unsigned long srcdatlen)



#include "dialog.h"
#include "ui_dialog.h"
#include "handledata.h"
/*
Dialog::Dialog(QMainWindow *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}*/

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
  {
   //QMessageBox *msgBox = new QMessageBox(this);
      kodieren = 0; //  wenn kodieren ==1 dann Dekodiermodus, wenn 0 dann Kodiermodus

   ui->setupUi(this);
   this->setWindowTitle("Sourcefile Values");
   this->move(650,100); //Setzt die Widget-Ausgabeposition

   //-------------vom Hauptfenster Variable holen-------------
   initglobvariable(parent);

   //-------------Text in TextEdit schreiben------------------
   dummystring  = QString::number(toprange);
   ui->sdatlen -> setText(dummystring);
   ui->quelldateiname->setText(srcfilename);
   ui->targetfile->setText(tarfilename);

   ui->kodiermodus->setText("kodieren"); //  wenn kodieren ==1 dann Dekodiermodus, wenn 0 dann Kodiermodus

   Nachricht = QString::number(toprange);
   ui->showmaxrnd->setText(Nachricht);

   //Zuerst die Orginallänge der Sourcedatei ermitteln
   srcdatlen    = srcgetdatlen();
   (reinterpret_cast<Alea *>(parent))->srcdatlen = srcdatlen;

   //  wenn kodieren ==1 dann Dekodiermodus, wenn 0 dann Kodiermodus
   if (kodieren == 0) orginaldateilaenge = srcdatlen;
    else dateilaenge = orginaldateilaenge;

   dummystring  = QString::number(srcdatlen);
   ui->srclnge->setText(dummystring);

   Nachricht = QString("SourceFile toprange vorher: %1").arg(toprange);
   NewsBox(Nachricht);
   ui->textEdit->append(Nachricht);

   if (toprange == 0)
    {
     Nachricht = QString("Keine Schlüsseldatei abgespeichert oder geladen");
     WmsgBox->setText(Nachricht);
     WmsgBox->show();
     ui->textEdit->append(Nachricht);
    }
    else
     {
      // Errechnet und zeigt die zu erstellenden Werte für die zu codende Datei an
      bloecke = (srcdatlen * 8) / (long)toprange;
      (reinterpret_cast<Alea *>(parent))->bloecke = bloecke;

      dummystring  = QString::number(bloecke);
      ui->sizeofblocks->setText(dummystring);

      //delete ui;

      blockrest = (int)((srcdatlen * 8) % (long)toprange);
      (reinterpret_cast<Alea *>(parent))->blockrest = blockrest;
      dummystring  = QString::number(blockrest);
      ui->sizeofblockrest->setText(dummystring);

      blockdifferenz = (toprange - blockrest) / 8;  // blockdifferenz ist die Anzahl der fehlenden Bytes
      (reinterpret_cast<Alea *>(parent))->blockdifferenz = blockdifferenz;
      dummystring  = QString::number(blockdifferenz);
      ui->srcblkdif->setText(dummystring);
     }
   //orginaldateilaenge = srcdatlen;

   Nachricht = QString("SourceFile toprange nachher: %1").arg(toprange);
   NewsBox(Nachricht);


   connect(ui->docode,         SIGNAL(clicked()), this, SLOT(loadSRCDatei() ) );   // startet den Kodiervorgang
   connect(ui->preparesrcfile, SIGNAL(clicked()), this, SLOT(PrepareFile() ) );    // Modifiziert die Quelldatei
   connect(ui->setkodemodus,   SIGNAL(clicked()), this, SLOT(Setkodiermodus() ) ); // Setzen des Kodiermodus
   connect(ui->srcaus,         SIGNAL(clicked()), this, SLOT(hide() ) );           // Beendet die Anzeige des zweiten Fensters
  }


Dialog::~Dialog()
{
 delete WmsgBox;
 delete ui;
}

//generiert Zufallszahlen von 0 bis 32767;
int Dialog::getrand(int min, int max)
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

void Dialog::PrepareFile(void)
{

  // Nur falls blockdifferenz ungleich NULL ist sollen fehlende Bytes angehängt werden
  if (blockdifferenz != 0)
          {
           NewsBox("Erzeuge fehlende Bytes....");

           difbytes = GenRandomByts();    // Erzeugen und Abspeichern fehlender Bytes
           NewsBox("Fehlende Bytes wurden erzeugt");

           Teila = QString("Laenge derSchluesseldatei %1 ").arg(keyfilename);  // Ausbessern, da die Quelldateilänge gezeigt wird!!
           Teilb = QString(" ist %1 Bytes").arg(keydatlen);
           Nachricht = Teila + Teilb;
           //NewsBox(Nachricht);
           ui->textEdit->append(Nachricht);

           // Nachricht = QString("PrepareFile toprange vor Saveorgdatlen: %1").arg(toprange);
           // NewsBox(Nachricht);

           maxrnd = toprange;  // Muss vor dem Aufruf von SaveOrgDatlen zwischengespeichert werden, da bei Aufruf von fopen toprange auf 64c gesetzt wird

           // Speichert die Orginale Dateilänge in der Schlüsseldatei
           dummy = SaveOrgDatlen(orginaldateilaenge);

           toprange = maxrnd;

           //NewsBox
           ui->textEdit->append("Haenge fehlende Bytes an SRC-Datei an");

           // Nachricht = QString("PrepareFile toprange nach Saveorgdatlen: %1").arg(toprange);
           // NewsBox(Nachricht);

          dummy = SetDifBytesInFile();

           //Nachricht = QString("PrepareFile toprange nach  Setdifbytesinfile: %1").arg(toprange);
           //NewsBox(Nachricht);

           //NewsBox
           ui->textEdit->append("Ermittle neue Dateilaenge.......");

           dateilaenge = srcgetdatlen();

           Teila = QString("Neue QuelldateiLaenge von %1 ").arg(srcfilename);
           Teilb = QString(" %1 Bytes").arg(dateilaenge);
           Nachricht = Teila + Teilb;
           //NewsBox
           ui->textEdit->append(Nachricht);
          }
}

// generiert per Zufallszahlengenerator die Fehlenden Bytes und speichert diese in das Array Fehlbytes ab
int Dialog::GenRandomByts(void)
{
int slei, rewer = 0;

 for (slei = 0; slei < blockdifferenz; slei++)
  {
   fehlbytes[slei]  = getrand(0, 255);
   rewer++;
  }
return rewer;
}
// rundet Datei auf richtige Länge auf
int Dialog::SetDifBytesInFile(void)
{
 int slei;
 FILE *ziel;
 int rewer = -1;

 //char *datname  = srcfilename.toAscii().data();  // kopiert einen QString in einen ASCII-String
 QByteArray datname = srcfilename.toLatin1();
 if ((ziel = fopen(datname, "ab"))  == NULL)
   {
    return rewer;
   }
   else
    {
     fseek(ziel, 0, SEEK_END); //setzt Dateizeiger auf 4 Bytes vor Dateiende
     // Speichert die fehlenden Bytes als int-Wert in datnamedas rgdatlenarray
     for (slei = 0; slei < blockdifferenz; slei++)
      fputc((int)fehlbytes[slei], ziel);
    rewer = 0;
   }

fclose(ziel);

return(rewer);
}

void Dialog::NewsBox(QString Newstext)
{
  QMessageBox::about( this, "Achtung:", Newstext);
}

void Dialog::Koden(void) //(char satzteil[], int (*ziel)[80], int key[], int toprange)
{
 long slei;
 int bytenummer, bitnummer, zielbytenummer, zielbitnummer, schluesselzahl, bitval;

   for (slei = 0; slei < toprange; slei++)
    {
     schluesselzahl = schluessel[slei];
     //  wenn kodieren ==1 dann Dekodiermodus, wenn 0 dann Kodiermodus
     if (kodieren)
     {
     bytenummer = schluesselzahl / 8;
     bitnummer = 7 - (schluesselzahl % 8);
     zielbytenummer = slei / 8;
     zielbitnummer = 7 - (slei % 8);
     }
    else
     {
      bytenummer = slei / 8;
      bitnummer = 7 - (slei % 8);
      zielbytenummer = schluesselzahl / 8;
      zielbitnummer = 7 - (schluesselzahl % 8);
     }
     bitval = getbitval(bitnummer, satzteil[bytenummer]);
     satzgecodet[zielbytenummer] = setbitval(satzgecodet[zielbytenummer], zielbitnummer, bitval);
   }
}


void Dialog::Setkodiermodus(void)
{
 //  wenn kodieren ==1 dann Dekodiermodus, wenn 0 dann Kodiermodus
 if (kodieren == 0)
  {
   kodieren = 1;
   ui->kodiermodus->setText("dekodieren");
  }
   else
    {
     kodieren = 0;
     ui->kodiermodus->setText("kodieren");
    }
}


/** Kodieren der Quell-Datei zur Zieldatei */
int Dialog::loadSRCDatei(void)
{
 long slei, sleib, zeimen, written, testit = 0;
 int rewer = -1;
 QByteArray tocodefile;
 std::fstream dat_ein;
 std::ofstream dat_aus;  // std::fstream

 // kopiert einen QString in einen ASCII-String
 tocodefile = srcfilename.toLatin1();

 // kopiert einen QString in einen ASCII-String
 QByteArray targetfile = tarfilename.toLatin1();

  // slei + sleib müssen int sein, bei unsigned int kann nicht auf Null dekrementieren!!!
  // sonst läuft die Schleife ewig!!!

  dateilaenge = srcdatlen; // Länge der Quelldatei einlesen
  //Kodieren = 0    dekodieren = 1

  Nachricht = QString::number(toprange);
  ui->showmaxrnd->setText(Nachricht);


  dat_ein.open(tocodefile, std::fstream::in | std::fstream::binary);

  if (!dat_ein)
   {
    Nachricht = srcfilename;
    QMessageBox::about( this, "Konnte nicht geoeffnet werden:", Nachricht);
    rewer = 0;       // bei Fehler eine 0 als Rückgabewert, bei Erfolg eine -1;
    return(rewer);
   }


   //Nachricht = QString("Quelldatei %1 geoeffnet").arg(quelldatei);
   //WmsgBox->setText(Nachricht);
   //WmsgBox->show();

  dat_aus.open(targetfile, std::ofstream::out | std::ofstream::binary);

  if (!dat_aus)
   {
    NewsBox("Ziel-Datei kann nicht erstellt werden!");
    dat_ein.close();
    rewer = 0; // bei Fehler eine 0 als Rückgabewert, bei Erfolg eine -1;
    dummy = rewer;
    return(rewer);
   }


   //***********cout << "\nZieldatei " << zieldatei << "wurde erstellt...." << endl;
   //Nachricht = QString("Ziel %1 erstellt").arg(zieldatei);
   //WmsgBox->setText(Nachricht);
   //WmsgBox->show();


   //zeimen = 0;
   //written = 0;

   testit = 0;
   for (sleib = 0; sleib < toprange; sleib++)
    testit += schluessel[sleib];

   zeimen = written = 0;
   Teila = QString("Bei toprange %1\n").arg(toprange);
   Teilb = QString("Testwert Schluesselarray: %1").arg(testit);
   Nachricht = Teila + Teilb;
   NewsBox(Nachricht);



   // Speichert die letzten 4 Bytes als long-Wert in das orgdatlenarray
   for (slei = 0; slei < dateilaenge; slei+= toprange / 8) //----------------------------------  hier ausbessern da dateilaenge auf Null ist
    {
     for (sleib = 0; sleib < toprange / 8; sleib++)
      {


         satzteil[sleib] = getint(&dat_ein);
         if (dat_ein.eof())
         {
          dat_ein.close();
          dat_aus.close();
          dummy = rewer;

          Teila = QString("Gelesene Bytes....: %1\n").arg(zeimen);
          Teilb = QString("Geschriebene Bytes: %1").arg(written);
          Nachricht = Teila + Teilb;
          NewsBox(Nachricht);

          //  wenn kodieren ==1 dann Dekodiermodus, wenn 0 dann Kodiermodus
          if (kodieren == 1)
            {
             ui->kodiermodus->setText("dekodieren");
             dummy = truncate(zieldatei, origdatlen);
             Teila = QString("Orig Zieldatei %1").arg(zieldatei);
             Teilb = QString("auf %1 Bytes gesetzt").arg(origdatlen);
             Nachricht = Teila + Teilb;
             NewsBox(Nachricht);
            }

          //Kodieren = 0    dekodieren = 1
          else
             {
              ui->kodiermodus->setText("kodieren");
              dummy = truncate(quelldatei, orginaldateilaenge);
              Teila = QString("Quelldatei %1").arg(quelldatei);
              Teilb = QString("\nauf %1 Bytes gesetzt").arg(orginaldateilaenge);
              Nachricht = Teila + Teilb;
              NewsBox(Nachricht);
            }
            return(rewer);

         }
         zeimen++;
     }

      Koden();          //alt war: schluessel, unkodiert, kodiert);

       // einzeln zielbytes abspeichern
       for (sleib = 0; sleib < toprange / 8; sleib++)
        {
         putint(&dat_aus, satzgecodet[sleib]);  // alt war: fputc(satzgecodet[sleib], tar); // test mit satzteil -> origdatei
         written++;
        }

    }

            dat_ein.close();
            dat_aus.close();

            dummy = rewer;
        Teila = QString("Gelesene Bytes.......: %1").arg(zeimen);
        Teilb = QString("\nGeschriebene  Bytes: %1").arg(written);
        Nachricht = Teila + Teilb;
        NewsBox(Nachricht);

            //  wenn kodieren ==1 dann Dekodiermodus, wenn 0 dann Kodiermodus
            if (kodieren == 1)
             {
              dummy = truncate(zieldatei, origdatlen);
              Teila = QString("Zieldatei %1").arg(zieldatei);
              Teilb = QString("\nauf %1 Bytes gesetzt").arg(origdatlen);
              Nachricht = Teila + Teilb;
              NewsBox(Nachricht);
             }//unsigned char quelle[], unsigned char binsatz[]);
             else if (kodieren == 0)
              {
               dummy = truncate(quelldatei, orginaldateilaenge);
               Teila = QString("Quelldatei %1").arg(quelldatei);
               Teilb = QString("\nauf %1 Bytes gesetzt").arg(orginaldateilaenge);
               Nachricht = Teila + Teilb;
               NewsBox(Nachricht);
              }

  return(rewer);
}
//*********************Ende von int SourceFile::loadSRCDatei(void)*************************************************



/** Speichet die Orginaldateilaenge der komprimierten Datei aus einen Long-Wert
 als Anhängsel an die Code-Datei*/
int Dialog::SaveOrgDatlen(unsigned long srcdatlen)
{
Alea talar;
int rewer = -1;// bei Erfolg -1 , bei existierender Datei -2, sonst 0

std::ofstream dat_aus;  // std::fstream

//char *keyfile  = keyfilename.toAscii().data();  // kopiert einen QString in einen ASCII-String
//getCHname(keyfilename,  slusseldatei);

   // Nachricht = QString("saveorgdatlen toprange vorher: %1").arg(toprange);
   // NewsBox(Nachricht);

   //std::string keydname;
   QByteArray keydname = keyfilename.toLatin1();
   //keydname = keyfilename.toAscii().data();  // kopiert einen QString in einen ASCII-String

       dat_aus.open(keydname, std::ofstream::out | std::ofstream::app| std::ofstream::binary);
       if (!dat_aus)
       {
         return rewer;
        }
        else
        {
         fputDWORD(srcdatlen, &dat_aus);
         dat_aus.close();
        rewer = -2;
       }

       // Nachricht = QString("saveorgdatlen toprange nachher: %1").arg(toprange);
       // NewsBox(Nachricht);

 return(rewer);
}

int Dialog::fputDWORD(unsigned int letter, std::ofstream *datei)
{
 int slei, rewer = 0;
 unsigned int DWTeile[4] = {0,0,0,0};

 DWTeile[3] = (letter >> 24);
 DWTeile[2] = ((letter >> 16) & 255);
 DWTeile[1] = ((letter >>  8) & 255);
 DWTeile[0] = (letter & 255);

 for (slei = 3; slei >= 0; slei--)
  datei->put(DWTeile[slei]);

return rewer;
}

long Dialog::srcgetdatlen(void)
{
   long dateilaenge = 0; // Initialisiert die Dateilänge, einser, und Nuller mit Null, um richtig zäehlen zu können
    //QMessageBox *msgBox = new QMessageBox(this);
    //Grundinformationen einlesen

   std::fstream dat_ein;  // std::fstream


    //char *finam = srcfilename.toAscii().data();  // kopiert einen QString in einen ASCII-String
    QByteArray finam = srcfilename.toLatin1();
    dat_ein.open(finam, std::fstream::in | std::fstream::binary);

   if (!dat_ein )
    {
     QMessageBox::about( this, "src-File", "Datei konnte nicht geoeffnet werden");
     // msgBox->setText("Datei konnte nicht geoeffnet werden!");
     // msgBox->show();
    }

   dat_ein.seekg(0, std::fstream::end);
   dateilaenge = dat_ein.tellg();


   dat_ein.close();

return dateilaenge;
}

void Dialog::initglobvariable(QWidget *parent)
{
    toprange = (reinterpret_cast<Alea *>(parent))->toprange;
    blockdifferenz = (reinterpret_cast<Alea *>(parent))->blockdifferenz;
    initrandom = (reinterpret_cast<Alea *>(parent))->initrandom;
    srcfilename = (reinterpret_cast<Alea *>(parent))->srcfilename;
    srcdatlen = (reinterpret_cast<Alea *>(parent))->srcdatlen;
    bloecke = (reinterpret_cast<Alea *>(parent))->bloecke;
    blockrest = (reinterpret_cast<Alea *>(parent))->blockrest;
    keydatlen = (reinterpret_cast<Alea *>(parent))->keydatlen;
    Teila = (reinterpret_cast<Alea *>(parent))->Teila;
    Teilb = (reinterpret_cast<Alea *>(parent))->Teilb;
    Teilc = (reinterpret_cast<Alea *>(parent))->Teilc;
    maxrnd = (reinterpret_cast<Alea *>(parent))->maxrnd;
    origdatlen = (reinterpret_cast<Alea *>(parent))->origdatlen;
    srcdatflag = (reinterpret_cast<Alea *>(parent))->srcdatflag;
    tarfilename = (reinterpret_cast<Alea *>(parent))->tarfilename;
    keyfilename = (reinterpret_cast<Alea *>(parent))->keyfilename;
    orginaldateilaenge = (reinterpret_cast<Alea *>(parent))->orginaldateilaenge;


    for (slei = 0; slei < 600; slei++)
     {
      quelldatei[slei] = (reinterpret_cast<Alea *>(parent))->quelldatei[slei];
      slusseldatei[slei] = (reinterpret_cast<Alea *>(parent))->slusseldatei[slei];
      zieldatei[slei] = (reinterpret_cast<Alea *>(parent))->zieldatei[slei];
     }

    for (slei = 0; slei < MAXBITLIMIT; slei++)
      {
        schluessel[slei] = (reinterpret_cast<Alea *>(parent))->schluessel[slei];
      }

}
