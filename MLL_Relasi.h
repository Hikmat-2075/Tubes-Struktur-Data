#ifndef MLL_RELASI_H_INCLUDED
#define MLL_RELASI_H_INCLUDED

#include <iostream>

using namespace std;

#include "MLL_Child.h"
#include "MLL_Parent.h"

typedef struct relasi *adrRelasi;

struct relasi {
    adrRelasi nextRelasi;
    adrKJR infoKJR;
    adrMHS infoMHS;
};

struct ListRelasi {
    adrRelasi first;
};

void createListRelasi(ListRelasi &L);
adrRelasi newElmlistRelasi(adrMHS m, adrKJR k);
bool isEmptyRelasi(ListRelasi L);

void insertFirstRelasi(ListRelasi &L, adrRelasi r);
void insertLastRelasi(ListRelasi &L, adrRelasi r);
void insertAfterRelasi(ListRelasi &L, adrRelasi r, adrRelasi prec);

void deleteFirstRelasi(ListRelasi &L, adrRelasi &r);
void deleteLastRelasi(ListRelasi &L, adrRelasi &r);
void deleteAfterRelasi(ListRelasi &L, adrRelasi &r, adrRelasi prec);

adrRelasi findRelasi(ListRelasi L, adrMHS m, adrKJR k);

void deleteRelasiByParent(ListRelasi &LRelasi, adrMHS parent);
void deleteRelasiByChild(ListRelasi &LRelasi, adrKJR child);

void printListRelasi(ListRelasi L);

#endif // MLL_RELASI_H_INCLUDED
