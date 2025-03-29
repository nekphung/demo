#include <iostream>
using namespace std;
int GT(int n) {
	int GT = 1;
	for (int i = 1; i <= n; i++) {
		GT *= i;
	}
	return GT;
}
int THchapkcuaN(int n, int k) {
	int TH;
	TH = (GT(n)) / (GT(k) * GT(n - k));
	return TH;
}
void inratamgiacPasscal(int n) {
	for (int i = 0; i <= n; i++) {
		cout << "n = " << i << ": ";
		for (int j = 0; j <= i; j++) {
			cout << THchapkcuaN(i, j) << " ";
		}
		cout << endl;
	}
}
int main() {
	int n;
	cout << "Nhap n = ";
	cin >> n;
	inratamgiacPasscal(n);
	return 0;
}