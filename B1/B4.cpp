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
// Sửa ở đây

bool CheckNT(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (!isPrime(a[i])) {
            return false;
        }
    }
    return true;
}
void Delete_element(int a[], int &n, int k) {
    for (int i = k; i < n - 1; i++) {
        a[i] = a[i + 1];
      }
    n--;
}

void Insert_element(int a[], int& n, int x, int k) {
    for (int i = n - 1; i >= k; i--) {
        a[i + 1] = a[i];
    }
    a[k] = x;
    n++;
}

int CheckMangConNT(int a[], int& n, int ketQuaMang[]) {
    int soLuongMangCon = 0;

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            int *subArray = new int[j - i + 1];
            int cnt = 0;

            for (int k = i; k <= j; k++) {
                subArray[cnt++] = a[k];
            }

            if (CheckNT(subArray, cnt)) {
                int sum = 0;
                for (int k = 0; k < cnt; k++) {
                    sum += subArray[k];
                }
                ketQuaMang[soLuongMangCon++] = sum; 
            }
            delete[] subArray;
        }
    }
    int idxkq = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(a[i])) {
            while (isPrime(a[i]) && i < n) {
                Delete_element(a, n, i);
            }
            Insert_element(a, n, ketQuaMang[idxkq++], i);
        }
    }
    return soLuongMangCon;
}

int main() {
    int a[100], n;
    cout << "Nhap n = ";
    cin >> n;
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ketQuaMang[100];
    int soLuongMangCon = CheckMangConNT(a, n, ketQuaMang);

    cout << "So luong mang con: " << soLuongMangCon << endl;
    cout << "Mang sau khi chen tong cac so nguyen to: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
