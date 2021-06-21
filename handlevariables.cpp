
#include "mainwindow.h"

void Alea::intzuchar(int zuza)
{
 union intpart{
 unsigned int erge;
 unsigned char ipart[4];
 } ipt;

 ipt.erge = zuza;

 intteile[0] = ipt.ipart[0];
 intteile[1] = ipt.ipart[1];
 intteile[2] = ipt.ipart[2];
 intteile[3] = ipt.ipart[3];
}

int Alea::charzuint(unsigned char intteile[4])
{
 union intpart{
 unsigned int erge;
 unsigned char ipart[4];
} ipt;

 ipt.ipart[0] = intteile[0];
 ipt.ipart[1] = intteile[1];
 ipt.ipart[2] = intteile[2];
 ipt.ipart[3] = intteile[3];

return ipt.erge;
}
//Umwandlung von signed char zu int
int atoint(char letter)
{
 int rewer;
 if ( letter < 0)
  rewer = letter + 256;
   else rewer = (int)letter;
 return rewer;
}
/*
// Wandelt QString in eindimensionales char-Array um
void getCHname(QString dtnam,  char erge[])
{
 int slei;
 //char *name;
 //name = dtnam.toAscii().data();  // kopiert einen QString in einen ASCII-String

 QByteArray name = dtnam.toLatin1();

 for (slei = 0; slei < 600; slei++)
  {
   erge[slei] = name[slei];
   if (name[slei] == '\0') break;

  }
}*/



unsigned char getbitval(int bitnum, unsigned char wert)
{
unsigned char suwer =  1;
unsigned char sumwer, dumwer;

if (bitnum < 14)
 {
  sumwer = wert & (suwer << bitnum);
  if (sumwer) dumwer = 1;
   else dumwer = 0;
 }
 return dumwer;
}

unsigned char setbitval(unsigned char wert, int bitnum, int setzwert)
{
 unsigned char istwert, bitwert, erge = 0;

 istwert = getbitval(bitnum, wert);
 if (istwert == setzwert) { erge = wert;} // std::cout << "*1*\n"; }
  else
   {
    bitwert = 1 << bitnum;
    //std::cout << "Setzwert: " << bitwert << std::endl;
    if((istwert == 0) && (setzwert == 1))
      {
       //std::cout << "*2erge= " << wert;
       erge = wert | bitwert;
      }
    if((istwert == 1) && (setzwert == 0))
      {
       //std::cout << "*3erge= " << wert;
       erge = wert & (255 - bitwert);
      }
   }

 //std::cout << " **erge= " << erge << std::endl;
 return erge;
}

// Wandelt QString in eindimensionales char-Array um
QString chartoqstring(QByteArray quelle)
{
 int slei, chlen = -1;
 QString ziel;
 //char *name;
 //name = dtnam.toAscii().data();  // kopiert einen QString in einen ASCII-String

 for (slei = 0; slei < 600; slei++)
 {
  if (quelle[slei] == '\0')
    chlen = slei;
 }

 for (slei = 0; slei < chlen; slei++)
  {
   ziel += quelle[slei];
  }

 return ziel;
}
