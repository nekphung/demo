// Duyet tat ca cac day con de day con tang voi so luong phan tu nhieu nhat
bool IsPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}
bool CheckDaytang(int* a, int n) {
	for (int i = 0; i < n-1; i++) {
		if (a[i] > a[i + 1]) return false;
	}
	return true;
}

void Thaymangthanhcacphantutangdainhat(int**& A, int n, int& m) {
	for (int i = 0; i < n; i++) {
		int count = INT_MIN;
		for (int j = 0; j < m; j++) {
			int* B = new int[j - i + 1];
			int cnt = 0;
			for (int z = i; z <= j; z++) {
				B[cnt++] = A[i][j];
			}
			if (CheckDaytang(B, cnt) && cnt > count) {
				count = cnt;

			}

		}
	}
}