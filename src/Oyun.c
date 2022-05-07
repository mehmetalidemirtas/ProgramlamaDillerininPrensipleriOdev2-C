/**
*
* @author Mehmetali Demirtas mehmetali.demirtas@ogr.sakarya.edu.tr
* @since 25.04.2022
* <p>
* 	Oyunun oynandığı sınıf. Oyun için gerekli hesaplamalar yapılır ve ekrana yazdırma işlemleri yapılır.
* </p>
*/
#include "Oyun.h"

Oyun OyunKurucuFonksiyon(Kisi* kisiler,int* sayilar,int kisiSayisi,int sayiSayisi, int oyundakiKisiSayisi){ // Oyun kurucu fonksiyonu
    Oyun this = (Oyun)malloc(sizeof(struct OYUN)); //Oyun için bellekten yer ayrılıyor.
    this->kisiler = kisiler;
    this->sayilar = sayilar;
    this->kisiSayisi = kisiSayisi;
    this->sayiSayisi = sayiSayisi;
    this->oyundakiKisiSayisi = oyundakiKisiSayisi;
    this->tur = 1;
    this->masaParasi = 0;
    this->oyunuBaslat = &OyunuBaslat;
    this->oyunSonucunuYaz = &OyunSonucunuYaz;
    this->oyunYikiciFonksiyon = &OyunYikiciFonksiyon;
    return this;
}
void OyunuBaslat(const Oyun this){ // Oyunu baslatan fonksiyon
    int sansliSayi = 0, sayiSinir = 0;
    while(this->oyundakiKisiSayisi > 0){ //Oyunda kişi olana kadar çalışacak while döngüsü
        sansliSayi = this->sayilar[sayiSinir]; //Şanslı sayı ataması yapılıyor.
        Kisi enZenginKisi = KisiKurucuFonksiyon(this->kisiler[0]->ad,this->kisiler[0]->para,0,0); // En zengin kişi için kurucu fonksiyon çağırılıyor.
        for(int i=0; i<this->kisiSayisi; i++){ //Kişi sayısı kadar dönecek olan for döngüsü
            if(this->kisiler[i]->oyundaMi == true){ //Oyuna sadece parası 1000 den fazla olanlar katılacak.
                double yatirilan = this->kisiler[i]->para * this->kisiler[i]->oran; //Kişinin oyuna yatıracağı para hesaplanıyor.
                this->kisiler[i]->para = this->kisiler[i]->para - yatirilan;  //Yatırılan miktar kişinin parasından çıkarılıyor.
                this->masaParasi += yatirilan; //Yatırılan miktar masaya ekleniyor.
                if(this->kisiler[i]->oynanan == sansliSayi){ //Kişi şanslı sayıyı bulduysa yatırılan paranın 10 katı masa parasından kişiye iade ediliyor.
                    this->kisiler[i]->para += (yatirilan*10); 
                    this->masaParasi -= (yatirilan*10);
                }
                if(this->kisiler[i]->para < 1000){ //Kişinin parası 1000 den az ise oyundan çıkarılıyor
                    this->kisiler[i]->oyundaMi = false;
                    this->oyundakiKisiSayisi--;
                }
            }
        }
        for(int i=0; i<this->kisiSayisi; i++){ //En zengin kişi hesaplanıyor. 
            if(this->kisiler[i]->oyundaMi == true){
                if(this->kisiler[i]->para > enZenginKisi->para){ //Oynayan kişi, en sonki en zengin kişiden daha zengin ise kendisi en zengin kişi oluyor,
                // eski zengin kişi bellekten serbest bırakılıyor.
                    free(enZenginKisi->ad);
                    enZenginKisi->ad = (char*)malloc(sizeof(char)*(strlen(this->kisiler[i]->ad)+1));
                    strcpy(enZenginKisi->ad, this->kisiler[i]->ad);
                    enZenginKisi->para = this->kisiler[i]->para;
                }
            }
        }

        //Oyun esnasındaki veriler ekrana basılıyor.
        
        printf("\n\n\n\t\t\t#############################################\n");
        printf("\t\t\t##              SANSLI SAYI: %-4d          ##\n", sansliSayi);
        printf("\t\t\t#############################################\n");
        printf("\t\t\t#############################################\n");
        printf("\t\t\t##              TUR: %-10d            ##\n", this->tur);
        printf("\t\t\t##      MASA BAKIYE: %-19.2lf   ##\n", this->masaParasi);
        printf("\t\t\t##                                         ##\n");
        printf("\t\t\t##-----------------------------------------##\n");
        printf("\t\t\t##              EN ZENGIN KISI             ##\n");
        printf("\t\t\t##              %-27s##\n", enZenginKisi->ad);
        printf("\t\t\t##      BAKIYESI: %-19.2lf      ##\n", enZenginKisi->para);
        printf("\t\t\t##                                         ##\n");
        printf("\t\t\t#############################################\n\n");
        
        Sleep(15);
        //Bir sonraki tura geçiliyor, şanslı sayı değiştriliyor.
        this->tur++; sayiSinir++;
        if(sayiSinir >= this->sayiSayisi) //Şanslı sayı dizisi sona erdiyse baştan başlatılıyor.
            sayiSinir = 0;            
        system("@cls||clear");
        enZenginKisi->kisiYikiciFonksiyon(enZenginKisi);        
    }
    this->tur--;
}
void OyunSonucunuYaz(const Oyun this){ // Oyun sonucunu ekrana basan fonksiyon
    printf("\n\n\n\t\t\t#############################################\n");
    printf("\t\t\t##              TUR: %-19d   ##\n", this->tur);
    printf("\t\t\t##      MASA BAKIYE: %-19.2lf   ##\n", this->masaParasi);
    printf("\t\t\t##                                         ##\n");
    printf("\t\t\t##-----------------------------------------##\n");
    printf("\t\t\t##              OYUN BITTI                 ##\n");
    printf("\t\t\t##                                         ##\n");
    printf("\t\t\t##                                         ##\n");
    printf("\t\t\t##                                         ##\n");
    printf("\t\t\t#############################################\n\n");
}
void OyunYikiciFonksiyon(Oyun this){ // Oyun yıkıcı fonksiyon
    if(this){
        if(this->kisiler){
            for(int i=0; i<this->kisiSayisi; i++){
                this->kisiler[i]->kisiYikiciFonksiyon(this->kisiler[i]);
            }
            free(this->kisiler);
        }
        if(this->sayilar){
            free(this->sayilar);
        }
        free(this);
    }
}