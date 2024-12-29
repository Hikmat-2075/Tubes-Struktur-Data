#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#include <iostream>

using namespace std;

#include "MLL_Child.h"
#include "MLL_Parent.h"
#include "MLL_Relasi.h"
#include "menu.h"

void printKseluruhanMHS(ListMHS L1, ListRelasi L3);

void pilihMenu(ListMHS &L1, ListKJR &L2, ListRelasi &L3, infoMHS mhs, infoKJR kjr);

void connect(ListMHS &L1, ListKJR &L2, ListRelasi &L3, string namaPeserta, string namaKejuaraan);
void disconnect(ListMHS &L1, ListKJR &L2, ListRelasi &L3, string namaPeserta, string namaKejuaraan);

void printKjr(ListKJR L1, ListRelasi L2, string nama);
void printMhs(ListMHS L1, ListRelasi L3, string nama);

void MAXKjr(ListKJR L1, ListRelasi L2);
void MINMhs(ListMHS L1, ListRelasi L2);
void clearScreen();

#endif // GLOBAL_H_INCLUDED
