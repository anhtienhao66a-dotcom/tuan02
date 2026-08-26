#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

// 1. Thuật toán sắp xếp chọn Selection Sort O(n^2)
void selection_sort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) min_idx = j;
        }
        swap(a[i], a[min_idx]);
    }
}

// 2. Đo thời gian: Chạy lặp 3 lần và lấy giá trị nhỏ nhất
double do_thoi_gian(int n, int lap = 3) {
    mt19937 rng(42);
    uniform_int_distribution<int> dist(-10000, 10000);
    double min_t = 1e9;

    for (int r = 0; r < lap; r++) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) a[i] = dist(rng);

        auto t0 = steady_clock::now();
        selection_sort(a);
        auto t1 = steady_clock::now();

        double sec = duration<double>(t1 - t0).count();
        min_t = min(min_t, sec);
    }
    return min_t;
}

// 3. Tự động sinh và lưu đồ thị đơn O(n^2)
void ve_do_thi_don(const vector<int>& sizes, const vector<double>& times) {
    ofstream py_script("plot_cpp_single.py");
    py_script << "import matplotlib.pyplot as plt\n"
              << "import numpy as np\n"
              << "sizes = np.array([" << sizes[0] << ", " << sizes[1] << ", " << sizes[2] << ", " << sizes[3] << "])\n"
              << "times = np.array([" << times[0] << ", " << times[1] << ", " << times[2] << ", " << times[3] << "])\n"
              << "plt.figure(figsize=(7.5, 5))\n"
              << "plt.plot(sizes, times, '^-', color='tab:red', linewidth=2.5, markersize=8, label='Thực nghiệm C++ (Selection Sort)')\n"
              << "for x, y in zip(sizes, times):\n"
              << "    plt.annotate(f'{y:.6f}s', (x, y), textcoords='offset points', xytext=(0, 10), ha='center', fontsize=9, fontweight='bold')\n"
              << "plt.title(r'Đồ thị thời gian chạy của thuật toán $O(n^2)$ khi $n$ tăng gấp đôi (C++)', fontsize=12, fontweight='bold')\n"
              << "plt.xlabel('Kích thước mảng (n)', fontsize=11)\n"
              << "plt.ylabel('Thời gian thực thi (giây)', fontsize=11)\n"
              << "plt.xticks(sizes)\n"
              << "plt.grid(True, linestyle='--', alpha=0.6)\n"
              << "plt.legend(fontsize=10)\n"
              << "plt.tight_layout()\n"
              << "plt.savefig('dothi_bai44_cpp.png', dpi=300)\n"
              << "plt.show()\n";
    py_script.close();

    system("python plot_cpp_single.py");
    cout << "-> Da luu do thi don vao file 'dothi_bai44_cpp.png' thanh cong.\n";
}

int main() {
    vector<int> sizes = {500, 1000, 2000, 4000};
    vector<double> times;

    for (int n : sizes) {
        times.push_back(do_thoi_gian(n, 3));
    }

    cout << fixed << setprecision(6);
    cout << "========== KET QUA KIEM CHUNG TI LE C++ ==========\n";
    cout << "n = 500  -> 1000: ti le = " << setprecision(2) << times[1] / times[0] << "\n";
    cout << "n = 1000 -> 2000: ti le = " << setprecision(2) << times[2] / times[1] << "\n";
    cout << "n = 2000 -> 4000: ti le = " << setprecision(2) << times[3] / times[2] << "\n";

    cout << "\n========== BANG DO THOI GIAN C++ (GIAY) ==========\n";
    for (int i = 0; i < 4; i++) {
        cout << "n=" << sizes[i] << ": " << setprecision(6) << times[i] << "s | ";
    }
    cout << "Ti le cuoi: " << setprecision(2) << times[3] / times[2] << "\n\n";

    ve_do_thi_don(sizes, times);
    return 0;
}