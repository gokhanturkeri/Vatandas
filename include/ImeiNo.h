
#ifndef IMEINO_H //IMEINO kütüphanesi tanýmlanýyor
#define IMEINO_H

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "time.h"
#include "stdbool.h"

struct IMEINO //IMEINO yapýsý oluþturuluyor
{
	//Struct alaný tanýmlanýyor
	char* imei;
	//Fonksiyon göstericileri tanýmlanýyor
	void(*Yoket)(struct IMEINO*);
	bool(*Kontrol)(char*);

};

typedef struct IMEINO* ImeiNo;
//IMEINO yapý iþaretçisinin ismi ImeiNo olarak atanýyor

ImeiNo imeiOlustur(int);	//yapýcý method tanýmlanýyor
//Kütüphane fonksiyonlarý tanýmlanýyor
char* generateValidImeiNumber(int);
int getCheckDigit(char*);
int sumUpDigits(int);
int sumDig(int);
void ImeiNoYoket(ImeiNo);
bool isValidIMEI(char*);
#endif
