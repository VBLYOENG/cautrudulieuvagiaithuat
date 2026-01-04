#include <iostream>
using namespace std;

struct CayTuanTu {
    int data[101]; 
    int n;
};
void khoiTao(CayTuanTu &cay) {
    cay.n = 0;
}
void themNut(CayTuanTu &cay, int giatri) {
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
void vunDong(CayTuanTu &cay, int n, int i) {
    int max = i;     
    int trai = 2 * i;    
    int phai = 2 * i + 1; 
    if (trai <= n && cay.data[trai] > cay.data[max])
        max = trai;
    if (phai <= n && cay.data[phai] > cay.data[max])
        max = phai;
    if (max != i) {
        int temp = cay.data[i];
        cay.data[i] = cay.data[max];
        cay.data[max] = temp;
        vunDong(cay, n, max);
    }
}
void buildMaxHeap(CayTuanTu &cay) {
    for (int i = cay.n / 2; i >= 1; i--) {
        vunDong(cay, cay.n, i);
    }
}

int main() {
    CayTuanTu cay;
    khoiTao(cay);
    int a[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    for (int i = 0; i < 10; i++) {
        themNut(cay, a[i]);
    }

    cout << "cau1" << endl;
    cout << "Duyet truoc: "; duyetTruoc(cay, 1); cout << endl;
    cout << "Duyet giua:  "; duyetGiua(cay, 1);  cout << endl;
    cout << "Duyet sau:   "; duyetSau(cay, 1);   cout << endl;
    cout << "\n--- cau2" << endl;
    buildMaxHeap(cay);
    cout << "Duyet truoc sau khi vun dong: ";
    duyetTruoc(cay, 1);
    cout << endl;

    return 0;
}