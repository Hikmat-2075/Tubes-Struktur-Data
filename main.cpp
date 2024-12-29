#include <iostream>
#include "Global.h"
using namespace std;
int main()

{
    ListKJR LK;
    ListMHS LM;
    ListRelasi LR;

    infoMHS mhs;
    infoKJR kjr;

    createListMhs(LM);
    createListKjr(LK);
    createListRelasi(LR);

    pilihMenu(LM, LK, LR, mhs, kjr);

    return 0;
}
