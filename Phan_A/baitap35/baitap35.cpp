#include <iostream>
#include <vector>

using namespace std;

bool la_nguyen_to(int n) {
    if (n < 2) return false;
    for (int i = 2; 1LL * i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

vector<int> sang_eratosthenes(int n) {
    vector<bool> check(n + 1, true);
    check[0] = check[1] = false;
    for (int p = 2; 1LL * p * p <= n; p++) {
        if (check[p]) {
            for (int i = p * p; i <= n; i += p) {
                check[i] = false;
            }
        }
    }
    vector<int> primes;
    for (int p = 2; p <= n; p++) {
        if (check[p]) primes.push_back(p);
    }
    return primes;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> primes = sang_eratosthenes(n);
        if (n <= 30) {
            for (size_t i = 0; i < primes.size(); i++) {
                cout << primes[i] << (i + 1 == primes.size() ? "" : " ");
            }
            cout << " (" << primes.size() << " so)" << endl;
        } else if (n == 1000000) {
            long long tong = 0;
            for (int p : primes) tong += p;
            cout << "so luong = " << primes.size() << ", tong = " << tong << endl;
        } else {
            cout << "so luong = " << primes.size() << endl;
        }
    }
    return 0;
}