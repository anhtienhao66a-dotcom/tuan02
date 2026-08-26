#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

struct Mau {
    vector<double> x;
    string y;
};

// 9 mau hoa dien vi rut gon (Vi du 1.8)
const vector<Mau> D = {
    {{1.4, 0.2}, "Setosa"},     // Mau 1
    {{1.3, 0.2}, "Setosa"},     // Mau 2
    {{1.5, 0.2}, "Setosa"},     // Mau 3
    {{4.7, 1.4}, "Versicolor"}, // Mau 4
    {{4.5, 1.5}, "Versicolor"}, // Mau 5
    {{4.9, 1.5}, "Versicolor"}, // Mau 6
    {{6.0, 2.5}, "Virginica"},  // Mau 7
    {{5.8, 1.9}, "Virginica"},  // Mau 8
    {{6.3, 2.5}, "Virginica"}   // Mau 9
};

struct KetQua {
    string nhan;
    double khoang_cach;
    int chi_so;
};

KetQua lang_gieng_gan_nhat(const vector<double>& q, const vector<Mau>& tap_mau) {
    double min_dist = 1e18;
    string best_label = "";
    int best_idx = -1;

    for (int i = 0; i < (int)tap_mau.size(); i++) {
        double d2 = 0.0;
        for (int j = 0; j < (int)q.size(); j++) {
            double diff = q[j] - tap_mau[i].x[j];
            d2 += diff * diff;
        }
        double dist = sqrt(d2);
        if (dist < min_dist) {
            min_dist = dist;
            best_label = tap_mau[i].y;
            best_idx = i + 1;
        }
    }
    return {best_label, min_dist, best_idx};
}

int main() {
    double x1, x2;
    while (cin >> x1 >> x2) {
        vector<double> q = {x1, x2};
        KetQua res = lang_gieng_gan_nhat(q, D);
        cout << fixed << setprecision(4);
        if (res.khoang_cach == 0.0) {
            cout << res.nhan << " - trung dung mau " << res.chi_so << ", khoang cach 0\n";
        } else {
            cout << res.nhan << " - lang gieng la mau " << res.chi_so << ", khoang cach " << setprecision(4) << res.khoang_cach << "\n";
        }
    }
    return 0;
}