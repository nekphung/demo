#include <iostream> 
using namespace std;
int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}
bool checkLeft(int a[100], int n) {
	for (int i = 1; i <= n; i++) {
		if (a[i] <= a[i - 1]) return false;
	}
	return true;
}
bool checkRight(int a[100], int x, int n) {
	for (int i = x + 1; i < n; i++) {
		if (a[i] >= a[i - 1]) return false;
	}
	return true;
}
bool CheckArray(int a[100], int n) {
	for (int i = 0; i < n; i++) {
		if (checkLeft(a, i) && checkRight(a, i, n)) {
			return true;
			break;
		}
	}
	return false;
}

bool Check(int *b, int n, int k) {
	int Max = b[0];
	int Min = b[0];
	for (int i = 1; i < n; i++) {
		Max = max(Max, b[i]);
		Min = min(Min, b[i]);
	}
	return (Max - Min) <= k;
}

int MaxSubArr(int a[100], int n) {
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int* b = new int[j - i + 1];
			int cnt = 0;
			for (int z = i; z <= j; z++) {
				b[cnt++] = a[z];
			}
			if (CheckArray(b, cnt) == true && Check(b, cnt, 2) == true) {
				res = max(res, j - i + 1);
			}
			delete[] b;
		}
	}
	return res;
}
int main() {
	int a[100];
	int n;
	cout << "Nhap n = "; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << endl;
	/*if (CheckArray(a, n)) {
		cout << "La mang dep" << endl;
	}*/
	 cout << "So luong max la: " << MaxSubArr(a, n);
	return 0;
}