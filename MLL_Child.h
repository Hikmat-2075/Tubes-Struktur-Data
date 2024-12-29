#ifndef MLL_CHILD_H_INCLUDED
#define MLL_CHILD_H_INCLUDED

#include <iostream>

using namespace std;

struct infoKJR {
    string nama;
    string tingkat;
};

typedef struct Kejuaraan *adrKJR;

struct Kejuaraan {
    infoKJR info;
    adrKJR nextKJR;
    adrKJR prevKJR;
};

struct ListKJR {
    adrKJR first;
    adrKJR last;
};

void createListKjr(ListKJR &L);
adrKJR newElmlistKjr(infoKJR x);

void insertFirstKJR(ListKJR &L, adrKJR kjr);
void insertLastKJR(ListKJR &L, adrKJR kjr);
void insertAfterKJR(ListKJR &L, adrKJR kjr, adrKJR prec);

void deleteFirstKjr(ListKJR &L, adrKJR &kjr);
void deleteLastKjr(ListKJR &L, adrKJR &kjr);
void deleteAfterKjr(ListKJR &L, adrKJR &kjr, adrKJR prec);

adrKJR findKjr(ListKJR L, string nama);
void printListKjr(ListKJR L);

#endif // MLL_CHILD_H_INCLUDED
