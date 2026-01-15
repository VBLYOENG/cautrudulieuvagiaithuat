#include <iostream>
using namespace std;

#define MAX 12
struct Nut {
    int dinhKe;
    Nut* tiepTheo;
};
Nut* danhSachKe[MAX];
int soDinh = 11;
void khoiTaoDanhSach() {
    for (int i = 1; i <= soDinh; i++)
        danhSachKe[i] = NULL;
}
void themCanh(int u, int v) {
    Nut* p = new Nut;
    p->dinhKe = v;
    p->tiepTheo = danhSachKe[u];
    danhSachKe[u] = p;
    Nut* q = new Nut;
    q->dinhKe = u;
    q->tiepTheo = danhSachKe[v];
    danhSachKe[v] = q;
}
void inDanhSachKe() {
    cout << "Danh sach ke:\n";
    for (int i = 1; i <= soDinh; i++) {
        cout << i << ": ";
        Nut* p = danhSachKe[i];
        while (p != NULL) {
            cout << p->dinhKe << " -> ";
            p = p->tiepTheo;
        }
        cout << "NULL\n";
    }
}
int main() {
    khoiTaoDanhSach();
    themCanh(1,2); themCanh(2,11); themCanh(10,11); themCanh(1,10); themCanh(1,9); themCanh(1,8);
    themCanh(1,7); themCanh(1,6); themCanh(6,5); themCanh(5,4); themCanh(6,4); themCanh(4,3); themCanh(2,3);
    inDanhSachKe();
    return 0;
}