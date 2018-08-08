
#ifndef TELEFON_H //TELEFON k�t�phanesi tan�mlan�yor
#define TELEFON_H

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"
#include "ImeiNo.h"

struct TELEFON //TELEFON yap�s� olu�turuluyor
{
	//Struct alanlar� tan�mlan�yor
	ImeiNo imei;
	char* telno ;
	//Fonksiyon g�stericisi tan�mlan�yor
	void (*Yoket)(struct TELEFON*);
};
typedef struct TELEFON* Telefon;
//TELEFON yap� i�aret�isinin ismi Telefon olarak atan�yor

Telefon TelefonOlustur(int);	//yap�c� method tan�mlan�yor
//K�t�phane fonksiyonlar� tan�mlan�yor
char* random_telno(int);
void TelefonYoket(Telefon);

#endif
