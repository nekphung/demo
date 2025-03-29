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
void Xuatmang(int** a, int d, int c) {
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < c; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
} 
int findMaxSumSubMatrix(int** a, int d, int c) {
	int Max_sum = INT_MIN;
	for (int r1 = 0; r1 < d; r1++) {
		for (int r2 = r1; r2 < d; r2++) {
			for (int c1 = 0; c1 < c; c1++) {
				for (int c2 = c1; c2 < c; c2++) {
					int sum = 0;
					for (int i = r1; i <= r2; i++) {
						for (int j = c1; j <= c2; j++) {
							sum += a[i][j];
						}
					}
					Max_sum = max(Max_sum, sum);
				}
			}
		}
	}
	return Max_sum;
}
void Thuhoi(int**& a, int d, int c) {
	for (int i = 0; i < d; i++) {
		delete[] a[i];
	}
	delete[] a;
}
int main() {
	int** a;
	int d, c;
	Nhapmang(a, d, c);
	Xuatmang(a, d, c);
	cout << "Tong lon nhat cua tat ca cac mang con la: ";
	cout << findMaxSumSubMatrix(a, d, c);
	Thuhoi(a, d, c);
	return 0;
}