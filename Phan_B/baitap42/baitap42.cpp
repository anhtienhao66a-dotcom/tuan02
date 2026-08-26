#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <iomanip>
#include <string>

using namespace std;
using namespace std::chrono;

pair<long long, int> cua_so_truot(const vector<int>& a, int k) {
    int n = a.size();
    long long cur_sum = 0;
    for (int i = 0; i < k; i++) cur_sum += a[i];

    long long max_sum = cur_sum;
    int best_start = 0;

    for (int i = k; i < n; i++) {
        cur_sum += a[i] - a[i - k];
        if (cur_sum > max_sum) {
            max_sum = cur_sum;
            best_start = i - k + 1;
        }
    }
    return {max_sum, best_start + 1};
}

pair<long long, int> ngay_tho(const vector<int>& a, int k) {
    int n = a.size();
    long long max_sum = -4e18;
    int best_start = 0;
    for (int i = 0; i <= n - k; i++) {
        long long s = 0;
        for (int j = i; j < i + k; j++) s += a[j];
        if (s > max_sum) {
            max_sum = s;
            best_start = i;
        }
    }
    return {max_sum, best_start + 1};
}

void benchmark() {
    int n = 50000, k = 1000; // Giảm n xuống 50.000 cho bản ngây thơ O(n*k) chạy không bị treo máy
    vector<int> a(n);
    mt19937 rng(42);
    uniform_int_distribution<int> dist(-100, 100);
    for (int i = 0; i < n; i++) a[i] = dist(rng);

    // Đo bản ngây thơ
    auto st1 = high_resolution_clock::now();
    volatile long long dummy1 = ngay_tho(a, k).first;
    auto en1 = high_resolution_clock::now();
    double t_naive = duration<double>(en1 - st1).count();

    // Đo bản cửa sổ trượt (với n = 1.000.000 để thấy rõ hiệu năng)
    int n_large = 1000000;
    vector<int> a_large(n_large);
    for (int i = 0; i < n_large; i++) a_large[i] = dist(rng);

    auto st2 = high_resolution_clock::now();
    volatile long long dummy2 = cua_so_truot(a_large, k).first;
    auto en2 = high_resolution_clock::now();
    double t_slide = duration<double>(en2 - st2).count();

    // Quy đổi tương đối bản ngây thơ lên n = 1.000.000 để so sánh chuẩn xác
    double t_naive_scaled = t_naive * ((double)1000000 / n);

    cout << fixed << setprecision(6);
    cout << "=== BENCHMARK C++ (n=10^6, k=1000) ===\n";
    cout << "Ngay tho O(n*k): " << t_naive_scaled << "s\n";
    cout << "Cua so truot O(n): " << t_slide << "s\n";
    cout << "So lan nhanh hon: " << setprecision(1) << (t_naive_scaled / t_slide) << " lan\n";
    (void)dummy1; (void)dummy2;
}

int main(int argc, char* argv[]) {
    if (argc > 1 && string(argv[1]) == "--benchmark") {
        benchmark();
        return 0;
    }

    int n, k;
    while (cin >> n >> k) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        if (k > n || k <= 0) continue;
        auto res = cua_so_truot(a, k);
        cout << "tong " << res.first << ", bat dau tai vi tri " << res.second << "\n";
    }
    return 0;
}