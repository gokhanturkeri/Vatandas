
#ifndef RASTGELEKISI_H	//RASTGELEKISI kütüphanesi tanımlanıyor
#define RASTGELEKISI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Kisi.h"
#include "ImeiNo.h"
#include "KimlikNo.h"

struct RASTGELEKISI	//RASTGELEKISI yapısı oluşturuluyor
{
	//Fonksiyon göstericileri tanımlanıyor
	int(*Olustur)(); 
	int(*Kontrol)();	
	void(*Yoket)(struct RASTGELEKISI*); 
};

typedef struct RASTGELEKISI* RastgeleKisi;
//RASTGELEKISI yapı işaretçisinin ismi RastgeleKisi olarak atanıyor

RastgeleKisi RastgeleKisiOlustur(); //yapıcı method tanımlanıyor
//Kütüphane fonksiyonları tanımlanıyor
int _Olustur();
int dosya_yaz(char**, char**, int);
int _Kontrol();
void kontrol_alt(char**, char**,int);
void RastgelekisiYoket(RastgeleKisi);


#endif