
#include "Kisi.h"

Kisi KisiOlustur(char** isim, char** soyisim,int dosyaboyutu)	//Kisi yapýsýndan nesne oluþturan fonksiyon

{
	Kisi gosterici;	//Kisi tipinde gosterici pointerý oluþturuluyor
	gosterici = (Kisi)calloc(dosyaboyutu, sizeof(struct KISI));	//Heap bölgesinde dosyaboyutu kadar KISI struct'ý büyüklüðünde yer açýlýyor
	Telefon tel = TelefonOlustur(dosyaboyutu); //Telefon'un gösterdiði TELEFON structý oluþturuluyor
	KimlikNo tcno = KimlikOlustur(dosyaboyutu); //KimlikNo'nun gösterdiði KÝMLÝKNO structý oluþturuluyor

	// Her bir KISI yapýsýnýn alanlarý dolduruluyor
	for (int i = 0; i < dosyaboyutu; i++)
	{
		char* yas = (char*)malloc(3 * sizeof(char));
		sprintf(yas, "%d", rand() % 100);
		(gosterici + i)->yas = yas;
		(gosterici + i)->isim = isim[i];
		(gosterici + i)->soyisim = soyisim[i];
		(gosterici + i)->telefon = (tel + i);
		(gosterici + i)->tcno = (tcno + i);
		(gosterici + i)->Yoket = &KisiYoket;
	}
	
	//Heapte açýlmýþ isim ve soyisimleri gösteren göstericiler null'u gösteriyor
		free(isim);
		free(soyisim);
	
	return gosterici;	// gosterici pointerý döndürülüyor
}


void KisiYoket(Kisi nesne) //Çöp toplayýcý fonksiyon
{
	if (nesne == NULL) return;
	if (nesne->tcno != NULL) nesne->tcno->Yoket(nesne->tcno);
	if (nesne->telefon != NULL) nesne->telefon->Yoket(nesne->telefon);
	free(nesne);
}