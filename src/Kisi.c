
#include "Kisi.h"

Kisi KisiOlustur(char** isim, char** soyisim,int dosyaboyutu)	//Kisi yap�s�ndan nesne olu�turan fonksiyon

{
	Kisi gosterici;	//Kisi tipinde gosterici pointer� olu�turuluyor
	gosterici = (Kisi)calloc(dosyaboyutu, sizeof(struct KISI));	//Heap b�lgesinde dosyaboyutu kadar KISI struct'� b�y�kl���nde yer a��l�yor
	Telefon tel = TelefonOlustur(dosyaboyutu); //Telefon'un g�sterdi�i TELEFON struct� olu�turuluyor
	KimlikNo tcno = KimlikOlustur(dosyaboyutu); //KimlikNo'nun g�sterdi�i K�ML�KNO struct� olu�turuluyor

	// Her bir KISI yap�s�n�n alanlar� dolduruluyor
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
	
	//Heapte a��lm�� isim ve soyisimleri g�steren g�stericiler null'u g�steriyor
		free(isim);
		free(soyisim);
	
	return gosterici;	// gosterici pointer� d�nd�r�l�yor
}


void KisiYoket(Kisi nesne) //��p toplay�c� fonksiyon
{
	if (nesne == NULL) return;
	if (nesne->tcno != NULL) nesne->tcno->Yoket(nesne->tcno);
	if (nesne->telefon != NULL) nesne->telefon->Yoket(nesne->telefon);
	free(nesne);
}