

#include "RastgeleKisi.h"

RastgeleKisi RastgeleKisiOlustur()	//RASTGELEKISI yap�s�ndan nesne olu�turan fonksiyon
{
	RastgeleKisi gosterici;	//RastgeleKisi tipinde gosterici pointer� olu�turuluyor
	gosterici = (RastgeleKisi)malloc(sizeof(struct RASTGELEKISI));	//Heap b�lgesinde RASTGELEKISI struct'� b�y�kl���nde yer a��l�yor
	//g�sterici fonksiyonlar�na k�t�phane fonksiyonlar� atan�yor
	gosterici->Olustur = &_Olustur;
	gosterici->Kontrol = &_Kontrol;
	gosterici->Yoket = &RastgelekisiYoket;
	//gosterici d�nd�r�l�yor
	return gosterici;
}

int _Olustur()	//random_isimler.txt'den isim ve soyisimler al�n�yor
{
	int dosyaboyutu = 0;
	//Heap b�lgesinde char pointerlar� tutan pointerlar tan�mlan�yor ve b�y�kl�k olarak 15000 adet char* alacaklar� �ekilde a��l�yor
	char** isim2 = (char**)calloc(15000, sizeof(char*));
	for (int i = 0; i < 15000; i++)
	{
		isim2[i] = (char*)calloc(30, sizeof(char*));
	}
	char** soyisim2 = (char**)calloc(15000, sizeof(char*));
	for (int i = 0; i < 15000; i++)
	{
		soyisim2[i] = (char*)calloc(30, sizeof(char*));
	}
	//Dosya tan�mlama ve a�ma i�lemleri
	FILE *fp;
	char str[100];
	char* filename = "random_isimler.txt";
	fp = fopen(filename, "r");			//Dosya sadece okunabilecek �ekilde a��l�yor
	if (fp == NULL) {
		printf("Could not found file %s\n", filename);
		return 0;
	}
	
	//Dosya'da t�m sat�rlar geziliyor
	while (fgets(str, 100, fp) != NULL)
	{
		
		char *isim = (char*)malloc(30*sizeof(char));
		char *soyisim = (char*)malloc(30 * sizeof(char));
		//Her bir sat�r isim ve soyisim olarak ay�r�l�p pointer to pointerlara yaz�l�yor
		char *token= strtok(str, " ");
		while (token != NULL)
		{
			strcpy(isim,token);
			token = strtok(NULL, " ");
			token = strtok(token, "\n");
			strcpy(soyisim, token);
			token = strtok(NULL, " ");
		}
		isim2[dosyaboyutu] = isim;
		soyisim2[dosyaboyutu] = soyisim;
		dosyaboyutu++;
		
	}
	
	dosya_yaz(isim2, soyisim2,dosyaboyutu);	//dosya_yaz fonksiyonu �a�r�l�yor
	fclose(fp);	//A��lan dosya kapan�yor
	return 0;
}

int dosya_yaz(char** isim, char** soyisim, int dosyaboyutu)		//Kisi struct�n�n bilgileri Kisiler.txt dosyas�na yaz�l�yor

{
	//Kisileri tutan pointer olu�turuluyor
	Kisi k = KisiOlustur(isim, soyisim,dosyaboyutu);
	//Dosya tan�mlama ve a�ma i�lemleri
	FILE *fp;
	char* filename = "Kisiler.txt";
	fp = fopen(filename, "w");			//Dosya sadece yaz�labilir olarak a��l�yor
	if (fp == NULL) {
		printf("Could not found file %s\n", filename);
		return 0;
	}
	
	//A��lan dosyaya sat�r sat�r ki�i bilgileri yaz�l�yor
	for (int i = 0; i < dosyaboyutu; i++)
	{
		char* satir = (char*)malloc(150 * sizeof(char));
		strcpy(satir, (k+i)->tcno->tcno);
		strcat(satir, " ");
		strcat(satir, (k + i)->isim);
		strcat(satir, " ");
		strcat(satir, (k + i)->soyisim);
		strcat(satir, " ");
		strcat(satir, (k+i)->yas);
		strcat(satir, " ");
		strcat(satir, (k + i)->telefon->telno);
		strcat(satir, " ");
		strcat(satir, "(");
		strcat(satir, (k + i)->telefon->imei->imei);
		strcat(satir, ")");
		fprintf(fp, "%s\n", satir);
		free(satir);
	}
	fclose(fp);

	//kisileri tutan pointer null tan�mlan�yor
	k->Yoket(k);
	return 0;
}


