#include "Global.h"

void pilihMenu(ListMHS &L1, ListKJR &L2, ListRelasi &L3, infoMHS mhs, infoKJR kjr) {
    int pilih = -1, pilihAsc, pilihDesc;
    adrKJR k, hapusKJR;
    adrMHS m, hapusMHS;
    string NamaPeserta, NamaKejuaraan;

    while (true) {
        menuUtama(pilih);
        switch (pilih) {
            case 1:
                while (true) {
                    menuTambah(pilih);
                    switch (pilih) {
                        case 1:
                                cout << "=========================================================" << endl;
                                cout << "                   Menu Tambah Peserta                   " << endl;
                                cout << "_________________________________________________________" << endl;
                                cout << "Masukkan nama peserta (string)" << endl;
                                cout << "Gunakan '_' (underscore) sebagai pengganti Spasi" << endl;
                                cout << "Contoh : Hikmat_Arif" << endl;
                                cout << ": ";
                                cin >> mhs.nama;
                                cout << endl;

                                cout << "Masukkan NIM peserta (Integer)" << endl;
                                cout << "Contoh : 123" << endl;
                                cout << ": ";
                                cin >> mhs.NIM;
                                cout << endl;

                                cout << "Masukkan Jurusan peserta (string)" << endl;
                                cout << "Gunakan '_' (underscore) sebagai pengganti Spasi" << endl;
                                cout << "Contoh : Data_Sains" << endl;
                                cout << ": ";
                                cin >> mhs.jurusan;
                                cout << endl;

                                cout << "Masukkan Usia peserta (Integer)" << endl;
                                cout << "Contoh : 19" << endl;
                                cout << ": ";
                                cin >> mhs.usia;
                                cout << "=========================================================" << endl;
                                cout << endl;

                                m = findMhsNIM(L1, mhs.NIM);
                                if (m == NULL) {
                                    m = newElmlistMhs(mhs);
                                    if (m == NULL) {
                                        cout << "=========================================================" << endl;
                                        cout << "                 Memory allocation failed!               " << endl;
                                        cout << "=========================================================" << endl;
                                        cout << endl;
                                        break;
                                    }
                                    insertFirstMhs(L1, m);
                                } else {
                                    cout << "=========================================================" << endl;
                                    cout << "                  Nim Tersebut Sudah ada                 " << endl;
                                    cout << "=========================================================" << endl;
                                    cout << endl;
                                }

                            break;
                        case 2:
                            cout << "=========================================================" << endl;
                            cout << "                  Menu Tambah Kejuaraan                  " << endl;
                            cout << "_________________________________________________________" << endl;
                            cout << "Masukkan nama Kejuaraan (string)" << endl;
                            cout << "Gunakan '_' (underscore) sebagai pengganti Spasi" << endl;
                            cout << "Contoh : Sepak_Bola" << endl;
                            cout << ": ";
                            cin >> kjr.nama;
                            cout << endl;

                            cout << "Masukkan Tingkat Kejuaraan (string)" << endl;
                            cout << "Gunakan '_' (underscore) sebagai pengganti Spasi" << endl;
                            cout << "Contoh : Nasional" << endl;
                            cout << ": ";
                            cin >> kjr.tingkat;
                            cout << "=========================================================" << endl;
                            cout << endl;

                            k = newElmlistKjr(kjr);
                            if (k == NULL) {
                                cout << "=========================================================" << endl;
                                cout << "                 Memory allocation failed!               " << endl;
                                cout << "=========================================================" << endl;
                                cout << endl;
                                break;
                            }
                            insertLastKJR(L2, k);
                            break;
                        case 3:
                            cout << "=========================================================" << endl;
                            cout << "            Connect Peserta dan Kejuaraannya             " << endl;
                            cout << "_________________________________________________________" << endl;
                            cout << "Masukkan nama peserta (string)" << endl;
                            cout << "Gunakan '_' (underscore) sebagai pengganti Spasi" << endl;
                            cout << "Contoh : Hikmat_Arif" << endl;
                            cout << ": ";
                            cin >> NamaPeserta;
                            cout << endl;

                            cout << "Masukkan nama kejuaraan (string)" << endl;
                            cout << "Gunakan '_' (underscore) sebagai pengganti Spasi" << endl;
                            cout << "Contoh : Sepak_Bola" << endl;
                            cout << ": ";
                            cin >> NamaKejuaraan;
                            cout << endl;

                            connect(L1, L2, L3, NamaPeserta, NamaKejuaraan);
                            break;
                        case 0:
                            break;
                        default:
                            cout << "=========================================================" << endl;
                            cout << "                   Pilihan Tidak Valid                   " << endl;
                            cout << "=========================================================" << endl;
                            cout << endl;
                    }
                    if (pilih == 0) break;
                }
                break;
            case 2:
                while (true) {
                    menuHapus(pilih);
                    switch (pilih) {
                        case 1:
                            // Hapus peserta
                            cout << "=========================================================" << endl;
                            cout << "                   Menu Hapus Peserta                    " << endl;
                            cout << "_________________________________________________________" << endl;
                            cout << "Masukkan nama peserta (string)" << endl;
                            cout << "Gunakan '_' (underscore) sebagai pengganti Spasi" << endl;
                            cout << "Contoh : Hikmat_Arif" << endl;
                            cout << ": ";
                            cin >> NamaPeserta;
                            cout << "=========================================================" << endl;
                            cout << endl;

                            m = findMhsNama(L1, NamaPeserta);
                            if(m != NULL){
                                deleteRelasiByParent(L3, m);
                                if(m->prevMhs == NULL){
                                    deleteFirstMhs(L1,m);
                                }else if(m->nextMHS == NULL){
                                    deleteLastMhs(L1, m);
                                }else{
                                    deleteAfterMhs(L1, m->prevMhs, m);
                                }
                            }else{
                                cout << "=========================================================" << endl;
                                cout << "                   Data tidak ditemukan                  " << endl;
                                cout << "=========================================================" << endl;
                                cout << endl;
                            }
                            hapusMHS = findMhsNama(L1, NamaPeserta);
                            if(hapusMHS == NULL){
                                cout << "_________________________________________________________" << endl;
                                cout << "Data Peserta dengan nama: " << NamaPeserta << " telah berhasil dihapus." << endl;
                                cout << "=========================================================" << endl;
                                cout << endl;
                            }
                            break;
                        case 2:
                            // Hapus kejuaraan
                            cout << "=========================================================" << endl;
                            cout << "                  Menu Hapus Kejuaraan                   " << endl;
                            cout << "_________________________________________________________" << endl;
                            cout << "Masukkan nama Kejuaraan (string)" << endl;
                            cout << "Gunakan '_' (underscore) sebagai pengganti Spasi" << endl;
                            cout << "Contoh : Sepak_Bola" << endl;
                            cout << ": ";
                            cin >> NamaKejuaraan;
                            k = findKjr(L2, NamaKejuaraan);
                            if(k != NULL){
                                deleteRelasiByChild(L3, k);
                                if(k->prevKJR == NULL){
                                    deleteFirstKjr(L2, k);
                                }else if(k->nextKJR == NULL){
                                    deleteLastKjr(L2, k);
                                }else{
                                    deleteAfterKjr(L2, k, k->prevKJR);
                                }
                            }
                            hapusKJR = findKjr(L2, NamaKejuaraan);
                            if(hapusKJR == NULL){
                                cout << "_________________________________________________________" << endl;
                                cout << "Data Kejuaraan dengan nama: " << NamaKejuaraan << " telah berhasil dihapus" << endl;
                                cout << "=========================================================" << endl;
                                cout << endl;
                            }
                            break;
                        case 3:
                            // Hapus relasi
                            cout << "=========================================================" << endl;
                            cout << "                   Menu Hapus Relasi                     " << endl;
                            cout << "_________________________________________________________" << endl;
                            cout << "Masukkan nama peserta (string)" << endl;
                            cout << "Gunakan '_' (underscore) sebagai pengganti Spasi" << endl;
                            cout << "Contoh : Hikmat_Arif" << endl;
                            cout << ": ";
                            cin >> NamaPeserta;
                            cout << endl;

                            cout << "Masukkan nama Kejuaraan (string)" << endl;
                            cout << "Gunakan '_' (underscore) sebagai pengganti Spasi" << endl;
                            cout << "Contoh : Sepak_Bola" << endl;
                            cout << ": ";
                            cin >> NamaKejuaraan;
                            cout << "=========================================================" << endl;
                            cout << endl;

                            disconnect(L1, L2, L3, NamaPeserta, NamaKejuaraan);
                            break;
                        case 0:
                            break;
                        default:
                            cout << "=========================================================" << endl;
                            cout << "                   Inputan Tidak Valid                   " << endl;
                            cout << "=========================================================" << endl;
                            cout << endl;
                    }
                    if (pilih == 0) break;
                }
                break;
            case 3:
                while (true) {
                    menuShow(pilih);
                    switch (pilih) {
                        case 1:
                            MenuAscending();
                            cin >> pilihAsc;
                            switch(pilihAsc){
                                case 1:
                                    AscendingNama(L1);
                                    break;
                                case 2:
                                    AscendingNIM(L1);
                                    break;
                                case 3:
                                    AscendingJurusan(L1);
                                    break;
                                case 4:
                                    AscendingUsia(L1);
                                    break;
                                case 0:
                                    break;
                                default:
                                    cout << "=========================================================" << endl;
                                    cout << "                   Pilihan Tidak Valid                   " << endl;
                                    cout << "=========================================================" << endl;
                                    cout << endl;
                            }
                            break;
                        case 2:
                            MenuDescending();
                            cin >> pilihDesc;
                            cout << endl;
                            switch(pilihDesc){
                                case 1:
                                    DescendingNama(L1);
                                    break;
                                case 2:
                                    DescendingNIM(L1);
                                    break;
                                case 3:
                                    DescendingJurusan(L1);
                                    break;
                                case 4:
                                    DescendingUsia(L1);
                                    break;
                                default:
                                    cout << "=========================================================" << endl;
                                    cout << "                   Pilihan Tidak Valid                   " << endl;
                                    cout << "=========================================================" << endl;
                                    cout << endl;
                            }
                            break;
                        case 3:
                            MAXKjr(L2, L3);
                            break;
                        case 4:
                            MINMhs(L1, L3);
                            break;
                        case 5:
                            cout << "=========================================================" << endl;
                            cout << "            Peserta dan lomba yang diikutinya            " << endl;
                            cout << "=========================================================" << endl;
                            cout << "Masukkan nama peserta (string)" << endl;
                            cout << "Gunakan '_' (underscore) sebagai pengganti Spasi" << endl;
                            cout << "Contoh : Hikmat_Arif" << endl;
                            cout << ": ";
                            cin >> NamaPeserta;
                            cout << "=========================================================" << endl;
                            cout << endl;
                            printMhs(L1, L3, NamaPeserta);
                            break;
                        case 6:
                            cout << "=========================================================" << endl;
                            cout << "          Kejuaraan dan peserta yang diikutinya          " << endl;
                            cout << "=========================================================" << endl;
                            cout << "Masukkan nama Kejuaraan (string)" << endl;
                            cout << "Gunakan '_' (underscore) sebagai pengganti Spasi" << endl;
                            cout << "Contoh : Sepak_Bola" << endl;
                            cout << ": ";
                            cin >> NamaKejuaraan;
                            cout << "=========================================================" << endl;
                            cout << endl;
                            printKjr(L2, L3, NamaKejuaraan);
                            break;
                        case 7:
                            printListMhs(L1);
                            break;
                        case 8:
                            printListKjr(L2);
                            break;
                        case 9:
                            printKseluruhanMHS(L1, L3);
                            break;
                        case 0:
                            break;
                        default:
                            cout << "=========================================================" << endl;
                            cout << "                   Pilihan Tidak Valid                   " << endl;
                            cout << "=========================================================" << endl;
                            cout << endl;
                    }
                    if (pilih == 0) break;
                }
                break;
            case 0:
                clearScreen();
                Finish();
                return;
            default:
                cout << "=========================================================" << endl;
                cout << "                   Pilihan Tidak Valid                   " << endl;
                cout << "=========================================================" << endl;
                cout << endl;
        }
    }
}

