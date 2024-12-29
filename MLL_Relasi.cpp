#include "MLL_Relasi.h"

void createListRelasi(ListRelasi &L) {
    /* I.S: List belum terdefinisi
       F.S: List L terdefinisi kosong */
    L.first = NULL;
}

adrRelasi newElmlistRelasi(adrMHS m, adrKJR k) {
    /* I.S: m dan k terdefinisi
       F.S: Sebuah elemen baru dengan info m dan k terbentuk dan dikembalikan */
    adrRelasi r = new relasi;
    if (r == NULL) { // Null check setelah allocasi
        cout << "=========================================================" << endl;
        cout << "                 Memory allocation failed!               " << endl;
        cout << "=========================================================" << endl;
        cout << endl;
        return NULL;
    }
    r->infoMHS = m;
    r->infoKJR = k;
    r->nextRelasi = NULL;
    return r;
}

bool isEmptyRelasi(ListRelasi L) {
    /* Mengembalikan true jika list L kosong */
    return (L.first == NULL);
}

void insertFirstRelasi(ListRelasi &L, adrRelasi r) {
    /* I.S: L mungkin kosong, r terdefinisi
       F.S: Elemen r menjadi elemen pertama dalam L */
    if (r == NULL) { // Validasi input
        cout << "=========================================================" << endl;
        cout << "                 Memory allocation failed!               " << endl;
        cout << "=========================================================" << endl;
        cout << endl;
        return;
    }
    r->nextRelasi = L.first;
    L.first = r;
}

void insertLastRelasi(ListRelasi &L, adrRelasi r) {
    /* I.S: L mungkin kosong, r terdefinisi
       F.S: Elemen r menjadi elemen terakhir dalam L */
    if (r == NULL) { // Validasi input
        cout << "=========================================================" << endl;
        cout << "                 Memory allocation failed!               " << endl;
        cout << "=========================================================" << endl;
        cout << endl;
        return;
    }
    if (isEmptyRelasi(L)) {
        L.first = r;
    } else {
        adrRelasi p = L.first;
        while (p->nextRelasi != NULL) {
            p = p->nextRelasi;
        }
        p->nextRelasi = r;
    }
}

void insertAfterRelasi(ListRelasi &L, adrRelasi prec, adrRelasi r) {
    /* I.S: prec dan r terdefinisi, prec berada dalam L
       F.S: r disisipkan setelah prec */
    if (prec != NULL) {
        r->nextRelasi = prec->nextRelasi;
        prec->nextRelasi = r;
    }
}

void deleteFirstRelasi(ListRelasi &L, adrRelasi &r) {
    /* I.S: L tidak kosong
       F.S: Elemen pertama dihapus, r berisi alamat elemen yang dihapus */
    if (isEmptyRelasi(L)) {
        r = NULL;
        cout << "====================== List Kosong ======================" << endl;
    } else {
        r = L.first;
        L.first = r->nextRelasi;
        r->nextRelasi = NULL;
    }
}

void deleteLastRelasi(ListRelasi &L, adrRelasi &r) {
    /* I.S: L tidak kosong
       F.S: Elemen terakhir dihapus, r berisi alamat elemen yang dihapus */
    if (isEmptyRelasi(L)) {
        r = NULL;
        cout << "====================== List Kosong ======================" << endl;
    } else if (L.first->nextRelasi == NULL) {
        r = L.first;
        L.first = NULL;
    } else {
        adrRelasi p = L.first;
        while (p->nextRelasi->nextRelasi != NULL) {
            p = p->nextRelasi;
        }
        r = p->nextRelasi;
        p->nextRelasi = NULL;
    }
}

void deleteAfterRelasi(ListRelasi &L, adrRelasi &r, adrRelasi prec) {
    /* I.S: prec terdefinisi dan berada dalam L
       F.S: Elemen setelah prec dihapus, r berisi alamat elemen yang dihapus */
    if (prec != NULL && prec->nextRelasi != NULL) {
        r = prec->nextRelasi;
        prec->nextRelasi = r->nextRelasi;
        r->nextRelasi = NULL;
    } else {
        r = NULL;
    }
}

adrRelasi findRelasi(ListRelasi L, adrMHS m, adrKJR k) {
    /* Mengembalikan alamat elemen dengan infoMHS m dan infoKJR k, atau NULL jika tidak ditemukan */
    adrRelasi r = L.first;
    while (r != NULL) {
        if (r->infoMHS == m && r->infoKJR == k) {
            return r;
        }
        r = r->nextRelasi;
    }
    return NULL;
}

void deleteRelasiByParent(ListRelasi &LRelasi, adrMHS parent) {
    adrRelasi p = LRelasi.first, q = NULL;

    while (p != NULL) {
        if (p->infoMHS == parent) {
            if (p == LRelasi.first) {
                LRelasi.first = p->nextRelasi;
            } else {
                q->nextRelasi = p->nextRelasi;
            }
            adrRelasi temp = p;
            p = p->nextRelasi;
            delete temp;
        } else {
            q = p;
            p = p->nextRelasi;
        }
    }
}

void deleteRelasiByChild(ListRelasi &LRelasi, adrKJR child) {
    adrRelasi p = LRelasi.first, q = NULL;

    while (p != NULL) {
        if (p->infoKJR == child) {
            if (p == LRelasi.first) {
                LRelasi.first = p->nextRelasi;
            } else {
                q->nextRelasi = p->nextRelasi;
            }
            adrRelasi temp = p;
            p = p->nextRelasi;
            delete temp;
        } else {
            q = p;
            p = p->nextRelasi;
        }
    }
}


void printListRelasi(ListRelasi L) {
    /* I.S: L terdefinisi
       F.S: Semua elemen dalam L dicetak */
    adrRelasi r = L.first;
    int i = 1;
    if (isEmptyRelasi(L)) {
        cout << "====================== List Kosong ======================" << endl;
    } else {
        cout << "=========================================================" << endl;
        cout << "                       Data Relasi                       " << endl;
        cout << "=========================================================" << endl;
        while (r != NULL) {
            cout << "Relasi ke-" << i << endl;
            cout << "Mahasiswa: " << r->infoMHS->info.nama << endl;
            cout << "Kejuaraan: " << r->infoKJR->info.nama << endl;
            cout << "_________________________________________________________" << endl;
            cout << endl;
            r = r->nextRelasi;
            i++;
        }
        cout << endl;
    }
}
