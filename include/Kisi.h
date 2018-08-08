
#ifndef KISI_H //KISI kütüphanesi tanýmlanýyor
#define KISI_H

#include "stdio.h"
#include "stdlib.h"
#include "Telefon.h"
#include "KimlikNo.h"

struct KISI //KISI yapýsý oluþturuluyor
{
	//Struct alanlarý tanýmlanýyor
	KimlikNo tcno;
	Telefon telefon;
	char* yas;
	char* isim;
	char* soyisim;
	//Fonksiyon göstericisi tanýmlanýyor
	void(*Yoket)(struct KISI*);
};

typedef struct KISI* Kisi;
//KISI yapý iþaretçisinin ismi Kisi olarak atanýyor

Kisi KisiOlustur(char**, char**,int);	//yapýcý method tanýmlanýyor
//Kütüphane fonksiyonu tanýmlanýyor
void KisiYoket(Kisi);
#endif
