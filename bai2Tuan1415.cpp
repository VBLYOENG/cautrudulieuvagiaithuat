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
bool kiemTraGiongNhau(CayTuanTu c1, CayTuanTu c2) {
    if (c1.n != c2.n) {
        return false;
    }
    for (int i = 1; i <= c1.n; i++) {
        if (c1.data[i] != c2.data[i]) {
            return false; 
        }
    }
    return true; 
}

int main() {
    CayTuanTu cayA, cayB, cayC;
    khoiTao(cayA); khoiTao(cayB); khoiTao(cayC);

    int a[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    for (int i = 0; i < 10; i++) {
        themNut(cayA, a[i]);
        themNut(cayB, a[i]);
    }
    for (int i = 0; i < 9; i++) themNut(cayC, a[i]);
    themNut(cayC, 2006);
    cout << "so sanh cayA va cayB: ";
    if (kiemTraGiongNhau(cayA, cayB)) cout << "giong" << endl;
    else cout << "khac" << endl;

    cout << "so sanh cayA va cayC: ";
    if (kiemTraGiongNhau(cayA, cayC)) cout << "giong" << endl;
    else cout << "khac" << endl;
    return 0;
}