void connect(ListMHS &L1, ListKJR &L2, ListRelasi &L3, string namaPeserta, string namaKejuaraan) {
    // Mencari mahasiswa berdasarkan nama
    adrMHS m = findMhsNama(L1, namaPeserta);
    // Mencari kejuaraan berdasarkan nama
    adrKJR k = findKjr(L2, namaKejuaraan);

    if (m == NULL) {
        cout << "=========================================================" << endl;
        cout << "Peserta dengan nama '" << namaPeserta << "' tidak ditemukan." << endl;
        cout << "=========================================================" << endl;
        cout << endl;
        return;
    }
    if (k == NULL) {
        cout << "=========================================================" << endl;
        cout << "Kejuaraan dengan nama '" << namaKejuaraan << "' tidak ditemukan." << endl;
        cout << "=========================================================" << endl;
        cout << endl;
        return;
    }

    // Memeriksa apakah relasi sudah ada
    adrRelasi existingRelasi = L3.first;
    while (existingRelasi != NULL) {
        if (existingRelasi->infoMHS == m && existingRelasi->infoKJR == k) {
            cout << "=========================================================" << endl;
            cout << "Relasi antara " << namaPeserta << " dan " << namaKejuaraan << " sudah ada." << endl;
            cout << "=========================================================" << endl;
            return;
        }
        existingRelasi = existingRelasi->nextRelasi;
    }

    // Membuat elemen relasi baru
    adrRelasi r = new relasi;
    r = newElmlistRelasi(m,k);
    if (r == NULL) {
        cout << "=========================================================" << endl;
        cout << "                 Memory allocation failed!               " << endl;
        cout << "=========================================================" << endl;
        return;
    }

    // Menambahkan relasi ke list
    insertFirstRelasi(L3, r);
    cout << "Relasi berhasil dibuat antara " << namaPeserta << " dan " << namaKejuaraan << "." << endl;
}


