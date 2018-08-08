
#ifndef KIMLIKNO_H //KIMLIKNO k�t�phanesi tan�mlan�yor
#define KIMLIKNO_H

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"
#include "time.h"

struct KIMLIKNO //KIMLIKNO yap�s� olu�turuluyor
{
	//Struct alan� tan�mlan�yor
	char* tcno;
	//Fonksiyon g�stericileri tan�mlan�yor
	void(*Yoket)(struct KIMLIKNO*);
	bool(*Kontrol)(char*);
};

typedef struct KIMLIKNO* KimlikNo;
//KIMLIKNO yap� i�aret�isinin ismi KimlikNo olarak atan�yor

KimlikNo KimlikOlustur(int);	//yap�c� method tan�mlan�yor
//K�t�phane fonksiyonlar� tan�mlan�yor
char* TCIDOlustur(int);
void KimlikNoYoket(KimlikNo);
bool isValidTckn(char*);
#endif
