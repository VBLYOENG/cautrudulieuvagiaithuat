#include <iostream>
#include <string>
using namespace std;

struct Nut {
    string duLieu;
    Nut* trai;
    Nut* phai;
};
Nut* taoNut(string giaTri) {
    Nut* nut = new Nut;
    nut->duLieu = giaTri;
    nut->trai = NULL;
    nut->phai = NULL;
    return nut;
}
bool cayRong(Nut* goc) {
    return goc == NULL;
}
void themConTrai(Nut* nutCha, string giaTri) {
    nutCha->trai = taoNut(giaTri);
}
void themConPhai(Nut* nutCha, string giaTri) {
    nutCha->phai = taoNut(giaTri);
}
void duyetTruoc(Nut* goc) {
    if (goc == NULL) return;
    cout << goc->duLieu << " ";
    duyetTruoc(goc->trai);
    duyetTruoc(goc->phai);
}
void duyetGiua(Nut* goc) {
    if (goc == NULL) return;
    duyetGiua(goc->trai);
    cout << goc->duLieu << " ";
    duyetGiua(goc->phai);
}
void duyetSau(Nut* goc) {
    if (goc == NULL) return;
    duyetSau(goc->trai);
    duyetSau(goc->phai);
    cout << goc->duLieu << " ";
}

int main() {
    Nut* goc = taoNut("A");
    themConTrai(goc, "A1");
    themConPhai(goc, "A2");
    themConTrai(goc->trai, "A1.1");
    themConPhai(goc->trai, "A1.2");
    themConTrai(goc->phai, "A2.1");
    themConPhai(goc->phai, "A2.2");
    cout << "Duyet truoc: ";
    duyetTruoc(goc);
    cout << "\nDuyet giua: ";
    duyetGiua(goc);
    cout << "\nDuyet sau: ";
    duyetSau(goc);
    return 0;
}
