#include <iostream>
#include <vector>

using namespace std;

long long dem = 0;

long long fib_de_quy(int n) {
    dem++; // Tang dem o dau ham
    if (n <= 2) return 1;
    return fib_de_quy(n - 1) + fib_de_quy(n - 2);
}

long long fib_ghi_nho_helper(int n, vector<long long>& memo) {
    if (n <= 2) return 1;
    if (memo[n] != 0) return memo[n];
    memo[n] = fib_ghi_nho_helper(n - 1, memo) + fib_ghi_nho_helper(n - 2, memo);
    return memo[n];
}

long long fib_ghi_nho(int n) {
    if (n <= 2) return 1;
    vector<long long> memo(n + 1, 0);
    return fib_ghi_nho_helper(n, memo);
}

long long fib_lap(int n) {
    if (n <= 2) return 1;
    long long a = 1, b = 1;
    for (int i = 3; i <= n; i++) {
        long long c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    while (cin >> n) {
        if (n >= 93) {
            cout << "tran long long - phai phat hien va bao\n";
            continue;
        }

        if (n <= 35) {
            dem = 0;
            long long ans = fib_de_quy(n);
            cout << "F = " << ans << ", so loi goi = " << dem << "\n";
        } else {
            long long ans = fib_lap(n);
            cout << "F = " << ans << "\n";
        }
    }
    return 0;
}