
#ifndef TELEFON_H //TELEFON kütüphanesi tanýmlanýyor
#define TELEFON_H

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"
#include "ImeiNo.h"

struct TELEFON //TELEFON yapýsý oluþturuluyor
{
	//Struct alanlarý tanýmlanýyor
	ImeiNo imei;
	char* telno ;
	//Fonksiyon göstericisi tanýmlanýyor
	void (*Yoket)(struct TELEFON*);
};
typedef struct TELEFON* Telefon;
//TELEFON yapý iþaretçisinin ismi Telefon olarak atanýyor

Telefon TelefonOlustur(int);	//yapýcý method tanýmlanýyor
//Kütüphane fonksiyonlarý tanýmlanýyor
char* random_telno(int);
void TelefonYoket(Telefon);

#endif
