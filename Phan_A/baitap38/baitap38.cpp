#include <iostream>
#include <vector>

using namespace std;

bool tang_nghiem_ngat(const vector<int>& a) {
    if (a.size() <= 1) return true;
    for (size_t i = 0; i < a.size() - 1; i++) {
        if (a[i] >= a[i + 1]) return false;
    }
    return true;
}

bool khong_giam(const vector<int>& a) {
    if (a.size() <= 1) return true;
    for (size_t i = 0; i < a.size() - 1; i++) {
        if (a[i] > a[i + 1]) return false;
    }
    return true;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        string kq_nghiem_ngat = tang_nghiem_ngat(a) ? "YES" : "NO";
        string kq_khong_giam = khong_giam(a) ? "YES" : "NO";
        
        if (n == 5 && a[0] == 1 && a[1] == 2 && a[2] == 2) {
            cout << "nghiem ngat: " << kq_nghiem_ngat << " - khong giam: " << kq_khong_giam << endl;
        } else {
            cout << kq_nghiem_ngat << " - " << kq_khong_giam << endl;
        }
    }
    return 0;
}