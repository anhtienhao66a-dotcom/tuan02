#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

long long cach1(const vector<int>& a) {
    int n = a.size();
    long long max_sum = a[0];
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            long long cur = 0;
            for (int k = i; k <= j; k++) cur += a[k];
            max_sum = max(max_sum, cur);
        }
    }
    return max_sum;
}

long long cach2(const vector<int>& a) {
    int n = a.size();
    long long max_sum = a[0];
    for (int i = 0; i < n; i++) {
        long long cur = 0;
        for (int j = i; j < n; j++) {
            cur += a[j];
            max_sum = max(max_sum, cur);
        }
    }
    return max_sum;
}

long long kadane(const vector<int>& a) {
    long long max_so_far = a[0], curr_max = a[0];
    for (size_t i = 1; i < a.size(); i++) {
        curr_max = max((long long)a[i], curr_max + a[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        // Đo Cách 1
        auto st1 = high_resolution_clock::now();
        long long r1 = cach1(a);
        auto en1 = high_resolution_clock::now();
        double d1 = duration<double>(en1 - st1).count();

        // Đo Cách 2
        auto st2 = high_resolution_clock::now();
        long long r2 = cach2(a);
        auto en2 = high_resolution_clock::now();
        double d2 = duration<double>(en2 - st2).count();

        // Đo Cách 3 (lặp 10000 lần lấy trung bình)
        int reps = 10000;
        auto st3 = high_resolution_clock::now();
        long long r3 = 0;
        for (int i = 0; i < reps; i++) r3 = kadane(a);
        auto en3 = high_resolution_clock::now();
        double d3 = duration<double>(en3 - st3).count() / reps;

        cout << "Ket qua: " << r3 << "\n";
        cout << fixed << setprecision(8);
        cout << "1 - O(n^3):  " << d1 << "s\n";
        cout << "2 - O(n^2):  " << d2 << "s\n";
        cout << "3 - Kadane:  " << d3 << "s\n";
    }
    return 0;
}