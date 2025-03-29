#include <iostream>
using namespace std;

void Nhapmatran(int**& a, int& n, int& m) {
    cout << "Nhap n = ";
    cin >> n;
    cout << "Nhap m = ";
    cin >> m;
    a = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Nhap a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
}

void MinximumPathSum(int** a, int n, int m) {
    int** b = new int* [n];
    for (int i = 0; i < n; i++) {
        b[i] = new int[m]; 
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                b[i][j] = a[i][j];
            }
            else if (j == 0) {
                b[i][j] = b[i - 1][j] + a[i][j];
            }
            else if (i == 0) {
                b[i][j] = b[i][j - 1] + a[i][j];
            }
            else {
                b[i][j] = min(b[i - 1][j], b[i][j - 1]) + a[i][j];
            }
        }
    }
    cout << "Tong duong di nho nhat: " << b[n - 1][m - 1] << endl;
    for (int i = 0; i < n; i++) {
        delete[] b[i];
    }
    delete[] b;
}

int main() {
    int** a = NULL;
    int n, m;
    Nhapmatran(a, n, m);
    MinximumPathSum(a, n, m);
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
    return 0;
}
