#include <iostream>
#include <string.h>
using namespace std;
struct Sinhvien1 {
	char ten[50];
	char mssv[10];
	double DTB;
};
struct Sinhvien2 {
	char* ten;
	char* mssv;
	double DTB;
};
void Capphatdongvacopy(Sinhvien1 sv1, Sinhvien2& sv2) {
	sv2.DTB = sv1.DTB;
	int len1 = strlen(sv1.mssv);
	int len2 = strlen(sv1.ten);
	sv2.mssv = new char[len1 + 1];
	sv2.ten = new char[len2 + 1];
	strcpy(sv2.mssv, sv1.mssv);
	strcpy(sv2.ten, sv1.ten);
}
void Thuhoi(Sinhvien2& sv2) {
	delete[] sv2.mssv;
	delete[] sv2.ten;
}
int main() {
	Sinhvien1 sv1;
	Sinhvien2 sv2;
	cin >> sv1.mssv;
	cin >> sv1.ten;
	cin >> sv1.DTB;
	Capphatdongvacopy(sv1, sv2);
	cout << sv2.mssv << endl;
	cout << sv2.ten << endl;
	cout << sv2.DTB << endl;
	Thuhoi(sv2);
	return 0;
}