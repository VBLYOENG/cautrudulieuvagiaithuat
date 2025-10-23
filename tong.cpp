#include <iostream>
using namespace std;
 int main () {
    int n, S = 0;
    std :: cin >> n;
    for (int i = 0; i <= n; i ++) {
        S += i;
    }
    std :: cout << S;
 }