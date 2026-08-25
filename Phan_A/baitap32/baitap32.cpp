#include <iostream>

using namespace std;

bool isSquare(unsigned long long n) {
    if (n == 0 || n == 1) return true;

    unsigned long long left = 1;
    unsigned long long right = 1000000000ULL;
    if (n < right) right = n;

    while (left <= right) {
        unsigned long long mid = left + (right - left) / 2;
        unsigned long long sq = mid * mid;

        if (sq == n) {
            return true;
        } else if (sq < n) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    unsigned long long n;
    while (cin >> n) {
        if (isSquare(n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}