void disconnect(ListMHS &L1, ListKJR &L2, ListRelasi &L3, string namaPeserta, string namaKejuaraan) {
    adrMHS m = findMhsNama(L1, namaPeserta);
    adrKJR k = findKjr(L2, namaKejuaraan);

    if (m == NULL) {
        cout << "=========================================================" << endl;
        cout << "Peserta dengan nama '" << namaPeserta << "' tidak ditemukan." << endl;
        cout << "=========================================================" << endl;
        return;
    }
    if (k == NULL) {
        cout << "=========================================================" << endl;
        cout << "Kejuaraan dengan nama '" << namaKejuaraan << "' tidak ditemukan." << endl;
        cout << "=========================================================" << endl;
        return;
    }

    adrRelasi r = L3.first;
    adrRelasi prec = NULL;

    // Mencari relasi yang sesuai
    while (r != NULL) {
        if (r->infoMHS == m && r->infoKJR == k) {
            break; // Relasi ditemukan
        }
        prec = r;
        r = r->nextRelasi;
    }

    // Jika relasi tidak ditemukan
    if (r == NULL) {
        cout << "=========================================================" << endl;
        cout << "   Relasi antara peserta dan kejuaraan tidak ditemukan.  " << endl;
        cout << "=========================================================" << endl;
        cout << endl;
        return;
    }

    // Menghapus relasi berdasarkan posisinya
    if (r == L3.first) {
        // Jika relasi berada di awal list
        L3.first = r->nextRelasi;
    } else if (r->nextRelasi == NULL) {
        // Jika relasi berada di akhir list
        if (prec != NULL) {
            prec->nextRelasi = NULL;
        } else {
            L3.first = NULL; // List hanya memiliki satu elemen
        }
    } else {
        // Jika relasi berada di tengah list
        prec->nextRelasi = r->nextRelasi;
    }

    // Dealokasi memori relasi
    delete r;
    cout << "_________________________________________________________" << endl;
    cout << "Relasi antara " << namaPeserta << " dan " << namaKejuaraan << " berhasil dihapus." << endl;
    cout << "_________________________________________________________" << endl;
    cout << endl;
}


