#include <iostream>
#include <string.h>
using namespace std;
struct Sinhvien {
	char mssv[9];
	char ten[50];
	float DTB;
};
void Docdulieutufile(Sinhvien ds[100], int& n) {
	FILE* f;
	fopen_s(&f, "input.csv", "rt");
	if (f == nullptr) {
		cout << "Mo file khong thanh cong!" << endl;
		return;
	}
	char line[255];
	while (fgets(line, 255, f) != nullptr) {
		Sinhvien sv;
		char DTB[5];
		strcpy(sv.mssv, strtok(line, ","));
		strcpy(sv.ten, strtok(nullptr, ","));
		strcpy(DTB, strtok(nullptr, ","));
		sv.DTB = atof(DTB);
		ds[n++] = sv;
	}
	fclose(f);
}
void Xuat1sinhvien(Sinhvien sv) {
	cout << " ------------------------------ " << endl;
	cout << "MSSV : " << sv.mssv << endl;
	cout << "Ten  : " << sv.ten << endl;
	cout << "DTB  : " << sv.DTB << endl;
	cout << " ------------------------------ " << endl;
}

void Xuatdanhsachsinhvien(Sinhvien ds[100], int n) {
	for (int i = 0; i < n; i++)
		Xuat1sinhvien(ds[i]);
}
Sinhvien Diemcaonhat(Sinhvien ds[100], int n) {
	float Diemcaonhat = ds[0].DTB; 
	int idx = 0;
	for (int i = 0; i < n; i++) {
		if (ds[i].DTB > Diemcaonhat) {
			Diemcaonhat = ds[i].DTB;
			idx = i;
		}
	}
	return ds[idx];
}

void copySinhvien(Sinhvien &sv1, Sinhvien &sv2) {
	strcpy(sv1.mssv, sv2.mssv);
	strcpy(sv1.ten, sv2.ten);
	sv1.DTB = sv2.DTB;
}

void Hoanvi2sinhvien(Sinhvien& sv1, Sinhvien& sv2) {
	Sinhvien temp;
	copySinhvien(temp, sv1);
	copySinhvien(sv1, sv2);
	copySinhvien(sv2, temp);
}

void Sapxepsinhvientheothututudien(Sinhvien ds[100], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (strcmp(ds[i].ten, ds[j].ten) > 0) {
				Hoanvi2sinhvien(ds[i], ds[j]);
			}
		}
	}
}

void Ghivaofile(Sinhvien ds[100], int n) {
	FILE* f;
	fopen_s(&f, "output.csv", "at");
	if (f == nullptr) {
		cout << "Mo file khong thanh cong!" << endl;
		return;
	}
	for (int i = 0; i < n; i++) {
		fprintf(f, "%s,%s,%lf\n", ds[i].mssv, ds[i].ten, ds[i].DTB);
	}
	fclose(f);
}
int main() {
	Sinhvien ds[100];
	int n = 0;
	Docdulieutufile(ds, n);
	cout << "Danh sach sinh vien doc tu file la: " << endl;
	Xuatdanhsachsinhvien(ds, n);
	Sinhvien sv = Diemcaonhat(ds, n);
	cout << "Sinh vien co diem cao nhat la: " << endl;
	Xuat1sinhvien(sv);
	Sapxepsinhvientheothututudien(ds, n);
	Ghivaofile(ds, n);
	cout << "Danh sach sinh vien da duoc sap xep: " << endl;
	Xuatdanhsachsinhvien(ds, n);
	return 0;
}