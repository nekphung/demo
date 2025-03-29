#include <iostream>
using namespace std;
// Tim tong duong di be nhat
// Tim hieu duong cheo chinh va duong cheo phu cua ma tran con 
// Tim phan tu hoang hau cua ma tran vuong (neu no max dong,max cot, max cheo)
void Timtonglonnhat(int a[50][50], int d, int c) {
	for (int i = 1; i < d; i++) {
		for (int j = 0; j < c; j++) {
			if (j == 0) {
				a[i][j] += max(a[i - 1][j], a[i - 1][j + 1]);
			}
			else if (j == c - 1) {
				a[i][j] += max(a[i - 1][j], a[i - 1][j - 1]);
			}
			else {
				a[i][j] += max(a[i - 1][j], max(a[i - 1][j - 1], a[i - 1][j + 1]));
			}
		}
	}
	int res = INT_MIN;
	for (int i = 0; i < c; i++) {
		res = max(res, a[d - 1][i]);
	}
	cout << res << endl;
}
int main() {
	int d, c;
	int a[50][50]; 
	d = 4; c = 6;
	FILE* f;
	fopen_s(&f, "Matrix.txt", "rt");
	if (f == NULL) {
		cout << "Mo file khong thanh cong!" << endl;
		return 0;
	}
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < c; j++) {
			fscanf_s(f, "%d", &a[i][j]);
		}
	}
	cout << "Xuat mang: " << endl;
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < c; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
	Timtonglonnhat(a, d, c);
	fclose(f);
	return 0;
}