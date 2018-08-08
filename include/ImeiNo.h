
#ifndef IMEINO_H //IMEINO k�t�phanesi tan�mlan�yor
#define IMEINO_H

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "time.h"
#include "stdbool.h"

struct IMEINO //IMEINO yap�s� olu�turuluyor
{
	//Struct alan� tan�mlan�yor
	char* imei;
	//Fonksiyon g�stericileri tan�mlan�yor
	void(*Yoket)(struct IMEINO*);
	bool(*Kontrol)(char*);

};

typedef struct IMEINO* ImeiNo;
//IMEINO yap� i�aret�isinin ismi ImeiNo olarak atan�yor

ImeiNo imeiOlustur(int);	//yap�c� method tan�mlan�yor
//K�t�phane fonksiyonlar� tan�mlan�yor
char* generateValidImeiNumber(int);
int getCheckDigit(char*);
int sumUpDigits(int);
int sumDig(int);
void ImeiNoYoket(ImeiNo);
bool isValidIMEI(char*);
#endif
