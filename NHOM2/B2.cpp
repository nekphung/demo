// Xoa phan tu lap lai nhieu lan va tra lai mot lan
// 1 2 3 2 3 2 -> 1
#include <iostream> 
using namespace std;
void Delete_element(int*& a, int& n, int k) {
	for (int i = k; i < n - 1; i++) {
		a[i] = a[i + 1];
	}
	n--;
}
void DeleteArr(int*& a, int& n) {
	for (int i = 0; i < n; i++) {
		bool KT = false;
		for (int j = i + 1; j < n; j++) {
			if (a[i] == a[j]) {
				Delete_element(a, n, j);
				KT = true;
				j--;
			}
		}
		if (KT) {
			Delete_element(a, n, i);
			i--;
		}
	}
}
void Xuatmang(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
} 
int main() {
	int n;
	cout << "Nhap n = ";
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	DeleteArr(a, n);
	Xuatmang(a, n);
	delete[] a;
	return 0;
}