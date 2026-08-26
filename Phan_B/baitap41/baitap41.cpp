#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>

using namespace std;

// Bản O(n) chính thức
long long tich_lon_nhat(const vector<int>& a) {
    int n = a.size();
    long long ans = a[0];
    long long max_p = a[0];
    long long min_p = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] < 0) {
            swap(max_p, min_p);
        }
        max_p = max((long long)a[i], max_p * a[i]);
        min_p = min((long long)a[i], min_p * a[i]);
        ans = max(ans, max_p);
    }
    return ans;
}

// Bản O(n^2) để đối chiếu trong kiểm thử
long long tich_lon_nhat_n2(const vector<int>& a) {
    int n = a.size();
    long long ans = a[0];
    for (int i = 0; i < n; i++) {
        long long cur = 1;
        for (int j = i; j < n; j++) {
            cur *= a[j];
            ans = max(ans, cur);
        }
    }
    return ans;
}

// Kiểm thử tự động đối chiếu O(n) và O(n^2)
void kiem_thu_tu_dong(int so_lan = 1000) {
    mt19937 rng(42);
    uniform_int_distribution<int> dist_n(1, 15);
    uniform_int_distribution<int> dist_val(-5, 5);

    for (int t = 0; t < so_lan; t++) {
        int n = dist_n(rng);
        vector<int> a(n);
        for (int i = 0; i < n; i++) a[i] = dist_val(rng);
        if (tich_lon_nhat(a) != tich_lon_nhat_n2(a)) {
            cout << "FAILED tai mang: ";
            for (int x : a) cout << x << " ";
            cout << "\n";
            return;
        }
    }
    cout << "OK (1000 tests matched)\n";
}

int main(int argc, char* argv[]) {
    if (argc > 1 && string(argv[1]) == "--test") {
        kiem_thu_tu_dong();
        return 0;
    }

    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << tich_lon_nhat(a) << "\n";
    }
    return 0;
}