#include <iostream>
#include <climits>
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

void Thaybangmangcontang(int**& a, int dong, int cot) {
    for (int i = 0; i < dong; i++) {
        int count_max = INT_MIN;
        int idx1 = 0, idx2 = 0; // Initialize properly
        for (int j = 0; j < cot - 1; j++) {
            for (int z = j + 1; z < cot; z++) {
                int count = 0;
                // Compare within the subarray from j to z
                for (int k = j; k < z; k++) {
                    if (a[i][k] < a[i][k + 1]) {
                        count++;
                    }
                }
                // Update count_max and indices if a larger subarray is found
                if (count > count_max) {
                    count_max = count;
                    idx1 = j;
                    idx2 = z;
                }
            }
        }
        // Create and replace the subarray
        int* temp = new int[idx2 - idx1 + 1];
        int cnt = 0;
        for (int j = idx1; j <= idx2; j++) {
            temp[cnt++] = a[i][j];
        }
           // Deallocate old memory
        for (int i = 0; i < cnt; i++) {
            cout << temp[i] << " ";
        }
        cout << endl;
        delete[] temp;
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

int main() {
    int dong, cot;
    int** a = nullptr;
    Nhapmang(a, dong, cot);
    cout << "Ma tran nhap tu ban phim la: " << endl;
    Xuatmang(a, dong, cot);

    cout << "Ma tran sau khi thay: " << endl;
    Thaybangmangcontang(a, dong, cot);

    // Clean up memory
    for (int i = 0; i < dong; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
