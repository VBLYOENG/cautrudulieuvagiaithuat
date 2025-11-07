#include <iostream>
using namespace std;

void inmang(int A[], int first, int last) {
    for (int i = first; i <= last; i++)
        cout << A[i] << " ";
    cout << endl;
}

void gopMang(int A[], int m, int n, int p) {
    int i = m, j = n + 1;

    cout << "Ghép hai mảng: ";
    inmang(A, m, n);
    cout << "và ";
    inmang(A, n + 1, p);

    while (i < j && j <= p) {
        if (A[i] <= A[j]) i++;
        else {
            int x = A[j];
            for (int k = j - 1; k >= i; k--)
                A[k + 1] = A[k];
            A[i] = x;
            i++;
            j++;
        }
    }
    cout << "Mảng sau khi ghép: ";
    inmang(A, m, p);
    cout << endl;
}

void TachMang(int A[], int first, int last) {
    if (first >= last) return;
    int m = (first + last) / 2;
    TachMang(A, first, m);      
    TachMang(A, m + 1, last);   
    gopMang(A, first, m, last); 
}

void hamTron(int A[], int N) {
    if (N < 2) return;
    TachMang(A, 0, N - 1);
}

int main() {
    int A[] = {3, 10, 1, 23, 103, 34, 17, 53, 64, 71};
    int N = sizeof(A) / sizeof(A[0]);
    cout << "Mảng ban đầu: ";
    for (int i = 0; i < N; i++) cout << A[i] << " ";
    cout << "\n\n";
    hamTron(A, N);
    cout << "Mảng sau khi sắp xếp: ";
    for (int i = 0; i < N; i++) cout << A[i] << " ";
    cout << endl;
    return 0;
}
