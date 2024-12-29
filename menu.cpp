#include "menu.h"

void menuUtama(int &pilihan){
    cout << "=========================================================" << endl;
	cout << "   Aplikasi Pengelolaan Data Kejuaraan dan Perlombaan    " << endl;
	cout << "=========================================================" << endl;
    cout << "1. Tambah Data" << endl;
    cout << "2. Hapus Data" << endl;
    cout << "3. Tampilkan Data" << endl;
    cout << "0. Keluar" << endl;
    cout << "========================================================="<< endl;
    cout << "Pilih Menu: ";
    cin >> pilihan;
    cout << endl;
}

void menuTambah(int &pilihan){
    cout << "=========================================================" << endl;
	cout << "                       Menu Tambah                       " << endl;
	cout << "=========================================================" << endl;
    cout << "1. Masukan Data Peserta" << endl;
    cout << "2. Masukan Data kejuaraan" << endl;
    cout << "3. Masukan Relasi" << endl;
    cout << "0. Kembali ke Menu Utama" << endl;
	cout << "=========================================================" << endl;
    cout << "Pilih Menu: ";
    cin >> pilihan;
    cout << endl;
}

void menuHapus(int &pilihan){
    cout << "=========================================================" << endl;
	cout << "                        Menu Hapus                       " << endl;
	cout << "=========================================================" << endl;
    cout << "1. Hapus Data Peserta" << endl;
    cout << "2. Hapus Data kejuaraan" << endl;
    cout << "3. Hapus Relasi" << endl;
    cout << "0. Kembali ke Menu Utama" << endl;
    cout << "=========================================================" << endl;
    cout << "Pilih Menu: ";
    cin >> pilihan;
    cout << endl;
}

void menuShow(int &pilihan){
    cout << "=========================================================" << endl;
	cout << "                        Menu Show                        " << endl;
	cout << "=========================================================" << endl;
    cout << "1. Ascending" << endl;
    cout << "2. Descending" << endl;
    cout << "3. Kejuaraan yang paling banyak diikuti" << endl;
    cout << "4. Peserta yang mengikuti lomba paling sedikit" << endl;
    cout << "5. Peserta dan lomba yang diikutinya" << endl;
    cout << "6. kejuaraan dan peserta yang diikutinya" << endl;
    cout << "7. Data Peserta" << endl;
    cout << "8. Data Kejuaraan" << endl;
    cout << "9. Print Keseluruhan Peserta dan Lomba yang diikutinya" << endl;
    cout << "0. Kembali ke Menu Utama" << endl;
	cout << "=========================================================" << endl;
    cout << "Pilih Menu: ";
    cin >> pilihan;
    cout << endl;
}

void Finish(){
    cout << "=========================================================" << endl;
    cout << "       TERIMA KASIH TELAH MENGGUNAKAN APLIKASI INI       " << endl;
    cout << "=========================================================" << endl;
}

void MenuAscending(){
    cout << "=========================================================" << endl;
    cout << "                    Menu Ascending                       " << endl;
    cout << "=========================================================" << endl;
    cout << "1. Ascending Nama" << endl;
    cout << "2. Ascending NIM" << endl;
    cout << "3. Ascending Jurusan" << endl;
    cout << "4. Ascending Usia" << endl;
    cout << "0. Kembali ke Menu Show" << endl;
    cout << "=========================================================" << endl;
    cout << "Pilih Menu: ";
}

void MenuDescending(){
    cout << "=========================================================" << endl;
    cout << "                    Menu Descending                      " << endl;
    cout << "=========================================================" << endl;
    cout << "1. Descending Nama" << endl;
    cout << "2. Descending NIM" << endl;
    cout << "3. Descending Jurusan" << endl;
    cout << "4. Descending Usia" << endl;
    cout << "=========================================================" << endl;
    cout << "Pilih Menu: ";
}
