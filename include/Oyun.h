/**
*
* @author Mehmetali Demirtas mehmetali.demirtas@ogr.sakarya.edu.tr
* @since 24.04.2022
* <p>
* 	Oyunu oynamak
* </p>
*/
#ifndef OYUN_H
#define OYUN_H

#include "Kisi.h"
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>

struct OYUN{ /*Dosyadan okunan kişilerden oluşturulan Kişi listesindeki kişilerin sırarı ile
gezilerek oyunun oynanması için gerekli değişkenler ve fonksiyonlar tanımlandı.*/
	void (*oyunuBaslat)(struct OYUN*);
    void (*oyunSonucunuYaz)(struct OYUN*);
    void (*oyunYikiciFonksiyon)(struct OYUN*);
	
    Kisi* kisiler; //Kişi sınıfından oluşturulan işaretçi
    int* sayilar; //Şanslı sayı için oluşturlan işaretçi
    int kisiSayisi, sayiSayisi, oyundakiKisiSayisi, tur; //Oyun için gerekli değişkenler
    double masaParasi;
};
typedef struct OYUN* Oyun;

//Oyunu oynamak için gerekli kurucu fonksiyon ve yardımcı fonksiyonlar tanımlandı.
Oyun OyunKurucuFonksiyon(Kisi*,int*,int,int,int);
void OyunuBaslat(const Oyun);
void OyunSonucunuYaz(const Oyun);
void OyunYikiciFonksiyon(Oyun);

#endif