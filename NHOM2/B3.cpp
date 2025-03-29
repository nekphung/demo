// Sap xep mang theo chieu co tong cac phan tu tren dong giam dan trong ma tran
// 1 2 3 4 
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16
#include <iostream>
using namespace std;
void Nhapmang(int**& a, int& n) {
    cout << "Nhap n = ";
    cin >> n;
    a = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
}
void Xuatmang(int** a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
int sum_Row(int** a, int n, int k) {
    if (k < 0 || k >= n) return 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[k][i];
    }
    return sum;
}
void Hoanvi(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}
void Hoanvi2dong(int**& a, int n, int m, int k) {
    for (int i = 0; i < n; i++) {
        Hoanvi(a[m][i], a[k][i]);
    }
}

void Sapxeptongdonggiam(int**& a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int sum1 = sum_Row(a, n, i);
        for (int j = i + 1; j < n; j++) {
            int sum2 = sum_Row(a, n, j);
            if (sum1 < sum2) {
                Hoanvi2dong(a, n, i, j);
            }
        }
    }
}
void Thuhoi(int**& a, int d) {
    for (int i = 0; i < d; i++) {
        delete[] a[i];
    }
    delete[] a;
}
int main() {
    int** a = NULL;
    int n;
    Nhapmang(a, n);
    Sapxeptongdonggiam(a, n);
    Xuatmang(a, n);
    Thuhoi(a, n);
    return 0;
}