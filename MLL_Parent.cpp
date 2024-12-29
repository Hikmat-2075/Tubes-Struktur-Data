#include "MLL_Parent.h"

void createListMhs(ListMHS &L) {
    L.first = NULL;
    L.last = NULL;
}

adrMHS newElmlistMhs(infoMHS x) {
    adrMHS m = new MHS;
    m->info = x;
    m->nextMHS = NULL;
    m->prevMhs = NULL;
    return m;
}

bool isEmptyMhs(ListMHS L) {
    return L.first == NULL && L.last == NULL;
}

void insertFirstMhs(ListMHS &L, adrMHS mhs) {
    if (isEmptyMhs(L)) {
        L.first = mhs;
        L.last = mhs;
    } else {
        mhs->nextMHS = L.first;
        L.first->prevMhs = mhs;
        L.first = mhs;
    }
}

void insertLastMHS(ListMHS &L, adrMHS mhs) {
    if (isEmptyMhs(L)) {
        L.first = mhs;
        L.last = mhs;
    } else {
        mhs->prevMhs = L.last;
        L.last->nextMHS = mhs;
        L.last = mhs;
    }
}

void insertAfterMHS(ListMHS &L, adrMHS prec, adrMHS mhs) {
    if (prec != NULL) {
        mhs->nextMHS = prec->nextMHS;
        mhs->prevMhs = prec;
        if (prec->nextMHS != NULL) {
            prec->nextMHS->prevMhs = mhs;
        } else {
            L.last = mhs;
        }
        prec->nextMHS = mhs;
    }
}

void deleteFirstMhs(ListMHS &L, adrMHS &mhs) {
    if (isEmptyMhs(L)) {
        mhs = NULL;
        cout << "====================== List Kosong ======================" << endl;
    } else if (L.first == L.last) {
        mhs = L.first;
        L.first = NULL;
        L.last = NULL;
    } else {
        mhs = L.first;
        L.first = mhs->nextMHS;
        L.first->prevMhs = NULL;
        mhs->nextMHS = NULL;
    }
}

void deleteLastMhs(ListMHS &L, adrMHS &mhs) {
    if (isEmptyMhs(L)) {
        mhs = NULL;
        cout << "====================== List Kosong ======================" << endl;
    } else if (L.first == L.last) {
        mhs = L.first;
        L.first = NULL;
        L.last = NULL;
    } else {
        mhs = L.last;
        L.last = mhs->prevMhs;
        L.last->nextMHS = NULL;
        mhs->prevMhs = NULL;
    }
}

void deleteAfterMhs(ListMHS &L, adrMHS prec, adrMHS &mhs) {
    if (prec != NULL && prec->nextMHS != NULL) {
        mhs = prec->nextMHS;
        prec->nextMHS = mhs->nextMHS;
        if (mhs->nextMHS != NULL) {
            mhs->nextMHS->prevMhs = prec;
        } else {
            L.last = prec;
        }
        mhs->nextMHS = NULL;
        mhs->prevMhs = NULL;
    }
}

adrMHS findMhsNIM(ListMHS L, string NIM) {
    /*
    I.S. : List L terdefinisi, bisa kosong atau berisi data.
    F.S. : Mengembalikan adrMHS jika mahasiswa dengan NIM ditemukan,
           atau NULL jika tidak ditemukan.
    */
    adrMHS m = L.first;

    while (m != NULL && m->info.NIM != NIM) {
        m = m->nextMHS;
    }
    return m;
}

adrMHS findMhsNama(ListMHS L, string nama) {
    /*
    I.S. : List L terdefinisi, bisa kosong atau berisi data.
    F.S. : Mengembalikan adrMHS jika mahasiswa dengan nama ditemukan,
           atau NULL jika tidak ditemukan.
    */
    adrMHS m = L.first;

    while (m != NULL && m->info.nama != nama) {
        m = m->nextMHS;
    }
    return m;
}

void copyListMhs(const ListMHS& src, ListMHS& dest) {
    createListMhs(dest);
    adrMHS p = src.first;
    while (p != NULL) {
        adrMHS newMhs = new MHS;
        newMhs->info = p->info;
        insertLastMHS(dest, newMhs);
        p = p->nextMHS;
    }
}

// ASCENDING //



void printListMhs(ListMHS L) {
    adrMHS m = L.first;
    int i = 1;

    cout << "=========================================================" << endl;
    cout << "                       Data Peserta                      " << endl;
    cout << "=========================================================" << endl;
    while (m != NULL) {
        cout << "Peserta ke-" << i << endl;
        cout << "Nama     : " << m->info.nama << endl;
        cout << "NIM      : " << m->info.NIM << endl;
        cout << "Usia     : " << m->info.usia << endl;
        cout << "Jurusan  : " << m->info.jurusan << endl;
        cout << "_________________________________________________________" << endl;
        cout << endl;
        m = m->nextMHS;
        i++;
    }
    cout << endl;
}

