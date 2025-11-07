#include <iostream>
#include <vector>
using namespace std;

void inmang(const vector<int>& A) {
    for (int x : A) cout << x << " ";
    cout << endl;
}

int HamChiaTach(vector<int>& A, int left, int right, int chisochot) {
    int chot = A[chisochot];
    int i = left + 1;
    int j = right;

    cout << "Chọn chot = " << chot << ", mảng hiện tại: ";
    for (int k = left; k <= right; k++) cout << A[k] << " ";
    cout << endl;

    while (i <= j) {
        while (i <= right && A[i] < chot) i++;
        while (j >= left && A[j] > chot) j--;
        if (i < j) {
            swap(A[i], A[j]);
            cout << "  Hoán vị A[" << i << "] và A[" << j << "] → ";
            inmang(A);
            i++;
            j--;
        } else break;
    }

    swap(A[left], A[j]);  
    cout << "  Đặt chot về vị trí " << j << " → ";
    inmang(A);
    cout << endl;

    return j; 
}

void XepNhanh(vector<int>& A, int left, int right, int buoc = 0) {
    if (right - left <= 0) return;
    else {
        int chisochot = left; 
        cout << string(buoc * 2, ' ') << "XepNhanh(A, " << left << ", " << right << ")\n";
        int partition = HamChiaTach(A, left, right, chisochot);
        XepNhanh(A, left, partition - 1, buoc + 1);
        XepNhanh(A, partition + 1, right, buoc + 1);
    }
}

int main() {
    vector<int> A = {3, 10, 1, 23, 103, 34, 17, 53, 64, 71};
    cout << "Mảng ban đầu: ";
    inmang(A);

    XepNhanh(A, 0, A.size() - 1);

    cout << "Mảng sau khi sắp xếp: ";
    inmang(A);

    return 0;
}

