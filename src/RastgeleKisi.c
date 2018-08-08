

#include "RastgeleKisi.h"

RastgeleKisi RastgeleKisiOlustur()	//RASTGELEKISI yapýsýndan nesne oluþturan fonksiyon
{
	RastgeleKisi gosterici;	//RastgeleKisi tipinde gosterici pointerý oluþturuluyor
	gosterici = (RastgeleKisi)malloc(sizeof(struct RASTGELEKISI));	//Heap bölgesinde RASTGELEKISI struct'ý büyüklüðünde yer açýlýyor
	//gösterici fonksiyonlarýna kütüphane fonksiyonlarý atanýyor
	gosterici->Olustur = &_Olustur;
	gosterici->Kontrol = &_Kontrol;
	gosterici->Yoket = &RastgelekisiYoket;
	//gosterici döndürülüyor
	return gosterici;
}

int _Olustur()	//random_isimler.txt'den isim ve soyisimler alýnýyor
{
	int dosyaboyutu = 0;
	//Heap bölgesinde char pointerlarý tutan pointerlar tanýmlanýyor ve büyüklük olarak 15000 adet char* alacaklarý þekilde açýlýyor
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
	//Dosya tanýmlama ve açma iþlemleri
	FILE *fp;
	char str[100];
	char* filename = "random_isimler.txt";
	fp = fopen(filename, "r");			//Dosya sadece okunabilecek þekilde açýlýyor
	if (fp == NULL) {
		printf("Could not found file %s\n", filename);
		return 0;
	}
	
	//Dosya'da tüm satýrlar geziliyor
	while (fgets(str, 100, fp) != NULL)
	{
		
		char *isim = (char*)malloc(30*sizeof(char));
		char *soyisim = (char*)malloc(30 * sizeof(char));
		//Her bir satýr isim ve soyisim olarak ayýrýlýp pointer to pointerlara yazýlýyor
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
	
	dosya_yaz(isim2, soyisim2,dosyaboyutu);	//dosya_yaz fonksiyonu çaðrýlýyor
	fclose(fp);	//Açýlan dosya kapanýyor
	return 0;
}

int dosya_yaz(char** isim, char** soyisim, int dosyaboyutu)		//Kisi structýnýn bilgileri Kisiler.txt dosyasýna yazýlýyor

{
	//Kisileri tutan pointer oluþturuluyor
	Kisi k = KisiOlustur(isim, soyisim,dosyaboyutu);
	//Dosya tanýmlama ve açma iþlemleri
	FILE *fp;
	char* filename = "Kisiler.txt";
	fp = fopen(filename, "w");			//Dosya sadece yazýlabilir olarak açýlýyor
	if (fp == NULL) {
		printf("Could not found file %s\n", filename);
		return 0;
	}
	
	//Açýlan dosyaya satýr satýr kiþi bilgileri yazýlýyor
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

	//kisileri tutan pointer null tanýmlanýyor
	k->Yoket(k);
	return 0;
}


int _Kontrol()			//Kisiler.txt dosyasýndan tüm kiþilerin tc ve imei numarasý bilgileri alýnýyor
{
	int dosyaboyutu = 0;
	//Heap bölgesinde char pointerlarý tutan pointerlar tanýmlanýyor ve büyüklük olarak 15000 adet char* alacaklarý þekilde açýlýyor
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
	//Dosya tanýmlama ve açma iþlemleri
	FILE *fp;
	char str[100];
	char* filename = "Kisiler.txt";
	fp = fopen(filename, "r");		//Dosya sadece okunabilecek þekilde açýlýyor
	if (fp == NULL) {
		printf("Could not found file %s\n", filename);
		return 0;
	}
	//Her bir satýr tc ve imei olarak ayýrýlýp pointer to pointerlara yazýlýyor
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
	kontrol_alt(tc2, imei2,dosyaboyutu);	//kontrol_alt fonksiyonu çaðrýlýyor
	fclose(fp);		//Açýlan dosya kapanýyor
	return 0;
}

void kontrol_alt(char** tc , char** imei, int dosyaboyutu)	//imei ve tc no doðruluklarý kontrol ediliyor
{
	//Kontrol fonksiyonlarý için struct pointerlarý oluþturuluyor
	ImeiNo imei2 = imeiOlustur(dosyaboyutu);
	KimlikNo tc2 = KimlikOlustur(dosyaboyutu);
	
	int imei_kontrol_gecerli = 0;
	int imei_kontrol_gecersiz = 0;
	int tcno_kontrol_gecerli = 0;
	int tcno_kontrol_gecersiz = 0;
	
	//Fonksiyonlarýn döndürdüðü deðere göre geçerli veya geçersiz numaralarýn adet deðeri deðiþiyor
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
	//struct pointerlarý null deðerini gösteriyor
	imei2->Yoket(imei2);
	tc2->Yoket(tc2);
}

void RastgelekisiYoket(RastgeleKisi nesne) //Çöp toplayýcý fonksiyon
{
	if (nesne == NULL) return;
	free(nesne);
}