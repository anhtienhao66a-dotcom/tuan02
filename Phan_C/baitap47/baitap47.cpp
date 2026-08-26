#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

struct Mau {
    vector<double> x;
    string y;
};

vector<Mau> doc_du_lieu(const string& ten_tep, int& d) {
    ifstream file(ten_tep);
    if (!file.is_open()) {
        cerr << "Khong the mo tep: " << ten_tep << "\n";
        exit(1);
    }
    int n;
    file >> n >> d;
    vector<Mau> D(n);
    for (int i = 0; i < n; i++) {
        D[i].x.resize(d);
        for (int j = 0; j < d; j++) {
            file >> D[i].x[j];
        }
        file >> D[i].y;
    }
    file.close();
    return D;
}

double khoang_cach(const vector<double>& u, const vector<double>& v) {
    double sum = 0.0;
    for (size_t i = 0; i < u.size(); i++) {
        double diff = u[i] - v[i];
        sum += diff * diff;
    }
    return sqrt(sum);
}

struct KetQua {
    string nhan;
    int chi_so;
    double khoang_cach;
};

KetQua lang_gieng_gan_nhat(const vector<double>& q, const vector<Mau>& D) {
    double min_dist = 1e18;
    string best_label = "";
    int best_idx = -1;

    for (int i = 0; i < (int)D.size(); i++) {
        double dist = khoang_cach(q, D[i].x);
        if (dist < min_dist) {
            min_dist = dist;
            best_label = D[i].y;
            best_idx = i + 1;
        }
    }
    return {best_label, best_idx, min_dist};
}

int main() {
    int d;
    vector<Mau> D = doc_du_lieu("hoa30.txt", d);

    vector<double> q(d);
    while (cin >> q[0]) {
        for (int j = 1; j < d; j++) {
            cin >> q[j];
        }
        KetQua res = lang_gieng_gan_nhat(q, D);
        cout << fixed << setprecision(4);
        cout << res.nhan << " - mau " << res.chi_so << ", khoang cach " << res.khoang_cach << "\n";
    }
    return 0;
}