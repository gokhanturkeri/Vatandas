

#include "Telefon.h"

Telefon TelefonOlustur(int dosyaboyutu) //TELEFON yap�s�ndan nesne olu�turan fonksiyon
{
	Telefon gosterici;	//Telefon tipinde gosterici pointer� olu�turuluyor
	gosterici = (Telefon)calloc(dosyaboyutu,sizeof(struct TELEFON));//Heap b�lgesinde dosyaboyutu kadar TELEFON struct'� b�y�kl���nde yer a��l�yor
	ImeiNo imei_p = imeiOlustur(dosyaboyutu); //imeiolustur fonksiyonu d�nd�r�l�yor
	// Her bir TELEFON yap�s�n�n alanlar� dolduruluyor
	for (int i = 0; i < dosyaboyutu; i++)
	{
		char* telno_heap = (char*)malloc(13 * sizeof(char));
		telno_heap = random_telno(i);
		(gosterici + i)->telno = telno_heap;
		(gosterici + i)->imei = (imei_p + i);
		(gosterici + i)->Yoket = &TelefonYoket;
	}
	return gosterici; //gosterici pointer�n�n adresi d�nd�r�l�yor
}

char* random_telno(int i)
{
	char* telno_heap = (char*)malloc(13 * sizeof(char));
	srand(time(NULL) + i);	//rastgeleli�i sa�lamak ad�na de�i�ken kullan�l�yor
	long telno = 0;
	//Rastgele numaralar telefon numaras� alanlar�na atan�yor
	int operator_kodu = rand() % 30 + 530;
	int area1 = rand() % 900 + 100;
	int area2 = rand() % 9000 + 1000;
	//char tipine d�n���m i�in char de�i�kenleri olu�turuluyor
	char operator_kodu2[5];
	char area1_2[5];
	char area2_2[5];
	//d�nd�r�lecek olan char pointer� olu�turuluyor ve telefon numaras� 0 ile ba�l�yor
	char telno_c[12] = "0";
	//int tipindeki telefon alanlar� char tipine d�n��t�r�l�yor
	sprintf(operator_kodu2, "%d", operator_kodu);
	sprintf(area1_2, "%d", area1);
	sprintf(area2_2, "%d", area2);
	//t�m telefon numaras� alanlar� birbirine ekleniyor
	strcat(telno_c, operator_kodu2);
	strcat(telno_c, area1_2);
	strcat(telno_c, area2_2);
	//olu�turulan telefon numaras� d�nd�r�l�yor
	strcpy(telno_heap, telno_c);
	return telno_heap;
}

void TelefonYoket(Telefon nesne) //��p toplay�c� fonksiyon
{
	if (nesne == NULL) return;
	if (nesne->imei != NULL) nesne->imei->Yoket(nesne->imei);
	free(nesne);
}