int _Kontrol()			//Kisiler.txt dosyas�ndan t�m ki�ilerin tc ve imei numaras� bilgileri al�n�yor
{
	int dosyaboyutu = 0;
	//Heap b�lgesinde char pointerlar� tutan pointerlar tan�mlan�yor ve b�y�kl�k olarak 15000 adet char* alacaklar� �ekilde a��l�yor
	char** tc2 = (char**)calloc(15000, sizeof(char*));
	for (int i = 0; i < 15000; i++)
	{
		tc2[i] = (char*)calloc(30, sizeof(char*));
	}
	char** imei2 = (char**)calloc(15000, sizeof(char*));
	for (int i = 0; i < 15000; i++)
	{
		imei2[i] = (char*)calloc(30, sizeof(char*));
	}
	//Dosya tan�mlama ve a�ma i�lemleri
	FILE *fp;
	char str[100];
	char* filename = "Kisiler.txt";
	fp = fopen(filename, "r");		//Dosya sadece okunabilecek �ekilde a��l�yor
	if (fp == NULL) {
		printf("Could not found file %s\n", filename);
		return 0;
	}
	//Her bir sat�r tc ve imei olarak ay�r�l�p pointer to pointerlara yaz�l�yor
	while (fgets(str, 100, fp) != NULL)
	{

		char *tc = (char*)malloc(30 * sizeof(char));
		char *imei = (char*)malloc(30 * sizeof(char));
		char *token = strtok(str, " ");
		while (token != NULL)
		{
			strcpy(tc, token);
			token = strtok(NULL, " ");
			token = strtok(NULL, " ");
			token = strtok(NULL, " ");
			token = strtok(NULL, " ");
			token = strtok(NULL, " (");
			token = strtok(token, ")\n");
			strcpy(imei, token);
			token = strtok(NULL, " ");
			token = strtok(NULL, "\n");
		}

		tc2[dosyaboyutu] = tc;
		imei2[dosyaboyutu] = imei;
		dosyaboyutu++;
	}
	kontrol_alt(tc2, imei2,dosyaboyutu);	//kontrol_alt fonksiyonu �a�r�l�yor
	fclose(fp);		//A��lan dosya kapan�yor
	return 0;
}

void kontrol_alt(char** tc , char** imei, int dosyaboyutu)	//imei ve tc no do�ruluklar� kontrol ediliyor
{
	//Kontrol fonksiyonlar� i�in struct pointerlar� olu�turuluyor
	ImeiNo imei2 = imeiOlustur(dosyaboyutu);
	KimlikNo tc2 = KimlikOlustur(dosyaboyutu);
	
	int imei_kontrol_gecerli = 0;
	int imei_kontrol_gecersiz = 0;
	int tcno_kontrol_gecerli = 0;
	int tcno_kontrol_gecersiz = 0;
	
	//Fonksiyonlar�n d�nd�rd��� de�ere g�re ge�erli veya ge�ersiz numaralar�n adet de�eri de�i�iyor
	for (int i = 0; i < dosyaboyutu; i++)
	{
		if (imei2->Kontrol(imei[i]) == true)
			{
				tcno_kontrol_gecerli++;
			}
		else
				tcno_kontrol_gecersiz++;

		if (tc2->Kontrol(tc[i]) == true)
			{
			imei_kontrol_gecerli++;
			}
		else
			imei_kontrol_gecersiz++;
	}

	printf("IMEI Kontrol\n");
	printf("%d	Gecerli\n",imei_kontrol_gecerli);
	printf("%d	Gecersiz\n", imei_kontrol_gecersiz);
	printf("%d	Gecerli\n", tcno_kontrol_gecerli);
	printf("%d	Gecersiz\n", tcno_kontrol_gecersiz);
	//struct pointerlar� null de�erini g�steriyor
	imei2->Yoket(imei2);
	tc2->Yoket(tc2);
}

void RastgelekisiYoket(RastgeleKisi nesne) //��p toplay�c� fonksiyon
{
	if (nesne == NULL) return;
	free(nesne);
}