void AscendingNama(ListMHS &L1) {
    ListMHS Ltemp;
    copyListMhs(L1,Ltemp);

    if (Ltemp.first == NULL || Ltemp.first->nextMHS == NULL) {
        cout << "=========================================================" << endl;
        cout << "       List kosong atau hanya memiliki satu elemen       " << endl;
        cout << "                 Tidak ada yang diurutkan.               " << endl;
        cout << "=========================================================" << endl;
        cout << endl;
        return;
    }

    bool swapped;
    do {
        swapped = false;
        adrMHS current = Ltemp.first;
        while (current->nextMHS != NULL) {
            if (current->info.nama > current->nextMHS->info.nama) {
                // Tukar data
                infoMHS temp = current->info;
                current->info = current->nextMHS->info;
                current->nextMHS->info = temp;
                swapped = true;
            }
            current = current->nextMHS;
        }
    } while (swapped);

    cout << "=========================================================" << endl;
    cout << "   List berhasil diurutkan berdasarkan nama (ascending). " << endl;
    cout << "=========================================================" << endl;

    printListMhs(Ltemp);
}

void AscendingJurusan(ListMHS &L1) {
    ListMHS Ltemp;
    copyListMhs(L1,Ltemp);

    if (Ltemp.first == NULL || Ltemp.first->nextMHS == NULL) {
        cout << "=========================================================" << endl;
        cout << "       List kosong atau hanya memiliki satu elemen       " << endl;
        cout << "                 Tidak ada yang diurutkan.               " << endl;
        cout << "=========================================================" << endl;
        cout << endl;
        return;
    }

    bool swapped;
    do {
        swapped = false;
        adrMHS current = Ltemp.first;
        while (current->nextMHS != NULL) {
            if (current->info.jurusan > current->nextMHS->info.jurusan) {
                // Tukar data
                infoMHS temp = current->info;
                current->info = current->nextMHS->info;
                current->nextMHS->info = temp;
                swapped = true;
            }
            current = current->nextMHS;
        }
    } while (swapped);

    cout << "=========================================================" << endl;
    cout << " List berhasil diurutkan berdasarkan jurusan (ascending)." << endl;
    cout << "=========================================================" << endl;

    printListMhs(Ltemp);
}

void AscendingNIM(ListMHS &L1) {
    ListMHS Ltemp;
    copyListMhs(L1,Ltemp);

    if (Ltemp.first == NULL || Ltemp.first->nextMHS == NULL) {
        cout << "=========================================================" << endl;
        cout << "       List kosong atau hanya memiliki satu elemen       " << endl;
        cout << "                 Tidak ada yang diurutkan.               " << endl;
        cout << "=========================================================" << endl;
        cout << endl;
        return;
    }

    bool swapped;
    do {
        swapped = false;
        adrMHS current = Ltemp.first;
        while (current->nextMHS != NULL) {
            if (current->info.NIM > current->nextMHS->info.NIM) {
                // Tukar data
                infoMHS temp = current->info;
                current->info = current->nextMHS->info;
                current->nextMHS->info = temp;
                swapped = true;
            }
            current = current->nextMHS;
        }
    } while (swapped);

    cout << "=========================================================" << endl;
    cout << "   List berhasil diurutkan berdasarkan NIM (ascending).  " << endl;
    cout << "=========================================================" << endl;

    printListMhs(Ltemp);
}

void AscendingUsia(ListMHS &L1) {
    ListMHS Ltemp;
    copyListMhs(L1,Ltemp);

    if (Ltemp.first == NULL) {
        cout << "=========================================================" << endl;
        cout << "       List kosong atau hanya memiliki satu elemen       " << endl;
        cout << "                 Tidak ada yang diurutkan.               " << endl;
        cout << "=========================================================" << endl;
        cout << endl;
        return;
    }

    // Menggunakan bubble sort sebagai contoh
    bool swapped;
    do {
        swapped = false;
        adrMHS current = Ltemp.first;
        while (current->nextMHS != NULL) {
            if (current->info.usia > current->nextMHS->info.usia) {
                // Tukar data
                infoMHS temp = current->info;
                current->info = current->nextMHS->info;
                current->nextMHS->info = temp;
                swapped = true;
            }
            current = current->nextMHS;
        }
    } while (swapped);

    cout << "=========================================================" << endl;
    cout << "         List berhasil diurutkan berdasarkan usia.       " << endl;
    cout << "=========================================================" << endl;

    printListMhs(Ltemp);
}

