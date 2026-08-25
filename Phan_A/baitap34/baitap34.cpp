#include <iostream>
#include <cmath>

using namespace std;

long long dao_nguoc(long long n) {
    int dau = (n < 0) ? -1 : 1;
    unsigned long long temp = (n < 0) ? -n : n;
    long long rev = 0;
    while (temp > 0) {
        rev = rev * 10 + (temp % 10);
        temp /= 10;
    }
    return rev * dau;
}

int main() {
    long long n;
    while (cin >> n) {
        cout << dao_nguoc(n) << endl;
    }
    return 0;
}