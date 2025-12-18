#include <iostream>
#include <string>
using namespace std;
struct CayTuanTu {
    string data[101];
    int n;
};
void khoiTao(CayTuanTu &cay) {
    cay.n = 0;
}
bool cayRong(CayTuanTu cay) {
    return cay.n == 0;
}
void themNut(CayTuanTu &cay, string giatri) {
    cay.data[++cay.n] = giatri;
}
void duyetTruoc(CayTuanTu cay, int i) {
    if (i > cay.n) return;
    cout << cay.data[i] << " ";
    duyetTruoc(cay, 2 * i);
    duyetTruoc(cay, 2 * i + 1);
}
void duyetGiua(CayTuanTu cay, int i) {
    if (i > cay.n) return;
    duyetGiua(cay, 2 * i);
    cout << cay.data[i] << " ";
    duyetGiua(cay, 2 * i + 1);
}
void duyetSau(CayTuanTu cay, int i) {
    if (i > cay.n) return;
    duyetSau(cay, 2 * i);
    duyetSau(cay, 2 * i + 1);
    cout << cay.data[i] << " ";
}

int main() {
    CayTuanTu cay;
    khoiTao(cay);
    themNut(cay, "A");    
    themNut(cay, "A1");    
    themNut(cay, "A2");   
    themNut(cay, "A1.1"); 
    themNut(cay, "A1.2"); 
    themNut(cay, "A2.1"); 
    themNut(cay, "A2.2"); 
    cout << "Duyet truoc: ";
    duyetTruoc(cay, 1);
    cout << "\nDuyet giua: ";
    duyetGiua(cay, 1);
    cout << "\nDuyet sau: ";
    duyetSau(cay, 1);
    return 0;
}