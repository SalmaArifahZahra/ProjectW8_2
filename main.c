#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/boolean.h"
#include "../header/mainbody.h"
#include "../header/kota.h"


int main() {
    Kota *pilihkota;
    infotype namakotalama, namakotabaru;
    addresskota PrecKota;  
    int jumlahkota;
    int running = 1;

    infotype nama, namalama;
    addressorg Prec;  
    int jumlah;

    int pil, indexkota, pil2;

    ListKota listkota;  

    CreateList(&listkota);

    while (running) {
        pilihkota = NULL;
        
        printf("\n=============================== Menu Kota ================================\n");
        printf("1.  Tambah Kota Depan         5.  Hapus Kota Belakang       9.  Jumlah Kota\n");
        printf("2.  Tambah Kota Belakang      6.  Hapus Kota Tertentu       10. Kelola Data Orang\n");
        printf("3.  Tambah Kota Tertentu      7.  Hapus Semua Kota          11. Keluar\n");
        printf("4.  Hapus Kota Depan          8.  Tampilkan Kota\n");
        printf("Pilih : ");        
        scanf("%d", &pil);
        printf("\n===========================================================================\n");

        while (getchar() != '\n');

        printf("\n===========================================================================\n");
        switch (pil) {
        case 1:
            printf("Masukkan Nama Kota: ");
            fgets(namakotabaru, 100, stdin);
            namakotabaru[strcspn(namakotabaru, "\n")] = 0;
            
            InsFirstKota(&listkota, namakotabaru);
                 printf("\n===========================================================================\n");
            break;

        case 2:
            printf("Masukkan Nama Kota: ");
            fgets(namakotabaru, 100, stdin);
            namakotabaru[strcspn(namakotabaru, "\n")] = 0;
            
            InsLastKota(&listkota, namakotabaru);
                 printf("\n===========================================================================\n");
            break;

        case 3:
            PrintInfoKota(listkota);
            if(ListKotaEmpty(listkota)) {
                printf("List Kosong\n");
                printf("========================= \n");
                break;
            } else {
                printf("Masukan Setelah Kota : ");
                fgets(namakotalama, 100, stdin);
                namakotalama[strcspn(namakotalama, "\n")] = 0;

                PrecKota = SearchKota(listkota, namakotalama);

                printf("Masukkan Nama Kota : ");
                fgets(namakotabaru, 100, stdin);
                namakotabaru[strcspn(namakotabaru, "\n")] = 0;

                InsAfterKota(&listkota, namakotabaru, PrecKota);
            }
                 printf("\n===========================================================================\n");
            break;

        case 4:
            DelFirstKota(&listkota, &namakotalama);
            printf("Data yang dihapus : %s\n", namakotalama);
            printf("========================= \n");
            break;

        case 5:
            DelLastKota(&listkota, &namakotalama);
            printf("Data yang dihapus : %s\n", namakotalama);
            printf("========================= \n");
            break;

        case 6:
            if(ListKotaEmpty(listkota)) {
                printf("List Kosong\n");
                printf("========================= \n");
                break;
            } else {
                PrintInfoKota(listkota);
                printf("Masukan Nama Kota : ");
                fgets(namakotabaru, 100, stdin);
                namakotabaru[strcspn(namakotabaru, "\n")] = 0;
                DelPKota(&listkota, namakotabaru);
                printf("========================= \n");
            }
            break;

        case 7:
            DelAllKota(&listkota);
            printf("Semua data berhasil dihapus\n");
            printf("========================= \n");
            break;

        case 8:
            PrintInfoKota(listkota);
            break;

        case 9:
            jumlahkota = HitungJumlahKota(listkota);
            printf("Jumlah Kota Sebanyak = %d\n", jumlahkota);
            printf("========================= \n");
            break;

        case 10:
            PrintInfoKota(listkota);
            printf("Pilih kota (1-10) : ");
            scanf("%d", &indexkota);
            if (indexkota < 1 || indexkota > HitungJumlahKota(listkota)) {
                printf("Kota tidak valid\n");
                     printf("\n===========================================================================\n");
                break;
            }

            pilihkota = GetKotaKe(listkota, indexkota);
            
            printf("========================= \n");
            printf("kota terpilih : %s\n", NamaKota(pilihkota));
            printf("========================= \n");

            int submenu = 1;
            while (submenu) {
                printf("\n============================= Menu Data Orang =============================\n");
                printf("1. Tambah Orang Depan      5. Hapus Orang Belakang     9. Jumlah Orang\n");
                printf("2. Tambah Orang Belakang   6. Hapus Orang Tertentu    10. Kembali\n");
                printf("3. Tambah Orang Tertentu   7. Hapus Semua Orang\n");
                printf("4. Hapus Orang Depan       8. Tampilkan Orang\n");
                printf("Pilih : ");                            
                scanf("%d", &pil2);
                while (getchar() != '\n');

                     printf("\n===========================================================================\n");
        
                switch (pil2) {
                    case 1:
                        printf("Masukkan Nama: ");
                        fgets(nama, 100, stdin);
                        nama[strcspn(nama, "\n")] = 0;
                        InsFirst(pilihkota, nama);
                             printf("\n===========================================================================\n");
                        break;

                    case 2:
                        printf("Masukkan Nama: ");
                        fgets(nama, 100, stdin);
                        nama[strcspn(nama, "\n")] = 0;
                        InsLast(pilihkota, nama);
                             printf("\n===========================================================================\n");
                        break;

                    case 3:
                        PrintInfo(*pilihkota);
                        if(ListEmpty(*pilihkota)) {
                            printf("List Kosong\n");
                            printf("========================= \n");
                            break;
                        } else {
                            printf("Masukan Setelah : ");
                            fgets(namalama, 100, stdin);
                            namalama[strcspn(namalama, "\n")] = 0;
                            Prec = Search(*pilihkota, namalama);
                            printf("Masukkan Nama: ");
                            fgets(nama, 100, stdin);
                            nama[strcspn(nama, "\n")] = 0;
                            InsAfter(nama, Prec);
                        }
                             printf("\n===========================================================================\n");
                        break;

                    case 4:
                        DelFirst(pilihkota, &namalama);
                        printf("Data yang dihapus : %s\n", namalama);
                        printf("========================= \n");
                        break;

                    case 5:
                        DelLast(pilihkota, &namalama);
                        printf("Data yang dihapus : %s\n", namalama);
                        printf("========================= \n");
                        break;

                    case 6:
                        PrintInfo(*pilihkota);
                        if(ListEmpty(*pilihkota)) {
                            printf("List Kosong\n");
                            printf("========================= \n");
                            break;
                        } else {
                            printf("Masukan Nama : ");
                            fgets(namalama, 100, stdin);
                            namalama[strcspn(namalama, "\n")] = 0;
                            DelP(pilihkota, namalama);
                            printf("========================= \n");
                        }
                        break;

                    case 7:
                        DelAll(pilihkota);
                        printf("Semua data berhasil dihapus\n");
                        printf("========================= \n");
                        break;

                    case 8:
                        PrintInfo(*pilihkota);
                        break;

                    case 9:
                        jumlah = Initorg(*pilihkota);
                        printf("Jumlah orang : %d\n", jumlah);
                        printf("========================= \n");
                        break;

                    case 10:
                        submenu = 0;
                        break;
                }
            }
            break;

        case 11:
            running = 0;
            break;
        }
    }
    
    return 0;
}