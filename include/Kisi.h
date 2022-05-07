/**
*
* @author Mehmetali Demirtas mehmetali.demirtas@ogr.sakarya.edu.tr
* @since 18.04.2022
* <p>
* 	Kişi oluşturmak için gerekli header sınıfı
* </p>
*/
#ifndef KISI_H
#define KISI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{
	false,true
} bool;

struct KISI{ ////Dosyadan okunan veriler eşliğinde kişi yapısı içerisinde yer alması gereken değişkenler ve fonksiyonlar tanımlandı.
	void(*kisiyiEkranaBas)(struct KISI*);
	void(*kisiYikiciFonksiyon)(struct KISI*);
	
    char* ad; 
    double para; //Kişinin toplam parası
	float oran; //Her turda oynayacağı para oranı
    int oynanan; //Her turda oynayacağı sayı
    bool oyundaMi; //Bakiye kontrolüne göre (<1000) oynayıp oynamayacağını belirleyen değişken
};
typedef struct KISI* Kisi;

//Gerekli fonksiyonlar tanımlandı.
Kisi KisiKurucuFonksiyon(char*,double,float,int);
void KisiyiEkranaBas(const Kisi);
void KisiYikiciFonksiyon(Kisi);

#endif