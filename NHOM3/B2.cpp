//Input: 1 2 3 4 5 7 9 
//Output: 1 5 4 12 9
#include <iostream>
using namespace std;
bool isPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}
void Duyetmang(int*& a, int &n) {
	int cnt = 0;
	int idx = 0;
	for (int i = 0; i < n; i++) {
		if (!isPrime(a[i])) {
			a[idx] = a[i];
			idx++;
		}
		else {
			int dem = 0;
			if (i == 0 || !isPrime(a[i - 1])) {
				a[idx] = a[i];
			}
			else {
				a[idx] += a[i];
				dem++;
			}
			if (dem >= 1) {
				cnt++;
			}
			if (i == n - 1 || !isPrime(a[i + 1])) {
				idx++;
			}
		}
	}
	n = idx;
	cout << "So day con la: " << cnt << endl;
}

int main() {
	int n = 7;
	int* a = new int[n]; 
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
    Duyetmang(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
	delete[] a;
}