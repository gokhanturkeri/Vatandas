
#include <stdio.h>
#include <stdlib.h>
#include "Kisi.h"
#include "RastgeleKisi.h"

int main() {

		int secenek = 0; //seçim için değişken oluşturuluyor
		
		RastgeleKisi rk = RastgeleKisiOlustur(); //RastgeleKisi'nin gösterdiği structtan pointer oluşturuluyor
	do {
		system("CLS"); //konsol ekranını siler
		printf("1- Rastgele Kisi Uret\n");
		printf("2- Uretilmis Dosya Kontrol Et\n");
		printf("3- Cikis\n");
		scanf("%d", &secenek); //secenek değişkeni belirleniyor
		switch (secenek)
		{
		case 1:
			
			rk->Olustur(); // Dosya_Yaz methodu çağrılıyor
			system("pause"); // Devam etmek için kullanıcıdan karakter girişi bekleniyor
			break;
		case 2:
			rk->Kontrol();// Dosya_Oku methodu çağrılıyor
			system("pause");
			break;
		}
	} while (secenek != 3); // 3'e basıldığı takdirde program kapanıyor
	
	rk->Yoket(rk); //rk pointerı null'u gösteriyor
	return 0;
}



