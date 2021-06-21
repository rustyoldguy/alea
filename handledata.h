#ifndef HANDLEDATA_H
#define HANDLEDATA_H

#include <fstream>
#include <QString>
#include "dialog.h"

char inttochar(int letter);
void putint(std::ofstream *datei, int letter);
int getint(std::fstream *datei);

int atoint(char letter);
int getint(std::fstream *datei);
char inttochar(int letter);
unsigned char getbitval(int bitnum, unsigned char wert);
unsigned char setbitval(unsigned char wert, int bitnum, int setzwert);
void getCHname(QString dtnam,  char erge[]);
long srcgetdatlen(void);


#endif
