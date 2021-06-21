#include "handledata.h"

// Umwandlung von int vorzeichenlos zu signed char
// Wertebereich von unsigned char = 0 bis 255
// Wertebereich singed char von -128 bis +127
char inttochar(int letter)
{
 char rewer = 0;
 if ( letter > 127)
  rewer = (char)(letter - 256);
   else rewer = letter;

 return rewer;
}


/** Fehler bei Anwendung */
void putint(std::ofstream *datei, int letter)
{
 char buchs;
 buchs = inttochar(letter);
 datei->put(buchs);
}

int getint(std::fstream *datei)
{
int rewer = 0;
char buchs;
datei->get(buchs);
rewer = atoint(buchs);

return rewer;
}

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
}

/** Liest vom Filestream 4 Bytes als 4Byte-Integer ein */
/** Alte Syntax war: */
/*
int Alea::fgetDWORD(FILE *fz)
{
 int slei, DWTeile[4] = {0,0,0,0};
 unsigned long dummy = 0;

 for (slei = 3; slei >= 0; slei--)
  {
   DWTeile[slei] = fgetc(fz);
    if ( (feof(fz)) == 0)
     {
      dummy = (unsigned long)DWTeile[0];
      dummy += (unsigned long)(DWTeile[1] << 8);
      dummy += (unsigned long)(DWTeile[2] << 16);
      dummy += (unsigned long)(DWTeile[3] << 24);
     }
  }
return dummy;
}
*/


