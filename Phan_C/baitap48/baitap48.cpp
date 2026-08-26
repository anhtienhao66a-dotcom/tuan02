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
    int id;
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
        for (int j = 0; j < d; j++) file >> D[i].x[j];
        file >> D[i].y;
        D[i].id = i + 1;
    }
    file.close();
    return D;
}

double kc_euclid(const vector<double>& u, const vector<double>& v) {
    double sum = 0.0;
    for (size_t i = 0; i < u.size(); i++) {
        double diff = u[i] - v[i];
        sum += diff * diff;
    }
    return sqrt(sum);
}

double kc_manhattan(const vector<double>& u, const vector<double>& v) {
    double sum = 0.0;
    for (size_t i = 0; i < u.size(); i++) {
        sum += abs(u[i] - v[i]);
    }
    return sum;
}

struct KetQua {
    string nhan;
    int chi_so;
    double khoang_cach;
};

KetQua lang_gieng_gan_nhat(const vector<double>& q, const vector<Mau>& D, 
                           double (*kc)(const vector<double>&, const vector<double>&), 
                           int bo_qua_id = -1) {
    double min_dist = 1e18;
    string best_label = "";
    int best_idx = -1;

    for (const auto& mau : D) {
        if (mau.id == bo_qua_id) continue;
        double dist = kc(q, mau.x);
        if (dist < min_dist) {
            min_dist = dist;
            best_label = mau.y;
            best_idx = mau.id;
        }
    }
    return {best_label, best_idx, min_dist};
}

int main() {
    int d;
    vector<Mau> D = doc_du_lieu("hoa30.txt", d);

    // 1. Kiem tra mau moi (6.5; 3.0; 5.5; 2.0)
    vector<double> q = {6.5, 3.0, 5.5, 2.0};
    KetQua res_e = lang_gieng_gan_nhat(q, D, kc_euclid);
    KetQua res_m = lang_gieng_gan_nhat(q, D, kc_manhattan);

    cout << "=== KET QUA PHAN LOAI MAU MOI ===\n";
    cout << "Euclid: " << res_e.nhan << " - lang gieng la mau " << res_e.chi_so << ", khoang cach " << fixed << setprecision(4) << res_e.khoang_cach << "\n";
    cout << "Manhattan: " << res_m.nhan << " - lang gieng la mau " << res_m.chi_so << ", khoang cach " << fixed << setprecision(1) << res_m.khoang_cach << "\n\n";

    // 2. Kiem thu bo mot mau (LOOCV)
    int dung_e = 0, dung_m = 0;
    string thong_tin_sai_m = "";

    for (const auto& mau : D) {
        KetQua pe = lang_gieng_gan_nhat(mau.x, D, kc_euclid, mau.id);
        KetQua pm = lang_gieng_gan_nhat(mau.x, D, kc_manhattan, mau.id);

        if (pe.nhan == mau.y) dung_e++;
        if (pm.nhan == mau.y) dung_m++;
        else {
            thong_tin_sai_m = "Manhattan du doan sai thanh " + pm.nhan + " (lang gieng mau " + to_string(pm.chi_so) + ", khoang cach " + to_string(pm.khoang_cach).substr(0, 3) + ")";
        }
    }

    cout << "=== KIEM THU BO MOT MAU (LOOCV) ===\n";
    cout << "Euclid " << dung_e << "/30 = " << fixed << setprecision(2) << (dung_e * 100.0 / D.size()) << "% - Manhattan " << dung_m << "/30 = " << (dung_m * 100.0 / D.size()) << "%\n";
    cout << "Mau 26 khi bi bo ra: " << thong_tin_sai_m << "\n";

    return 0;
}