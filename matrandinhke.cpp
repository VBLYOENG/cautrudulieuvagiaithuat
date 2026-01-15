#include <iostream>
using namespace std;

#define MAX 12   
int maTranKe[MAX][MAX];
int soDinh = 11;
void khoiTaoMaTran() {
    for (int i = 1; i <= soDinh; i++)
        for (int j = 1; j <= soDinh; j++)
            maTranKe[i][j] = 0;
}
void themCanh(int u, int v) {
    maTranKe[u][v] = 1;
    maTranKe[v][u] = 1;   // đồ thị vô hướng
}
void inMaTranKe() {
    cout << "Ma tran ke:\n";
    for (int i = 1; i <= soDinh; i++) {
        for (int j = 1; j <= soDinh; j++)
            cout << maTranKe[i][j] << " ";
        cout << endl;
    }
}
int main() {
    khoiTaoMaTran(); 
    themCanh(1,2); themCanh(2,11); themCanh(10,11); themCanh(1,10); themCanh(1,9);
    themCanh(1,8); themCanh(1,7); themCanh(1,6); themCanh(6,5); themCanh(5,4);
    themCanh(6,4); themCanh(4,3); themCanh(2,3);
    inMaTranKe();
    return 0;
}