void printMhs(ListMHS L1, ListRelasi L3, string nama) {
    /* I.S ..............
       F.S  */
    adrMHS m;
    adrRelasi r;

    m = findMhsNama(L1, nama);

    if (m != NULL) {
        cout << "=========================================================" << endl;
        cout << "                       Data Peserta                      " << endl;
        cout << "=========================================================" << endl;
        cout << "Nama: " << m->info.nama << endl;
        cout << "Nim: " << m->info.NIM << endl;
        cout << "Jurusan: " << m->info.jurusan << endl;
        cout << "Usia: " << m->info.usia << endl;

        r = L3.first;
        bool found = false;

        cout << "_________________________________________________________" << endl;
        cout << "                       Kejuaraan                         " << endl;
        cout << "_________________________________________________________" << endl;
        cout << endl;

        while (r != NULL) {
            if (r->infoMHS == m) {
                cout << "Nama Kejuaraan: " << r->infoKJR->info.nama << endl;
                cout << "Tingkat: " << r->infoKJR->info.tingkat << endl;
                cout << "_________________________________________________________" << endl;
                cout << endl;
                found = true;
            }
            r = r->nextRelasi;
        }

        if (!found) {
            cout << "_________________________________________________________" << endl;
            cout << "                Tidak mengikuti Kejuaraan                " << endl;
            cout << "=========================================================" << endl;
            cout << endl;
        }
    } else {
        cout << "=========================================================" << endl;
        cout << "                  Peserta Tidak Ditemukan                " << endl;
        cout << "=========================================================" << endl;
        cout << endl;
    }
}

