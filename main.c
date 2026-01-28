#include <stdio.h>
#include <stdlib.h>

#define MAX_GUN 100

int tyt_soru[MAX_GUN];
int ayt_soru[MAX_GUN];
float calisma_saati[MAX_GUN];
int toplam_veri_sayisi = 0;

// fonksiyon prototipleri
void veriOku();
void menuGoster();
void verileriListele();
void veriEkle();
void toplamVeOrtalama();
void minMaxAnaliz();
void esikDegerAnalizi();
void ozelAnaliz();

int main() {
    int secim;

    veriOku();

    if (toplam_veri_sayisi == 0) {
        printf("HATA: Veri okunmadi veya dosya bos! Program kapatiliyor.\n");
        return 1;
    }

    do {
        menuGoster();
        printf("\nSeciminiz: ");
        scanf("%d", &secim);
        printf("\n");

        switch (secim) {
            case 1: verileriListele(); break;
            case 2: veriEkle(); break;
            case 3: toplamVeOrtalama(); break;
            case 4: minMaxAnaliz(); break;
            case 5: esikDegerAnalizi(); break;
            case 6: ozelAnaliz(); break;
            case 0: printf("Programdan cikiliyor...\n"); break;
            default: printf("Hatali secim! Lutfen tekrar deneyin.\n");
        }
    } while (secim != 0);

    return 0;
}


void veriOku() {
    FILE *dosya = fopen("data.txt", "r");

    if (dosya == NULL) {
        printf("Veri dosyasi bulunamadi!\n");
        return;
    }

    // dosyayi EOF gelene kadar okur
    while (fscanf(dosya, "%d %d %f", &tyt_soru[toplam_veri_sayisi], &ayt_soru[toplam_veri_sayisi], &calisma_saati[toplam_veri_sayisi]) != EOF) {
        toplam_veri_sayisi++;

        // dizinin tasmasini engeller
        if(toplam_veri_sayisi >= MAX_GUN) break;
    }

    fclose(dosya);
    printf("--> %d gunluk veri basariyla yuklendi.\n", toplam_veri_sayisi);
}

void menuGoster() {
    printf("\n\n");
    printf("====================================================\n");
    printf("             YKS CALISMA TAKIP SISTEMI              \n");
    printf("====================================================\n");
    printf("1 - Tum Veriyi Listele\n");
    printf("2 - Dosyaya Veri Ekle\n");
    printf("3 - Toplam ve Ortalama Degerleri Goster\n");
    printf("4 - En Yuksek ve En Dusuk Calisma Suresi\n");
    printf("5 - Esik Degerine Gore Soru Analizi\n");
    printf("6 - Ozel Analiz: Gunluk Verimlilik Puani\n");
    printf("0 - Cikis\n");
    printf("----------------------------------------------------\n");
}

void verileriListele() {
    printf("\n%-5s %-15s %-15s %-15s\n", "Gun", "TYT Soru", "AYT Soru", "Sure (Saat)");
    printf("----------------------------------------------------\n");

    for (int i = 0; i < toplam_veri_sayisi; i++) {
        printf("%-5d %-15d %-15d %-15.1f\n", i + 1, tyt_soru[i], ayt_soru[i], calisma_saati[i]);
    }
}

void veriEkle(){
    FILE *dosya = fopen("data.txt", "a");

    if (dosya == NULL){
        printf("Dosya hatasi!\n");
        return;
    }

    int tyt, ayt;
    float sure;

    printf("Bugun cozulen TYT soru sayisi: ");
    scanf("%d", &tyt);

    printf("Bugun cozulen AYT soru sayisi: ");
    scanf("%d", &ayt);

    printf("Bugun calisilan sure (Saat): ");
    scanf("%f", &sure);

    fprintf(dosya, "\n%d %d %.2f", tyt, ayt, sure);

    fclose(dosya);

    printf("Veriler dosyaya kaydedildi! Listede gorunmesi icin programi yeniden baslatabilirsiniz.\n");
}

void toplamVeOrtalama() {
    long toplamTYT = 0;
    long toplamAYT = 0;
    float toplamSaat = 0.0;

    for (int i = 0; i < toplam_veri_sayisi; i++) {
        toplamTYT += tyt_soru[i];
        toplamAYT += ayt_soru[i];
        toplamSaat += calisma_saati[i];
    }

    printf("\n--------------- GENEL ISTATISTIKLER ----------------\n");
    printf("Toplam Gun Sayisi: %d\n", toplam_veri_sayisi);
    printf("Toplam Cozulen TYT: %ld (Ort: %.2f)\n", toplamTYT, (float)toplamTYT / toplam_veri_sayisi);
    printf("Toplam Cozulen AYT: %ld (Ort: %.2f)\n", toplamAYT, (float)toplamAYT / toplam_veri_sayisi);
    printf("Toplam Calisma Saati: %.2f (Ort: %.2f)\n", toplamSaat, toplamSaat / toplam_veri_sayisi);
}

void minMaxAnaliz() {
    float maxSure = calisma_saati[0];
    float minSure = calisma_saati[0];
    int maxGun = 0, minGun = 0;

    for (int i = 1; i < toplam_veri_sayisi; i++) {
        if (calisma_saati[i] > maxSure) {
            maxSure = calisma_saati[i];
            maxGun = i;
        }
        if (calisma_saati[i] < minSure) {
            minSure = calisma_saati[i];
            minGun = i;
        }
    }

    printf("\n---------- EN YUKSEK & EN DUSUK CALISMA ------------\n");
    printf("En Cok Calisilan Gun: %d. Gun (%.2f Saat)\n", maxGun + 1, maxSure);
    printf("En Az Calisilan Gun : %d. Gun (%.2f Saat)\n", minGun + 1, minSure);
}

void esikDegerAnalizi() {
    int esik;
    int sayac = 0;

    printf("\nGunluk toplam en az kac soru cozulen gunleri ariyorsunuz?: ");
    scanf("%d", &esik);

    printf("\n-------------- %d SORU BARAJI ANALIZI --------------\n", esik);
    for (int i = 0; i < toplam_veri_sayisi; i++) {
        int gunlukToplam = tyt_soru[i] + ayt_soru[i];
        if (gunlukToplam >= esik) {
            printf("%d. Gun: %d Soru (TYT:%d, AYT:%d)\n", i+1, gunlukToplam, tyt_soru[i], ayt_soru[i]);
            sayac++;
        }
    }

    if (sayac == 0)
        printf("Bu kriterlere uygun gun bulunamadi.\n");
    else
        printf("Toplam %d gun hedefe ulasildi.\n", sayac);
}


// verimlilik : 1 saatte cozulen soru sayisi
// bir gunde 40 soru ve fazlasi cozulmusse verimli, degilse verimsiz
void ozelAnaliz() {
    printf("\n------ GUNLUK VERIMLILIK ANALIZI (Soru/Saat) -------\n");

    for (int i = 0; i < toplam_veri_sayisi; i++) {
        if (calisma_saati[i] == 0) continue; // 0'a bolmeyi engeller

        int toplamSoru = tyt_soru[i] + ayt_soru[i];
        float hiz = toplamSoru / calisma_saati[i];

        printf("%d. Gun Hizi: %.1f soru/saat -> ", i + 1, hiz);

        if (hiz >= 40.0) {
            printf("VERIMLI\n");
        } else {
            printf("HIZLANMALISIN\n");
        }
    }
}
