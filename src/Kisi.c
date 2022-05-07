/**
*
* @author Mehmetali Demirtas mehmetali.demirtas@ogr.sakarya.edu.tr
* @since 20.04.2022
* <p>
* 	Kişilerin oluşturulduğu sınıf.
* </p>
*/
#include "Kisi.h"

Kisi KisiKurucuFonksiyon(char *ad,double para, float oran,int oynanan){ // Kisi kurucu fonksiyonu
    Kisi this = (Kisi)malloc(sizeof(struct KISI)); //Kişi için bellekten yer açılıyor
    this->ad = (char*)malloc(sizeof(char)*(strlen(ad)+1)); //Kişi adı için bellekten yer açılıyor.
    strcpy(this->ad, ad); //Okunan adın atama işlemi yapılıyor.
    this->para = para; 
    this->oran = oran;
    this->oynanan = oynanan;
    if(para >= 1000) //Kişinin parası 1000 den fazla ise oyunu oynayabilir.
        this->oyundaMi = true;
    else
        this->oyundaMi = false;
    this->kisiyiEkranaBas = &KisiyiEkranaBas;
    this->kisiYikiciFonksiyon = &KisiYikiciFonksiyon;
    return this;
}
void KisiyiEkranaBas(const Kisi this){ // Kisi bilgilerini ekrana basan fonksiyon
    printf("%s %lf %f %d\n", this->ad, this->para, this->oran, this->oynanan);
}
void KisiYikiciFonksiyon(Kisi this){ // Kisi yıkıcı fonksiyonu
    if(this){
        if(this->ad)
            free(this->ad);
        free(this);
    }
}