void printKjr(ListKJR L1, ListRelasi L3, string nama) {
    /* I.S ..............
       F.S  */
    adrKJR k;
    adrRelasi r;

    k = findKjr(L1, nama);

    if (k != NULL) { // Periksa apakah k ditemukan
        cout << "=========================================================" << endl;
        cout << "                      Data Kejuaraan                     " << endl;
        cout << "=========================================================" << endl;
        cout << endl;
        cout << "Nama : " << k->info.nama << endl;
        cout << "Tingkat : " << k->info.tingkat << endl;

        r = L3.first;
        bool found = false; // Flag untuk mengecek apakah ada peserta
        int i = 1;

        cout << "_________________________________________________________" << endl;
        cout << "                         Peserta                         " << endl;
        cout << "_________________________________________________________" << endl;
        cout << endl;

        while (r != NULL) {
            if (r->infoKJR == k) {
                cout << "Peserta ke-" << i << "." << endl;
                cout << "Nama : " << r->infoMHS->info.nama << endl;
                cout << "Nim : " << r->infoMHS->info.NIM << endl;
                cout << "Jurusan : " << r->infoMHS->info.jurusan << endl;
                cout << "_________________________________________________________" << endl;
                cout << endl;
                found = true; // Set flag jika peserta ditemukan
                i++;
            }
            r = r->nextRelasi; // Pindah ke relasi berikutnya
        }

        if (!found) { // Jika tidak ada peserta ditemukan
            cout << "_________________________________________________________" << endl;
            cout << "     Tidak ada peserta yang mengikuti kejuaraan ini      " << endl;
            cout << "=========================================================" << endl;
            cout << endl;
        }
    } else {
        cout << "=========================================================" << endl;
        cout << "                Kejuaraan Tidak Ditemukan                " << endl;
        cout << "=========================================================" << endl;
        cout << endl;
    }
}

