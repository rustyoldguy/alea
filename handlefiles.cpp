#include "mainwindow.h"

void Alea::getkeyfilename(void)
{
  keyfilename = QFileDialog::getOpenFileName(this, tr("Load Key File..."),
                                                 QString(), tr("All Files (*);;HTML-Files (*.htm *.html)"));
  kdatname->setText(keyfilename);
}

void Alea::setKeyDatname(void)
{
 keyfilename = QFileDialog::getSaveFileName(this, tr("Save Key in File as..."),
                                                 QString(), tr("All Files (*);;HTML-Files (*.htm *.html)"));
 kdatname -> setText(keyfilename);
}

/** Stellt die Länge der Schlüsseldatei fest*/
long Alea::getdatlen(void)
{
   long dateilaenge = 0; // Initialisiert die Dateilänge, einser, und Nuller mit Null, um richtig zäehlen zu können
    //QMessageBox *msgBox = new QMessageBox(this);
    //Grundinformationen einlesen

   std::fstream dat_ein;  // std::fstream


    ///char *finam = keyfilename.toAscii().data();  // kopiert einen QString in einen ASCII-String
    QByteArray finam = keyfilename.toLatin1();
    dat_ein.open(finam, std::fstream::in | std::fstream::binary);

   if (!dat_ein )
    {
     msgBox->setText("Datei konnte nicht geoeffnet werden!");
     msgBox->show();
     infoEdit->append("Datei konnte nicht geoeffnet werden!");
    }

   dat_ein.seekg(0, std::fstream::end);
   dateilaenge = dat_ein.tellg();


   dat_ein.close();

return dateilaenge;
}

void Alea::GetTargetname(void)
{
 tarfilename = QFileDialog::getSaveFileName(this, tr("Name der Zieldatei"),
                                                     QString(), tr("All Files (*);;HTML-Files (*.htm *.html)"));



 //QMessageBox::about( this, "tarfilename", tarfilename);

  if (!tarfilename.isEmpty())
  {
   //load(tarfilename);
   //erge  = tarfilename.toAscii().data();  // kopiert einen QString in einen ASCII-String
   getCHname(tarfilename, zieldatei);

   infoEdit->append("Name Zieldatei: ");
   infoEdit->append(tarfilename);
   Nachricht = QString("Orginaldateilaenge: %1 Byte").arg(orginaldateilaenge);
   msgBox->setText(Nachricht);
   msgBox->show();
   infoEdit->append(Nachricht);
  }
 else
  {
   Nachricht = QString("Keine Ziel-Datei ausgewaehlt!");
   msgBox->setText(Nachricht);
   msgBox->show();
   infoEdit->append(Nachricht);
  }

}
