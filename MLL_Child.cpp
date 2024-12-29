#include "MLL_Child.h"

void createListKjr(ListKJR &L) {
    /* I.S: List belum terdefinisi
       F.S: List L terdefinisi kosong */
    L.first = NULL;
    L.last = NULL;
}

adrKJR newElmlistKjr(infoKJR x) {
    /* I.S: x terdefinisi
       F.S: Sebuah elemen baru dengan info x terbentuk dan dikembalikan */
    adrKJR k = new Kejuaraan;
    k->info = x;
    k->nextKJR = NULL;
    k->prevKJR = NULL;
    return k;
}

bool isEmptyKjr(ListKJR L) {
    /* Mengembalikan true jika list L kosong */
    return (L.first == NULL && L.last == NULL);
}

void insertFirstKJR(ListKJR &L, adrKJR kjr) {
    /* I.S: L mungkin kosong, kjr terdefinisi
       F.S: Elemen kjr menjadi elemen pertama dalam L */
    if (isEmptyKjr(L)) {
        L.first = kjr;
        L.last = kjr;
    } else {
        kjr->nextKJR = L.first;
        L.first->prevKJR = kjr;
        L.first = kjr;
    }
}

void insertLastKJR(ListKJR &L, adrKJR kjr) {
    /* I.S: L mungkin kosong, kjr terdefinisi
       F.S: Elemen kjr menjadi elemen terakhir dalam L */
    if (isEmptyKjr(L)) {
        L.first = kjr;
        L.last = kjr;
    } else {
        kjr->prevKJR = L.last;
        L.last->nextKJR = kjr;
        L.last = kjr;
    }
}

void insertAfterKJR(ListKJR &L, adrKJR prec, adrKJR kjr) {
    /* I.S: prec dan kjr terdefinisi, prec berada dalam L
       F.S: kjr disisipkan setelah prec */
    if (prec != NULL) {
        kjr->nextKJR = prec->nextKJR;
        kjr->prevKJR = prec;
        if (prec->nextKJR != NULL) {
            prec->nextKJR->prevKJR = kjr;
        } else {
            L.last = kjr; // Jika prec adalah elemen terakhir
        }
        prec->nextKJR = kjr;
    }
}

void deleteFirstKjr(ListKJR &L, adrKJR &kjr) {
    /* I.S: L tidak kosong
       F.S: Elemen pertama dihapus, kjr berisi alamat elemen yang dihapus */
    if (isEmptyKjr(L)) {
        kjr = NULL;
        cout << "====================== List Kosong ======================" << endl;
    } else if (L.first == L.last) {
        kjr = L.first;
        L.first = NULL;
        L.last = NULL;
    } else {
        kjr = L.first;
        L.first = kjr->nextKJR;
        L.first->prevKJR = NULL;
        kjr->nextKJR = NULL;
    }
}

void deleteLastKjr(ListKJR &L, adrKJR &kjr) {
    /* I.S: L tidak kosong
       F.S: Elemen terakhir dihapus, kjr berisi alamat elemen yang dihapus */
    if (isEmptyKjr(L)) {
        kjr = NULL;
        cout << "====================== List Kosong ======================" << endl;
    } else if (L.first == L.last) {
        kjr = L.first;
        L.first = NULL;
        L.last = NULL;
    } else {
        kjr = L.last;
        L.last = kjr->prevKJR;
        L.last->nextKJR = NULL;
        kjr->prevKJR = NULL;
    }
}

void deleteAfterKjr(ListKJR &L, adrKJR &kjr, adrKJR prec) {
    /* I.S: prec terdefinisi dan berada dalam L
       F.S: Elemen setelah prec dihapus, kjr berisi alamat elemen yang dihapus */
    if (prec != NULL && prec->nextKJR != NULL) {
        kjr = prec->nextKJR;
        prec->nextKJR = kjr->nextKJR;
        if (kjr->nextKJR != NULL) {
            kjr->nextKJR->prevKJR = prec;
        } else {
            L.last = prec; // Jika elemen terakhir dihapus
        }
        kjr->nextKJR = NULL;
        kjr->prevKJR = NULL;
    } else {
        kjr = NULL;
    }
}

adrKJR findKjr(ListKJR L, string nama) {
    /* Mengembalikan alamat elemen dengan nama yang dicari, atau NULL jika tidak ditemukan */
    adrKJR k = L.first;
    while (k != NULL) {
        if (k->info.nama == nama) {
            return k;
        }
        k = k->nextKJR;
    }
    return NULL;
}

void printListKjr(ListKJR L) {
    /* I.S: L terdefinisi
       F.S: Semua elemen dalam L dicetak */
    adrKJR k = L.first;
    int i = 1;
    if (isEmptyKjr(L)) {
        cout << "====================== List Kosong ======================" << endl;
    } else {
        cout << "=========================================================" << endl;
        cout << "                      Data Kejuaraan                     " << endl;
        cout << "=========================================================" << endl;
        while (k != NULL) {
            cout << "Peserta ke-" << i << endl;
            cout << "Nama    : " << k->info.nama << endl;
            cout << "Tingkat : " << k->info.tingkat << endl;
            cout << "_________________________________________________________" << endl;
            cout << endl;
            k = k->nextKJR;
            i++;
        }
        cout << endl;
    }
}
