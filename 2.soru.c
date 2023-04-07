#include <stdio.h>
#include <stdlib.h>

/* 
   2. SORUNUN KONUSU : Aðaçtaki Kök deðeri alt düðümlerin toplamýný bulma 
   2. SORU : Size tam olarak 3 düðümden oluþan ikili bir aðacýn kökü verildiðinde, bu deðerin alt düðümlerin(child) toplamý olup olmadýðýný bulun.
*/

// Aðaç düðümü yapýsý tanýmý
struct agacDugumu {
    int veri;
    struct agacDugumu *sol;
    struct agacDugumu *sag;
};

// Yeni bir aðaç düðümü oluþturma fonksiyonu
struct agacDugumu* dugum_olustur(int veri) {
    struct agacDugumu* yeni_dugum = (struct agacDugumu*) malloc(sizeof(struct agacDugumu));
    yeni_dugum->veri = veri;
    yeni_dugum->sol = NULL;
    yeni_dugum->sag = NULL;
    return yeni_dugum;
}

// Ýkili aðaç yapýsý oluþturma fonksiyonu
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

// Ýkili aðaç yapýsýnýn kökünün deðerinin alt düðümlerinin toplamýna eþit olup olmadýðýný kontrol eden fonksiyon
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
	
	printf("2. SORU : Size tam olarak 3 dugumden oluþan ikili bir agacin koku verildiginde, bu degerin alt dugumlerin(child) toplami olup olmadigini bulun.\n");
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
 
