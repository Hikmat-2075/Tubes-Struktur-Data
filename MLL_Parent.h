#ifndef MLL_PARENT_H_INCLUDED
#define MLL_PARENT_H_INCLUDED

#include <iostream>

using namespace std;

struct infoMHS {

    string nama;
    string NIM;
    string jurusan;
    int usia;

};

typedef struct MHS *adrMHS;

struct MHS {
    infoMHS info;
    adrMHS nextMHS;
    adrMHS prevMhs;
};

struct ListMHS {
    adrMHS first;
    adrMHS last;
};

void createListMhs(ListMHS &L);
adrMHS newElmlistMhs(infoMHS x);

bool isEmptyMhs(ListMHS L);

void insertFirstMhs(ListMHS &L, adrMHS mhs);
void insertLastMHS(ListMHS &L, adrMHS mhs);
void insertAfterMHS(ListMHS &L, adrMHS mhs, adrMHS prec);

void deleteFirstMhs(ListMHS &L, adrMHS &mhs);
void deleteLastMhs(ListMHS &L, adrMHS &mhs);
void deleteAfterMhs(ListMHS &L, adrMHS prec, adrMHS &mhs);

adrMHS findMhsNIM(ListMHS L, string NIM);
adrMHS findMhsNama(ListMHS L, string nama);

void AscendingUsia(ListMHS &L1);
void AscendingJurusan(ListMHS &L1);
void AscendingNama(ListMHS &L1);
void AscendingNIM(ListMHS &L1);

void DescendingUsia(ListMHS &L1);
void DescendingJurusan(ListMHS &L1);
void DescendingNama(ListMHS &L1);
void DescendingNIM(ListMHS &L1);



void printListMhs(ListMHS L);


#endif // MLL_PARENT_H_INCLUDED
