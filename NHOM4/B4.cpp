#include <iostream>
 using namespace std;

void func(int* a, int* b) {
 * a = (*a) * 2;
 * b *= *b;

}

int main() {
 int a = 2, b[] = { 1, 2 };
 func(b+1, b+1);
 cout << a << " " << *(b+1) << "\n";
 return 0;
}