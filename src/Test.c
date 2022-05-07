/**
*
* @author Mehmetali Demirtas mehmetali.demirtas@ogr.sakarya.edu.tr
* @since 28.04.2022
* <p>
* 	Dosyaların okunduğu ve oyunun başladığı main sınıfı.
* </p>
*/
#include <stdio.h>
#include "Dosya.h"
#include "Oyun.h"

int main(int argc, char **argv)
{
    Dosya kisiDosyasi = DosyaKurucuFonksiyon("Kisiler.txt", "./doc/Kisiler.txt"); //Kişiler okunuyor ve bellekte yer ayrılıyor.
    Kisi* kisiler = (Kisi*)malloc(sizeof(Kisi)*kisiDosyasi->satir);
    kisiDosyasi->kisilerOku(kisiDosyasi, kisiler);
    
    Dosya sayiDosyasi = DosyaKurucuFonksiyon("Sayilar.txt", "./doc/Sayilar.txt"); // Sayılar okunuyor.
    int sayilar[sayiDosyasi->satir];
    sayiDosyasi->sayilarOku(sayiDosyasi, sayilar);
    
    int oyundakiKisiSayisi = kisiDosyasi->satir; //Oyundaki kişi sayısı hesaplanıyor.
    for(int i=0; i<kisiDosyasi->satir; i++){
        if(kisiler[i]->oyundaMi == false)
            oyundakiKisiSayisi--;
    }
    
    //Oyun başlatılıyor ve sonuç ekrana yazılıyor. En son olarak yıkma işlemleri gerçekleştiriliyor.
    Oyun oyun = OyunKurucuFonksiyon(kisiler, sayilar, kisiDosyasi->satir, sayiDosyasi->satir, oyundakiKisiSayisi);
    oyun->oyunuBaslat(oyun);
    oyun->oyunSonucunuYaz(oyun);
    oyun->oyunYikiciFonksiyon(oyun);
    kisiDosyasi->dosyaYikiciFonksiyon(kisiDosyasi);
    sayiDosyasi->dosyaYikiciFonksiyon(sayiDosyasi);
    // Not: Kisiler ve sayilar oyun yıkıcısı içerisinde yıkıma uğradı.
    
    return 0;
}