void clearScreen(){
    system("cls");
}

void MAXKjr(ListKJR L1, ListRelasi L2) {
    adrRelasi r;
    adrKJR k = L1.first;
    adrKJR mostPopularKJR = NULL;
    int maxCount = 0;

    while (k != NULL) {
        int count = 0;
        r = L2.first;

        while (r != NULL) {
            if (r->infoKJR == k) {
                count++;
            }
            r = r->nextRelasi;
        }
        if (count > maxCount) {
            maxCount = count;
            mostPopularKJR = k;
        }

        k = k->nextKJR;
    }
    if (mostPopularKJR != NULL) {
        cout << "=========================================================" << endl;
        cout << "                Kejuaraan Paling Diminati                " << endl;
        cout << "_________________________________________________________" << endl;
        cout << "Nama Kejuaraan : " << mostPopularKJR->info.nama << endl;
        cout << "Tingkat : " << mostPopularKJR->info.tingkat << endl;
        cout << "=========================================================" << endl;
        cout << endl;

    } else {
        cout << "=========================================================" << endl;
        cout << "                Kejuaraan Tidak Ditemukan                " << endl;
        cout << "=========================================================" << endl;
        cout << endl;
    }
}

void MINMhs(ListMHS L1, ListRelasi L2) {
    adrMHS leastParticipatingMHS = NULL;
    adrMHS m = L1.first;
    int minCount = INT_MAX;

    while (m != NULL) {
        int count = 0;
        adrRelasi r = L2.first;

        while (r != NULL) {
            if (r->infoMHS == m) {
                count++;
            }
            r = r->nextRelasi;
        }
        if (count < minCount) {
            minCount = count;
            leastParticipatingMHS = m;
        }
        m = m->nextMHS;
    }

    if (leastParticipatingMHS != NULL) {
        cout << "=========================================================" << endl;
        cout << "          Peserta paling sedikit mengikuti lomba         " << endl;
        cout << "_________________________________________________________" << endl;
        cout << "Nama: " << leastParticipatingMHS->info.nama << endl;
        cout << "NIM: " << leastParticipatingMHS->info.NIM << endl;
        cout << "Usia: " << leastParticipatingMHS->info.usia << endl;
        cout << "Jurusan: " << leastParticipatingMHS->info.jurusan << endl;
        cout << "=========================================================" << endl;
        cout << endl;
    } else {
        cout << "=========================================================" << endl;
        cout << "                 Peserta Tidak Ditemukan                 " << endl;
        cout << "=========================================================" << endl;
        cout << endl;
    }
}

void printKseluruhanMHS(ListMHS L1, ListRelasi L3){
    adrMHS m;
    adrRelasi r;

    m = L1.first;

    if (m!=NULL){
        while (m!=NULL){
            cout << "=========================================================" << endl;
            cout << "                       Data Peserta                      " << endl;
            cout << "=========================================================" << endl;
            cout << "Nama: " << m->info.nama << endl;
            cout << "Nim: " << m->info.NIM << endl;
            cout << "Jurusan: " << m->info.jurusan << endl;
            cout << "Usia: " << m->info.usia << endl;

            r = L3.first;
            bool found = false;

            cout << "_" << endl;
            cout << "                       Kejuaraan                         " << endl;
            cout << "_" << endl;
            cout << endl;

            while (r!=NULL){
                if (r->infoMHS == m){
                    cout << "Nama Kejuaraan: " << r->infoKJR->info.nama << endl;
                    cout << "Tingkat: " << r->infoKJR->info.tingkat << endl;
                    cout << "_" << endl;
                    cout << endl;
                    found = true;
                }
                r = r->nextRelasi;
            }
            if (!found) {
                cout << "_" << endl;
                cout << "                Tidak mengikuti Kejuaraan                " << endl;
                cout << "=========================================================" << endl;
                cout << endl;
            }
            m = m->nextMHS;
        }
    } else {
            cout << "====================== List Kosong ======================" << endl;
    }
}
