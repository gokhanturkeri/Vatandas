
#include "ImeiNo.h"

ImeiNo imeiOlustur(int dosyaboyutu)	//IMEINO yapýsýndan nesne oluþturan fonksiyon
{
	ImeiNo gosterici;	//ImeiNo tipinde gosterici pointerý oluþturuluyor
	gosterici = (ImeiNo)calloc(dosyaboyutu,sizeof(struct IMEINO)); //Heap bölgesinde dosyaboyutu kadar IMEINO struct'ý büyüklüðünde yer açýlýyor
	// Her bir IMEINO yapýsýnýn alanlarý dolduruluyor
	for (int i = 0; i < dosyaboyutu; i++)
	{
		char* imei_heap = (char*)malloc(20 * sizeof(char));
		imei_heap = generateValidImeiNumber(i);
		(gosterici + i)->imei = imei_heap;
		(gosterici + i)->Kontrol = &isValidIMEI;
		(gosterici + i)->Yoket = &ImeiNoYoket;
	}
	
	return gosterici; //gosterici pointerý döndürülüyor
}


char* generateValidImeiNumber(int i) //Rastgele imei numarasý üretiliyor
{
	char* imei_heap = (char*)malloc(20 * sizeof(char));
	srand(time(NULL)+i);	//rastgeleliði saðlamak adýna deðiþken kullanýlýyor
	char rand_num_c[2];
	char generatedCheckDigit_c[2];
	char imei[17] = "";
	char imeiNumber[16] = "";
	strcat(imeiNumber, "864898034");
	for (int counter = 0; counter < 5; counter++)
	{
		int rand_num = rand() % 8 + 1;
		sprintf(rand_num_c, "%d", rand_num);
		strcat(imeiNumber, rand_num_c);
	}
	int generatedCheckDigit = getCheckDigit(imeiNumber);
	sprintf(generatedCheckDigit_c, "%d", generatedCheckDigit);
	strcat(imei, imeiNumber);
	strcat(imei, generatedCheckDigit_c);
	strcpy(imei_heap, imei);
	return imei_heap;
}

int getCheckDigit(char* input)
{
	int sum = 0;
	int digit;
	for (int counter = 13; counter >= 0; counter--)
	{
		digit = input[counter] - '0';
		if (counter % 2 == 0)
		{
			sum += digit;
		}
		else
		{
			sum += sumUpDigits(digit);
		}
	}
	sum *= 9;
	return sum % 10;
}

int sumUpDigits(int digit)
{


	int sum = 0;
	digit *= 2;
	while (digit > 0)
	{
		sum += digit % 10;
		digit /= 10;

	}
	return sum;

}
int sumDig(int n)
{
	int a = 0;
	while (n > 0)
	{
		a += n % 10;
		n = n / 10;
	}
	return a;
}

bool isValidIMEI(char* giris) //imei numarasýnýn doðruluðu kontrol ediliyor
{

	char* imei = giris;
	char imei_a[16];
	strcpy(imei_a, imei);
	int sum2 = 0;
	if (imei_a[14] == '\0')
		return false;
	int sum = 0;
	for (int i = 0; i < 15; i++)
	{
		if (i % 2 == 0)
			sum2 += imei_a[i] - '0';
		else
			sum += sumDig(2 * (imei_a[i] - '0'));
	}
	sum = sum + sum2;
	return (sum % 10 == 0);
}

void ImeiNoYoket(ImeiNo nesne) //Çöp toplayýcý fonksiyon
{
	if (nesne == NULL) return;
	free(nesne);
}