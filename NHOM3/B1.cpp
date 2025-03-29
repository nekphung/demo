// Sap xep cac phan tu tren cung mot dong sao cho no giam dan
#include <iostream>
#include <cmath>
using namespace std;

void Nhapmang(int**& a, int& d, int& c) {
    FILE* f;
    fopen_s(&f, "Matrix.txt", "rt");
    if (f == NULL) {
        cout << "Mo file khong thanh cong!" << endl;
        return;
    }
    a = new int* [d];
    for (int i = 0; i < d; i++) {
        a[i] = new int[c];
    }
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < c; j++) {
            fscanf_s(f, "%d", &a[i][j]);
        }
    }
    fclose(f);
}
void Hoanvi(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void Sapxepgiamcacphantutrendong(int**& a, int d, int c) {
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < c - 1; j++) {
            for (int k = j + 1; k < c; k++) {
                if (a[i][j] < a[i][k]) {
                    Hoanvi(a[i][j], a[i][k]);
                }
            }
        }
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
    d = 4; c = 6;
    Nhapmang(a, d, c);
    cout << "Mang ban dau:\n";
    Xuatmang(a, d, c);
    cout << "Mang sau khi sap xep: \n";
    Sapxepgiamcacphantutrendong(a, d, c);
    Xuatmang(a, d, c);
    Thuhoi(a, d);
    return 0;
}
