#include <iostream>
using namespace std;

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

bool Prime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void Xoacacsonguyento(int**& a, int dong, int& cot) {
	for (int i = 0; i < dong; i++) {
		for (int j = 0; j < cot; j++) {
			if (Prime(a[i][j])) {
				a[i][j] = -1;
			}
		}
	}
}

void Hoanvi(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void Hoanvi2dong(int**& a, int cot, int i, int k) {
	for (int j = 0; j < cot; j++) {
		Hoanvi(a[i][j], a[k][j]);
	}
}

void Hoanvitheosoluongphantu(int**& a, int dong, int cot) {
	for (int i = 0; i < dong - 1; i++) {
		for (int j = i + 1; j < dong; j++) {
			int n1 = 0; int n2 = 0;
			for (int z = 0; z < cot; z++) {
				if (a[i][z] != -1) {
					n1++;
				}
				if (a[j][z] != -1) {
					n2++;
				}
			}
			if (n1 > n2) {
				Hoanvi2dong(a, cot, i, j);
			}
		}
	}
	for (int i = 0; i < dong; i++) {
		for (int j = 0; j < cot; j++) {
			if (a[i][j] == -1) continue;
			else cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
void Xuatmang(int** a, int dong, int cot) {
	for (int i = 0; i < dong; i++) {
		for (int j = 0; j < cot; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
void Thuhoi(int**& a, int dong) {
	for (int i = 0; i < dong; i++) {
		delete[] a[i];
	}
	delete[] a;
}
int main() {
	int** a = nullptr;
	int dong, cot;
	Nhapmang(a, dong, cot);
	cout << "Mang duoc nhap tu ban phim: " << endl;
	Xuatmang(a, dong, cot);
	Xoacacsonguyento(a, dong, cot);
	cout << "Mang sau khi xoa: " << endl;
	Xuatmang(a, dong, cot);
	cout << "Mang sau khi sap xep: " << endl;
	Hoanvitheosoluongphantu(a, dong, cot);
	Thuhoi(a, dong);
	return 0;
}