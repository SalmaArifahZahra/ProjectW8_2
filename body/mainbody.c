#include "../header/mainbody.h"
#include "../header/kota.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

boolean ListEmpty(Kota L) {
    return (HeadKota(&L) == Nil);
}

addressorg Alokasi(infotype X) {
    addressorg P = (addressorg)malloc(sizeof(ElmtList));
    if(P != Nil) {
        strcpy(Info(P), X);
        Next(P) = Nil;
    }
    return P;
}

void Dealokasi(addressorg P) {
    if(P != Nil) {
        free(P);
    }
}

addressorg Search(Kota L, infotype X) {
    addressorg P = HeadKota(&L);
    while(P != Nil) {
        if(strcmp(Info(P), X) == 0) {
            return P;
        }
        P = Next(P);
    }
    return Nil;
}

addressorg SearchPrec(Kota L, infotype X) {
    addressorg P = HeadKota(&L);
    addressorg Prec = Nil;
    boolean found = false;

    while(P != Nil && !found) {
        if(strcmp(Info(P), X) == 0) {
            found = true;
        } else {
            Prec = P;
            P = Next(P);
        }
    }

    return found ? Prec : Nil;
}

void InsFirst(Kota *L, infotype X) {
    addressorg P = Alokasi(X);
    if(P != Nil) {
        Next(P) = HeadKota(L);
        HeadKota(L) = P;
    }
}

void InsLast(Kota *L, infotype X) {
    addressorg P = Alokasi(X);
    if(P != Nil) {
        if(HeadKota(L) == Nil) {
            HeadKota(L) = P;
        } else {
            addressorg last = HeadKota(L);
            while(Next(last) != Nil) {
                last = Next(last);
            }
            Next(last) = P;
        }
    }
}

void DelFirst(Kota *L, infotype *X) {
    if(!ListEmpty(*L)) {
        addressorg P = HeadKota(L);
        strcpy(*X, Info(P));
        HeadKota(L) = Next(P);
        Dealokasi(P);
    } else {
        printf("List Kosong\n");
        printf("=========================\n");
    }
}

void DelLast(Kota *L, infotype *X) {
    if(!ListEmpty(*L)) {
        addressorg P = HeadKota(L);
        if(Next(P) == Nil) {
            DelFirst(L, X);
        } else {
            addressorg Prec = Nil;
            while(Next(P) != Nil) {
                Prec = P;
                P = Next(P);
            }
            strcpy(*X, Info(P));
            Next(Prec) = Nil;
            Dealokasi(P);
        }
    } else {
        printf("List Kosong\n");
        printf("=========================\n");
    }
}

void InsAfter(infotype X, addressorg Prec) {
    if(Prec != Nil) {
        addressorg P = Alokasi(X);
        if(P != Nil) {
            Next(P) = Next(Prec);
            Next(Prec) = P;
        }
    }
}

void DelP(Kota *L, infotype X) {
    addressorg P = Search(*L, X);
    if(P != Nil) {
        addressorg Prec = SearchPrec(*L, X);
        infotype temp;
        
        if(Prec == Nil) {
            DelFirst(L, &temp);
        } else if(Next(P) == Nil) {
            DelLast(L, &temp);
        } else {
            strcpy(temp, Info(P));
            Next(Prec) = Next(P);
            Dealokasi(P);
        }
        printf("Data yang dihapus: %s\n", temp);
    } else {
        printf("Data tidak ditemukan\n");
    }
}

void DelAll(Kota *L) {
    addressorg P = HeadKota(L);
    while(P != Nil) {
        addressorg next = Next(P);
        Dealokasi(P);
        P = next;
    }
    HeadKota(L) = Nil;
}

void PrintInfo(Kota L) {
    addressorg P = HeadKota(&L);
    if(P == Nil) {
        printf("List Kosong\n");
        printf("=========================\n");
    } else {
        while(P != Nil) {
            printf("%s -> ", Info(P));
            P = Next(P);
        }
        printf("NULL\n");
        printf("=========================\n");
    }
}

int Initorg(Kota L) {
    int count = 0;
    addressorg P = HeadKota(&L);
    while(P != Nil) {
        count++;
        P = Next(P);
    }
    return count;
}