// DESCENDING

void DescendingNama(ListMHS &L1) {
    ListMHS Ltemp;
    copyListMhs(L1,Ltemp);

    if (Ltemp.first == NULL || Ltemp.first->nextMHS == NULL) {
        cout << "=========================================================" << endl;
        cout << "       List kosong atau hanya memiliki satu elemen       " << endl;
        cout << "                 Tidak ada yang diurutkan.               " << endl;
        cout << "=========================================================" << endl;
        cout << endl;
        return;
    }

    bool swapped;
    do {
        swapped = false;
        adrMHS current = Ltemp.first;
        while (current->nextMHS != NULL) {
            if (current->info.nama < current->nextMHS->info.nama) {
                // Tukar data
                infoMHS temp = current->info;
                current->info = current->nextMHS->info;
                current->nextMHS->info = temp;
                swapped = true;
            }
            current = current->nextMHS;
        }
    } while (swapped);

    cout << "=========================================================" << endl;
    cout << "  List berhasil diurutkan berdasarkan nama (descending). " << endl;
    cout << "=========================================================" << endl;

    printListMhs(Ltemp);
}

void DescendingNIM(ListMHS & L1) {
    ListMHS Ltemp;
    copyListMhs(L1,Ltemp);

    if (Ltemp.first == NULL || Ltemp.first->nextMHS == NULL) {
        cout << "=========================================================" << endl;
        cout << "       List kosong atau hanya memiliki satu elemen       " << endl;
        cout << "                 Tidak ada yang diurutkan.               " << endl;
        cout << "=========================================================" << endl;
        cout << endl;
        return;
    }

    bool swapped;
    do {
        swapped = false;
        adrMHS current = Ltemp.first;
        while (current->nextMHS != NULL) {
            if (current->info.NIM < current->nextMHS->info.NIM) {
                // Tukar data
                infoMHS temp = current->info;
                current->info = current->nextMHS->info;
                current->nextMHS->info = temp;
                swapped = true;
            }
            current = current->nextMHS;
        }
    } while (swapped);

    cout << "=========================================================" << endl;
    cout << "  List berhasil diurutkan berdasarkan NIM (descending).  " << endl;
    cout << "=========================================================" << endl;

    printListMhs(Ltemp);
}

void DescendingJurusan(ListMHS &L1) {
    ListMHS Ltemp;
    copyListMhs(L1,Ltemp);

    if (Ltemp.first == NULL || Ltemp.first->nextMHS == NULL) {
        cout << "=========================================================" << endl;
        cout << "       List kosong atau hanya memiliki satu elemen       " << endl;
        cout << "                 Tidak ada yang diurutkan.               " << endl;
        cout << "=========================================================" << endl;
        cout << endl;
        return;
    }

    bool swapped;
    do {
        swapped = false;
        adrMHS current = Ltemp.first;
        while (current->nextMHS != NULL) {
            if (current->info.jurusan < current->nextMHS->info.jurusan) {
                // Tukar data
                infoMHS temp = current->info;
                current->info = current->nextMHS->info;
                current->nextMHS->info = temp;
                swapped = true;
            }
            current = current->nextMHS;
        }
    } while (swapped);

    cout << "=========================================================" << endl;
    cout << "List berhasil diurutkan berdasarkan jurusan (descending)." << endl;
    cout << "=========================================================" << endl;

    printListMhs(Ltemp);
}

void DescendingUsia(ListMHS &L1) {
    ListMHS Ltemp;
    copyListMhs(L1,Ltemp);

    if (Ltemp.first == NULL || Ltemp.first->nextMHS == NULL) {
        cout << "=========================================================" << endl;
        cout << "       List kosong atau hanya memiliki satu elemen       " << endl;
        cout << "                 Tidak ada yang diurutkan.               " << endl;
        cout << "=========================================================" << endl;
        cout << endl;
        return;
    }

    bool swapped;
    do {
        swapped = false;
        adrMHS current = Ltemp.first;
        while (current->nextMHS != NULL) {
            if (current->info.usia < current->nextMHS->info.usia) {
                // Tukar data
                infoMHS temp = current->info;
                current->info = current->nextMHS->info;
                current->nextMHS->info = temp;
                swapped = true;
            }
            current = current->nextMHS;
        }
    } while (swapped);

    cout << "=========================================================" << endl;
    cout << "  List berhasil diurutkan berdasarkan usia (descending). " << endl;
    cout << "=========================================================" << endl;

    printListMhs(Ltemp);
}
