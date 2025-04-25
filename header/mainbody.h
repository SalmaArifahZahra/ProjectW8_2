#ifndef MAINBODY_H
#define MAINBODY_H

#include "boolean.h"
#include <stdio.h>
#include <string.h>

#define Nil NULL
#define Info(P) (P)->nm
#define Next(P) (P)->next

typedef char infotype[100];
typedef struct tElmtList *addressorg;
typedef struct tElmtList {
    infotype nm;
    addressorg next;
} ElmtList;

typedef struct tKota Kota;

boolean ListEmpty(Kota L);
addressorg Alokasi(infotype X);
void Dealokasi(addressorg P);
addressorg Search(Kota L, infotype X);
addressorg SearchPrec(Kota L, infotype X);
void InsFirst(Kota *L, infotype X);
void InsLast(Kota *L, infotype X);
void DelFirst(Kota *L, infotype *X);
void DelLast(Kota *L, infotype *X);
void InsAfter(infotype X, addressorg Prec);
void DelP(Kota *L, infotype X);
void DelAll(Kota *L);
void PrintInfo(Kota L);
int Initorg(Kota L);

#define HeadKota(L) (L)->head

#endif

