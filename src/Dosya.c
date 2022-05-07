/**
*
* @author Mehmetali Demirtas mehmetali.demirtas@ogr.sakarya.edu.tr
* @since 21.04.2022
* <p>
* 	Dosya okumak için sınıf. Dosyadan Kişiler ve Sayılar okunarak gerekli işlemler yapılır.
* </p>
*/
#include "Dosya.h"

Dosya DosyaKurucuFonksiyon(char* ad,char* yol){ // Dosya kurucu fonksiyonu
    Dosya this = (Dosya)malloc(sizeof(struct DOSYA)); //Dosya için bellekte yer ayrılıyor.
    this->ad = ad;
    this->yol = yol;
    this->satir = 0;
    this->kisilerOku = &KisilerOku;
    this->sayilarOku = &SayilarOku;
    this->dosyaYikiciFonksiyon = &DosyaYikiciFonksiyon;
    
    // Dosya satir sayisi okumak icin yazılan kısım.
    FILE* fp;
    int satirUzunluk = 1001;
    char satir[satirUzunluk];
    if((fp = fopen(this->yol, "r")) != NULL){
        while(fgets(satir, satirUzunluk, fp)){
            this->satir++;
        }
    }
    else{
        printf("%s dosyasi acilamadi.\n", this->ad);
    }
    fclose(fp);
    return this;
}
void KisilerOku(const Dosya this,Kisi* kisiler){ // Dosyadan kisiler dizisine okuma yapan fonksiyon
    FILE* fp;
    int satirUzunluk = 1001;
    char satir[satirUzunluk];
    if((fp = fopen(this->yol, "r")) != NULL){
        int i=0;
        while(fgets(satir, satirUzunluk, fp)){
            double para;
			float oran;
            int oynanan;
            char* itr = strtok(satir,"#"); //Okunan satırı bölme işlemi.
            char ad[strlen(itr)+1]; //adın uzunluğu +1 (isim soyisim arası boşluk).
            strcpy(ad,itr); //İlk bölünen kısımm ada kopyalanıyor.
            itr = strtok(NULL, "#");
            para = strtod(itr, NULL); //İkinci bölünen kısım double türündeki paraya atanıyor.
            itr = strtok(NULL, "#"); 
            oran = atof(itr); //Üçüncü bölünen kısım olan float türündeki oynanacak para oranı atanıyor.
            itr = strtok(NULL, "#"); 
            oynanan = atoi(itr); //Son bölünen kısım integer türündeki oynanacak sayı atanıyor.
            kisiler[i] = KisiKurucuFonksiyon(ad, para, oran, oynanan); //Oluşturulan yeni kişi kişiler dizisine atanıyor. 
            i++;
        }
    }
    else{
        printf("%s dosyasi acilamadi.\n", this->ad);
    }
    fclose(fp);
}
void SayilarOku(const Dosya this,int* sayilar){ // Dosyadan sayilar dizisine okuma yapan fonksiyon
    FILE* fp;
    int satirUzunluk = 1001;
    char satir[satirUzunluk];
    if((fp = fopen(this->yol, "r")) != NULL){
        int i=0;
        while(fgets(satir, satirUzunluk, fp)){
            sayilar[i] = atoi(satir); //Okunan sayı, sayilar dizisine atanıyor.
            i++;
        }
    }
    else{
        printf("%s dosyasi acilamadi.\n", this->ad);
    }
    fclose(fp);
}
void DosyaYikiciFonksiyon(Dosya this){ // Dosya yıkıcı fonksiyonu
    if(this) free(this);
}