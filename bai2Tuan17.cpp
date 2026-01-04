#include <iostream>
#include <string>
using namespace std;

struct Nut {
    int chiSo;          
    string tenMuc;      
    Nut *trai;          
    Nut *phai;          
        Nut(int cs, string tm) {
        chiSo = cs;
        tenMuc = tm;
        trai = nullptr;
        phai = nullptr;
        }
};
bool kiemTraBanSao(Nut* goc1, Nut* goc2) {
    if (goc1 == nullptr && goc2 == nullptr) {
        return true;
    }
    if (goc1 != nullptr && goc2 != nullptr) {
        return (goc1->chiSo == goc2->chiSo) &&          
               (goc1->tenMuc == goc2->tenMuc) &&         
               kiemTraBanSao(goc1->trai, goc2->trai) && 
               kiemTraBanSao(goc1->phai, goc2->phai);   
    }
    return false;
}

int main() {
    Nut* sach1 = new Nut(1, "Chuong 1");
    sach1->trai = new Nut(11, "Muc 1.1");
    sach1->phai = new Nut(12, "Muc 1.2");
    Nut* sach2 = new Nut(1, "Chuong 1");
    sach2->trai = new Nut(11, "Muc 1.1");
    sach2->phai = new Nut(12, "Muc 1.2");
    Nut* sach3 = new Nut(1, "Chuong 1");
    sach3->trai = new Nut(11, "Muc 1.1");
    sach3->phai = new Nut(99, "Muc Bi Thay Doi");
    cout << "So sanh Sach 1 va Sach 2:" << endl;
    if (kiemTraBanSao(sach1, sach2)) {
        cout << "=> hai cuon sach la ban copy cua nhau" << endl;
    } else {
        cout << "=> hai cuon sach KHONG phai la ban copy cua nhau" << endl;
    }
    cout << "\nSo sanh Sach 1 va Sach 3:" << endl;
    if (kiemTraBanSao(sach1, sach3)) {
        cout << "=> hai cuon sach la ban copy cua nhau" << endl;
    } else {
        cout << "=> hai cuon sach KHONG phai la ban copy cua nhau" << endl;
    }
    return 0;
}