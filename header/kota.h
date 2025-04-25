#ifndef KOTA_H
#define KOTA_H

#include "boolean.h"
#include "../header/mainbody.h"
#include <stdio.h>
#include <string.h>

#define Nil NULL
#define NamaKota(P) (P)->nk
#define NextKota(P) (P)->next
#define Head(P) (P)->head
#define First(L) (L).First

typedef struct tKota *addresskota;
typedef struct tKota {
    infotype nk;
    addressorg head;
    addresskota next;
} Kota;

typedef struct {
    addresskota First;
} ListKota;

boolean ListKotaEmpty(ListKota L);
addresskota AlokasiKota(infotype namaKota);
void CreateList(ListKota *L);
void InsFirstKota(ListKota *L, infotype X);
void InsLastKota(ListKota *L, infotype X);
void InsAfterKota(ListKota *L, infotype X, addresskota Prec);
void DelFirstKota(ListKota *L, infotype *X);
void DelLastKota(ListKota *L, infotype *X);
void DelPKota(ListKota *L, infotype X);
void DelAllKota(ListKota *L);
void PrintInfoKota(ListKota L);
addresskota GetKotaKe(ListKota listkota, int index);
int HitungJumlahKota(ListKota L);
addresskota SearchKota(ListKota L, infotype X);
addresskota SearchPrecKota(ListKota L, infotype X);

#endif
