#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void Nhapmang(int**& a, int& d, int& c) {
    cout << "Nhap d, c = ";
    cin >> d >> c;
    a = new int* [d];
    for (int i = 0; i < d; i++) {
        a[i] = new int[c];
    }
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < c; j++) {
            cout << "a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
}

void xoacacphantuisPrimenumber(int**& a, int d, int& c) {
    cout << "Mang sau khi xoa cac phan tu nguyen to: " << endl;
    for (int i = 0; i < d; i++) {
        int new_n = c;
        for (int j = 0; j < new_n; j++) {
            if (isPrime(a[i][j])) {
                for (int k = j; k < new_n - 1; k++) {
                    a[i][k] = a[i][k + 1];
                }
                new_n--;
                j--;
            }
        }
        for (int j = 0; j < new_n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void Xuatmang(int** a, int d, int c) {
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < c; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}

void Thuhoi(int**& a, int d) {
    for (int i = 0; i < d; i++) {
        delete[] a[i];
    }
    delete[] a;
}

int main() {
    int** a;
    int d, c;
    Nhapmang(a, d, c);      
    cout << "Mang ban dau:\n";
    Xuatmang(a, d, c);
    xoacacphantuisPrimenumber(a, d, c);
    Thuhoi(a, d);
    return 0;
}
