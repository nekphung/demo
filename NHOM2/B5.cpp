#include <iostream>
using namespace std;
void Nhapmang(int**& a, int& n) {
    cout << "Nhap n = ";
    cin >> n;
    a = new int* [n];
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
bool checkPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}
void INMATRANXOAYOC(int** a, int dong, int cot, int *A) {
	int cnt = 0;
	int h1 = 0, h2 = dong - 1, c1 = 0, c2 = cot - 1;
	while (h1 <= h2 && c1 <= c2) {
		// Xay dung hang tren cung
		for (int i = c1; i <= c2; i++) {
			A[cnt++] = a[h1][i];
		}
		++h1;
		// Xay dung cot ben phai
		for (int i = h1; i <= h2; i++) {
			A[cnt++] = a[i][c2];
		}
		--c2;
		// Xay dung hang cuoi cung
		if (c1 <= c2) {
			for (int i = c2; i >= c1; i--) {
				A[cnt++] = a[h2][i];
			}
			--h2;
		}
		//Xay dung cot ben trai
		if (h1 <= h2) {
			for (int i = h2; i >= h1; i--) {
				A[cnt++] = a[i][c1];
			}
			++c1;
		}
	}
}
int main() {
	int** a;
	int n;
	Nhapmang(a, n);
	int* A = new int[n*n]; int cnt = 0;
	INMATRANXOAYOC(a, n, n, A);
	int x1, y1, x2, y2;
	cout << "Nhap vi tri diem thu nhat: ";
	cin >> x1 >> y1;
	cout << "Nhap vi tri diem thu hai: ";
	cin >> x2 >> y2;
	int pos1, pos2;
	for (int i = 0; i < n * n; i++) {
		if (A[i] == a[x1][y1]) {
			pos1 = i;
		}
		if (A[i] == a[x2][y2]) {
			pos2 = i;
		}
	}
	int count = 0;
	for (int j = pos1 + 1;j < pos2; j++) {
		if (checkPrime(A[j])) {
			count++;
		}
	}
	cout << "So lan xuat hien so nguyen to trong duong di tu A den B la: " << count << endl;
	delete[] A;
	for (int i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[] a;
	return 0;
}