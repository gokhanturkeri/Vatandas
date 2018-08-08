
#ifndef KISI_H //KISI k�t�phanesi tan�mlan�yor
#define KISI_H

#include "stdio.h"
#include "stdlib.h"
#include "Telefon.h"
#include "KimlikNo.h"

struct KISI //KISI yap�s� olu�turuluyor
{
	//Struct alanlar� tan�mlan�yor
	KimlikNo tcno;
	Telefon telefon;
	char* yas;
	char* isim;
	char* soyisim;
	//Fonksiyon g�stericisi tan�mlan�yor
	void(*Yoket)(struct KISI*);
};

typedef struct KISI* Kisi;
//KISI yap� i�aret�isinin ismi Kisi olarak atan�yor

Kisi KisiOlustur(char**, char**,int);	//yap�c� method tan�mlan�yor
//K�t�phane fonksiyonu tan�mlan�yor
void KisiYoket(Kisi);
#endif
