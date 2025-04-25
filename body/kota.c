#include "../header/kota.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

boolean ListKotaEmpty(ListKota L) {
    return (First(L) == Nil);
}

void CreateList(ListKota *L) {
    First(*L) = Nil;
}

addresskota AlokasiKota(infotype X) {
    addresskota P = (addresskota) malloc(sizeof(Kota));
    if (P != Nil) {
        strcpy(NamaKota(P), X);
        Head(P) = Nil;
        NextKota(P) = Nil;
    }
    return P;
}

void DealokasiKota(addresskota P) {
    if (P != Nil) {
        free(P);
    }
}

addresskota SearchKota(ListKota L, infotype X) {
    addresskota P = First(L);
    while (P != Nil) {
        if (strcmp(NamaKota(P), X) == 0) {
            return P;
        }
        P = NextKota(P);
    }
    return Nil;
}

addresskota SearchPrecKota(ListKota L, infotype X) {
    addresskota P = First(L);
    addresskota Prec = Nil;
    boolean found = false;

    while (P != Nil && !found) {
        if (strcmp(NamaKota(P), X) == 0) {
            found = true;
        } else {
            Prec = P;
            P = NextKota(P);
        }
    }

    return found ? Prec : Nil;
}

void InsFirstKota(ListKota *L, infotype X) {
    addresskota P = AlokasiKota(X);
    if (P != Nil) {
        NextKota(P) = First(*L);
        First(*L) = P;
    }
}

void InsLastKota(ListKota *L, infotype X) {
    addresskota P = AlokasiKota(X);
    if (P != Nil) {
        if (ListKotaEmpty(*L)) {
            First(*L) = P;
        } else {
            addresskota last = First(*L);
            while (NextKota(last) != Nil) {
                last = NextKota(last);
            }
            NextKota(last) = P;
        }
    }
}

void DelFirstKota(ListKota *L, infotype *X) {
    if (!ListKotaEmpty(*L)) {
        addresskota P = First(*L);
        strcpy(*X, NamaKota(P));
        First(*L) = NextKota(P);
        DealokasiKota(P);
    } else {
        printf("List Kosong\n");
        printf("========================= \n");
    }
}

void DelLastKota(ListKota *L, infotype *X) {
    if (!ListKotaEmpty(*L)) {
        addresskota P = First(*L), Prec = Nil;
        if (NextKota(P) == Nil) {
            DelFirstKota(L, X);
        } else {
            while (NextKota(P) != Nil) {
                Prec = P;
                P = NextKota(P);
            }
            strcpy(*X, NamaKota(P));
            NextKota(Prec) = Nil;
            DealokasiKota(P);
        }
    } else {
        printf("List Kosong\n");
        printf("========================= \n");
    }
}

void InsAfterKota(ListKota *L, infotype X, addresskota Prec) {
    addresskota P = AlokasiKota(X);
    if (P != Nil && Prec != Nil) {
        NextKota(P) = NextKota(Prec);
        NextKota(Prec) = P;
    } else {
        if (Prec == Nil) {
            printf("Kota yang dimaksud tidak ditemukan, tidak bisa menambahkan setelahnya.\n");
        } 
        if (P == Nil) {
            printf("Alokasi memori gagal untuk kota baru.\n");
        }
        printf("========================= \n");
    }
}


void DelPKota(ListKota *L, infotype X) {
    addresskota P = SearchKota(*L, X);
    addresskota Prec = SearchPrecKota(*L, X);
    infotype temp;

    if (P != Nil) {
        if (Prec == Nil) {
            DelFirstKota(L, &temp);
        } else if (NextKota(P) == Nil) {
            DelLastKota(L, &temp);
        } else {
            strcpy(temp, NamaKota(P));
            NextKota(Prec) = NextKota(P);
            DealokasiKota(P);
        }
        printf("Data yang dihapus : %s\n", temp);
    } else {
        printf("Data tidak ditemukan\n");
        printf("========================= \n");
    }
}

void DelAllKota(ListKota *L) {
    addresskota P = First(*L);
    addresskota NextP;

    while (P != Nil) {
        NextP = NextKota(P);
        DealokasiKota(P);
        P = NextP;
    }

    First(*L) = Nil;
}

void PrintInfoKota(ListKota L) {
    addresskota P = First(L);
    int i = 1;

    if (P == Nil) {
        printf("List Kosong\n");
        printf("========================= \n\n");
    } else {
        while (P != Nil) {
            printf("Kota %d : %s\n", i, NamaKota(P));
            PrintInfo(*P); // Make sure PrintInfo is properly defined
            P = NextKota(P);
            i++;
        }
        printf("NULL\n");
        printf("========================= \n");
    }
}

addresskota GetKotaKe(ListKota listkota, int index) {
    addresskota P = First(listkota);
    int i = 1;

    while (P != Nil && i < index) {
        P = NextKota(P);
        i++;
    }

    return P;
}

int HitungJumlahKota(ListKota L) {
    addresskota P = First(L);
    int count = 0;

    while (P != Nil) {
        count++;
        P = NextKota(P);
    }

    return count;
}