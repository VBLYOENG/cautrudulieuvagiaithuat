#include <iostream>
#include <string>
using namespace std;

struct Nut {
    string tieuDe;      
    int soTrang;        
    int chiSo;         
    Nut* conDau;       
    Nut* emKe;          
        Nut(string td, int st, int cs) {
        tieuDe = td;
        soTrang = st;
        chiSo = cs;
        conDau = NULL;
        emKe = NULL;
        }
};
int demSoChuong(Nut* goc) {
    if (goc == NULL || goc->conDau == NULL) return 0;
    int dem = 0;
    Nut* tam = goc->conDau; 
    while (tam != NULL) {
        dem++;
        tam = tam->emKe;
    }
    return dem;
}
int tinhTongSoTrang(Nut* n) {
    if (n == NULL) return 0;
    int tong = n->soTrang;
    Nut* con = n->conDau;
    while (con != NULL) {
        tong += tinhTongSoTrang(con);
        con = con->emKe;
    }
    return tong;
}
void timChuongDaiNhat(Nut* goc) {
    if (goc == NULL || goc->conDau == NULL) return;
    Nut* chuongLonNhat = NULL;
    int trangMax = -1;

    Nut* hienTai = goc->conDau;
    while (hienTai != NULL) {
        int tongTrang = tinhTongSoTrang(hienTai);
        if (tongTrang > trangMax) {
            trangMax = tongTrang;
            chuongLonNhat = hienTai;
        }
        hienTai = hienTai->emKe;
    }
    if (chuongLonNhat != NULL) {
        cout << "Chuong dai nhat la: " << chuongLonNhat->tieuDe 
             << " voi tong " << trangMax << " trang." << endl;
    }
}
void inDeMucChuong(Nut* goc, int chiSoCanTim) {
    Nut* chuong = goc->conDau;
    while (chuong != NULL) {
        if (chuong->chiSo == chiSoCanTim) {
            cout << "Cac de muc trong " << chuong->tieuDe << ":" << endl;
            Nut* mucCon = chuong->conDau;
            while (mucCon != NULL) {
                cout << " + " << mucCon->tieuDe << " (Trang: " << mucCon->soTrang << ")" << endl;
                mucCon = mucCon->emKe;
            }
            return;
        }
        chuong = chuong->emKe;
    }
    cout << "Khong tim thay chuong co chi so " << chiSoCanTim << endl;
}
bool xoaMuc(Nut* &cha, string tenCanXoa) {
    if (cha == NULL) return false;

    Nut* truoc = NULL;
    Nut* hienTai = cha->conDau;

    while (hienTai != NULL) {
        if (hienTai->tieuDe == tenCanXoa) {
            if (truoc == NULL) cha->conDau = hienTai->emKe;
            else truoc->emKe = hienTai->emKe;
            delete hienTai; 
            return true;
        }
        if (xoaMuc(hienTai, tenCanXoa)) return true;

        truoc = hienTai;
        hienTai = hienTai->emKe;
    }
    return false;
}