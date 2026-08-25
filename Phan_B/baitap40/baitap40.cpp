#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct KetQua {
    long long tong;
    int dau;
    int cuoi;
};

KetQua kadane_chi_so(const vector<int>& a) {
    long long max_so_far = a[0];
    long long curr_max = a[0];
    int start = 0, end = 0, temp_start = 0;

    for (int i = 1; i < (int)a.size(); i++) {
        if (a[i] > curr_max + a[i]) {
            curr_max = a[i];
            temp_start = i;
        } else {
            curr_max += a[i];
        }

        if (curr_max > max_so_far) {
            max_so_far = curr_max;
            start = temp_start;
            end = i;
        }
    }
    // Trả về chỉ số đánh số từ 1
    return {max_so_far, start + 1, end + 1};
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        KetQua kq = kadane_chi_so(a);
        cout << "tong " << kq.tong << ", doan [" << kq.dau << ".." << kq.cuoi << "]\n";
    }
    return 0;
}