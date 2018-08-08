

#include "Telefon.h"

Telefon TelefonOlustur(int dosyaboyutu) //TELEFON yapýsýndan nesne oluþturan fonksiyon
{
	Telefon gosterici;	//Telefon tipinde gosterici pointerý oluþturuluyor
	gosterici = (Telefon)calloc(dosyaboyutu,sizeof(struct TELEFON));//Heap bölgesinde dosyaboyutu kadar TELEFON struct'ý büyüklüðünde yer açýlýyor
	ImeiNo imei_p = imeiOlustur(dosyaboyutu); //imeiolustur fonksiyonu döndürülüyor
	// Her bir TELEFON yapýsýnýn alanlarý dolduruluyor
	for (int i = 0; i < dosyaboyutu; i++)
	{
		char* telno_heap = (char*)malloc(13 * sizeof(char));
		telno_heap = random_telno(i);
		(gosterici + i)->telno = telno_heap;
		(gosterici + i)->imei = (imei_p + i);
		(gosterici + i)->Yoket = &TelefonYoket;
	}
	return gosterici; //gosterici pointerýnýn adresi döndürülüyor
}

char* random_telno(int i)
{
	char* telno_heap = (char*)malloc(13 * sizeof(char));
	srand(time(NULL) + i);	//rastgeleliði saðlamak adýna deðiþken kullanýlýyor
	long telno = 0;
	//Rastgele numaralar telefon numarasý alanlarýna atanýyor
	int operator_kodu = rand() % 30 + 530;
	int area1 = rand() % 900 + 100;
	int area2 = rand() % 9000 + 1000;
	//char tipine dönüþüm için char deðiþkenleri oluþturuluyor
	char operator_kodu2[5];
	char area1_2[5];
	char area2_2[5];
	//döndürülecek olan char pointerý oluþturuluyor ve telefon numarasý 0 ile baþlýyor
	char telno_c[12] = "0";
	//int tipindeki telefon alanlarý char tipine dönüþtürülüyor
	sprintf(operator_kodu2, "%d", operator_kodu);
	sprintf(area1_2, "%d", area1);
	sprintf(area2_2, "%d", area2);
	//tüm telefon numarasý alanlarý birbirine ekleniyor
	strcat(telno_c, operator_kodu2);
	strcat(telno_c, area1_2);
	strcat(telno_c, area2_2);
	//oluþturulan telefon numarasý döndürülüyor
	strcpy(telno_heap, telno_c);
	return telno_heap;
}

void TelefonYoket(Telefon nesne) //Çöp toplayýcý fonksiyon
{
	if (nesne == NULL) return;
	if (nesne->imei != NULL) nesne->imei->Yoket(nesne->imei);
	free(nesne);
}