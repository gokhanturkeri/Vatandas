
#ifndef KIMLIKNO_H //KIMLIKNO kütüphanesi tanýmlanýyor
#define KIMLIKNO_H

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"
#include "time.h"

struct KIMLIKNO //KIMLIKNO yapýsý oluþturuluyor
{
	//Struct alaný tanýmlanýyor
	char* tcno;
	//Fonksiyon göstericileri tanýmlanýyor
	void(*Yoket)(struct KIMLIKNO*);
	bool(*Kontrol)(char*);
};

typedef struct KIMLIKNO* KimlikNo;
//KIMLIKNO yapý iþaretçisinin ismi KimlikNo olarak atanýyor

KimlikNo KimlikOlustur(int);	//yapýcý method tanýmlanýyor
//Kütüphane fonksiyonlarý tanýmlanýyor
char* TCIDOlustur(int);
void KimlikNoYoket(KimlikNo);
bool isValidTckn(char*);
#endif
