#include <stdio.h>
#include <stdlib.h>

/* 
   2. SORUNUN KONUSU : A�a�taki K�k de�eri alt d���mlerin toplam�n� bulma 
   2. SORU : Size tam olarak 3 d���mden olu�an ikili bir a�ac�n k�k� verildi�inde, bu de�erin alt d���mlerin(child) toplam� olup olmad���n� bulun.
*/

// A�a� d���m� yap�s� tan�m�
struct agacDugumu {
    int veri;
    struct agacDugumu *sol;
    struct agacDugumu *sag;
};

// Yeni bir a�a� d���m� olu�turma fonksiyonu
struct agacDugumu* dugum_olustur(int veri) {
    struct agacDugumu* yeni_dugum = (struct agacDugumu*) malloc(sizeof(struct agacDugumu));
    yeni_dugum->veri = veri;
    yeni_dugum->sol = NULL;
    yeni_dugum->sag = NULL;
    return yeni_dugum;
}

// �kili a�a� yap�s� olu�turma fonksiyonu
struct agacDugumu* agac_olustur() {
    
	int sayi;
    
    printf("Kok dugumun degerini giriniz: ");
    scanf("%d", &sayi);
    printf("\n");
    
    struct agacDugumu* kok = dugum_olustur(sayi);
    printf("Sol cocugun degerini giriniz (veya -2 girerek cocuk yok deyin): ");
    scanf("%d", &sayi);
    printf("\n");
    
    if (sayi != -1) {
        kok->sol = dugum_olustur(sayi);
    }
    
    printf("Sag cocugun degerini giriniz (veya -2 girerek cocuk yok deyin): ");
    scanf("%d", &sayi);
	printf("\n");
	
	if (sayi != -1) {
        kok->sag = dugum_olustur(sayi);
    }
    return kok;
}

// �kili a�a� yap�s�n�n k�k�n�n de�erinin alt d���mlerinin toplam�na e�it olup olmad���n� kontrol eden fonksiyon
int dugumler_toplami(struct agacDugumu *kok) {
    if (kok == NULL) {
        return 0;
    }
    else {
        int sol_toplam = dugumler_toplami(kok->sol);
        int sag_toplam = dugumler_toplami(kok->sag);
        return kok->veri + sol_toplam + sag_toplam;
    }
}

// Ana fonksiyon
int main() {
	
	printf("2. SORU : Size tam olarak 3 dugumden olu�an ikili bir agacin koku verildiginde, bu degerin alt dugumlerin(child) toplami olup olmadigini bulun.\n");
	printf("\n\n");
	
    struct agacDugumu* kok = agac_olustur();
    int toplam = dugumler_toplami(kok);
    
    if (kok->veri == toplam - kok->veri) {
        printf("Kok dugumun degeri, sol ve sag cocuklarinin toplamina esittir.\n");
    }
    else {
        printf("Kok dugumun degeri, sol ve sag cocuklarinin toplamina esit degildir.\n");
    }
    return 0;
}
 
