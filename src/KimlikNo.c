
#include "KimlikNo.h"


KimlikNo KimlikOlustur(int dosyaboyutu)	//KIMLIKNO yap�s�ndan nesne olu�turan fonksiyon
{
	KimlikNo gosterici;	//KimlikNo tipinde gosterici pointer� olu�turuluyor
	gosterici = (KimlikNo)calloc(dosyaboyutu,sizeof(struct KIMLIKNO));	//Heap b�lgesinde dosyaboyutu kadar KIMLIKNO struct'� b�y�kl���nde yer a��l�yor
	// Her bir KIMLIKNO yap�s�n�n alanlar� dolduruluyor
	for (int i = 0; i < dosyaboyutu; i++)
	{
		char* num_heap = (char*)calloc(13, sizeof(char));
		strcpy(num_heap, TCIDOlustur(i));
		(gosterici + i)->Kontrol = &isValidTckn;
		(gosterici + i)->Yoket = &KimlikNoYoket;
		(gosterici + i)->tcno = num_heap;
	}
	return gosterici;	//gosterici pointer� d�nd�r�l�yor
}

char* TCIDOlustur(int i) // Rastgele tckimlik numaras� olu�turuluyor
{
	char* num_heap = (char*)calloc(13, sizeof(char));
	srand(time(NULL) + i);	//rastgeleli�i sa�lamak ad�na de�i�ken kullan�l�yor
	char *ara_donusturucu = (char*)malloc(sizeof(char));
	char numlist_c[12] = "";
	int numlist[11] = {0};
	numlist[0] = rand() % 9 + 1;
	int numara1 = 0;
	int numara2 = 0;
	for (int i = 1; i < 9; i++)
	{
		int a = rand() % 10;
		numlist[i] = a;
	}

	for (int i = 0; i < 9; i += 2)
		numara1 += numlist[i];

	for (int i = 1; i < 8; i += 2)
		numara2 += numlist[i];

	int sonrakam = (numara1 * 7 - numara2) % 10;
	numlist[9] = sonrakam;
	sonrakam = 0;

	for (int i = 0; i < 10; i++)
		sonrakam += numlist[i];

	sonrakam = sonrakam % 10;

	numlist[10] = sonrakam;

	for (int i = 0; i < 11; i++)
	{
		sprintf(ara_donusturucu, "%d", numlist[i]);
		numlist_c[i] = ara_donusturucu[0];
	}
	strcpy(num_heap, numlist_c);
	return num_heap;
	
}

bool isValidTckn(char* giris) //tckimlik numaras�n�n do�rulu�u kontrol ediliyor

{
	char* input = giris;
	char input_a[12];
	strcpy(input_a, input);

	if (input_a[10] == '\0')
		return false;
	int totalOdd = 0;
	int totalEven = 0;
	for (int i = 0; i < 9; i++)
	{
		int val = input_a[i] - '0';
		if (i % 2 == 0)
		{
			totalOdd += val;
		}
		else
		{
			totalEven += val;
		}
	}

	int total = totalOdd + totalEven + input_a[9] - '0';
	int lastDigit = total % 10;
	if (input_a[10] - '0' == lastDigit)
	{
		int check = (totalOdd * 7 - totalEven) % 10;
		if (input_a[9] - '0' == check)
		{
			return true;
		}
	}
	return false;


}

void KimlikNoYoket(KimlikNo nesne) //��p toplay�c� fonksiyon
{
	if (nesne == NULL) return;
	free(nesne);
}