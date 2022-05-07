/**
*
* @author Mehmetali Demirtas mehmetali.demirtas@ogr.sakarya.edu.tr
* @since 18.04.2022
* <p>
* 	Dosya okumak için gerekli header sınıfı
* </p>
*/
#ifndef DOSYA_H
#define DOSYA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Kisi.h"

struct DOSYA{ // Kisiler.txt den kişileri ve Sayilar.txt den sayıları okumak için gerekli yapılar tanımlanmıştır.
	void (*kisilerOku)(struct DOSYA*, Kisi*);
    void (*sayilarOku)(struct DOSYA*,int*);
    void (*dosyaYikiciFonksiyon)(struct DOSYA*);
	
    char* ad, *yol; //dosya adı ve dosya yolu için tanımlandı.
    int satir; // satır sayısını bulmak için tanımlandı.
};
typedef struct DOSYA* Dosya;

//Dosyayı okumak ve gerekli işlemleri yapmak için tanımlanan fonksiyonlar ve kurucu fonksiyon.
Dosya DosyaKurucuFonksiyon(char*,char*);
void KisilerOku(const Dosya,Kisi*);
void SayilarOku(const Dosya,int*);
void DosyaYikiciFonksiyon(Dosya);

#endif