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

// Doc du lieu tu tep van ban
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

// Danh gia do chinh xac bo mot mau
double do_chinh_xac_bo_mot_mau(const vector<Mau>& D, double (*kc)(const vector<double>&, const vector<double>&), vector<string>& danh_sach_sai) {
    int so_dung = 0;
    danh_sach_sai.clear();

    for (size_t i = 0; i < D.size(); i++) {
        double min_dist = 1e18;
        string best_label = "";

        // Bo qua mau i trong n - 1 mau con lai
        for (size_t j = 0; j < D.size(); j++) {
            if (i == j) continue;
            double dist = kc(D[i].x, D[j].x);
            if (dist < min_dist) {
                min_dist = dist;
                best_label = D[j].y;
            }
        }

        if (best_label == D[i].y) {
            so_dung++;
        } else {
            danh_sach_sai.push_back("sai mau " + to_string(D[i].id) + " (that: " + D[i].y + ", du doan: " + best_label + ")");
        }
    }
    return (double)so_dung / D.size();
}

int main() {
    int d;
    vector<Mau> D30 = doc_du_lieu("hoa30.txt", d);

    // Tap 9 mau 2 dac trung Vi du 1.8
    vector<Mau> D9 = {
        {{1.4, 0.2}, "Setosa", 1},
        {{1.3, 0.2}, "Setosa", 2},
        {{1.5, 0.2}, "Setosa", 3},
        {{4.7, 1.4}, "Versicolor", 4},
        {{4.5, 1.5}, "Versicolor", 5},
        {{4.9, 1.5}, "Versicolor", 6},
        {{6.0, 2.5}, "Virginica", 7},
        {{5.8, 1.9}, "Virginica", 8},
        {{6.3, 2.5}, "Virginica", 9}
    };

    vector<string> ds_sai;
    cout << fixed << setprecision(2);

    // 1. Euclid tren hoa30
    double acc_e = do_chinh_xac_bo_mot_mau(D30, kc_euclid, ds_sai);
    cout << "Euclid: " << (int)(acc_e * D30.size()) << "/" << D30.size() << " = " << acc_e * 100.0 << "% - ";
    if (ds_sai.empty()) cout << "khong mau nao sai\n";
    else { for (auto& s : ds_sai) cout << s << "; "; cout << "\n"; }

    // 2. Manhattan tren hoa30
    double acc_m = do_chinh_xac_bo_mot_mau(D30, kc_manhattan, ds_sai);
    cout << "Manhattan: " << (int)(acc_m * D30.size()) << "/" << D30.size() << " = " << acc_m * 100.0 << "% - ";
    for (size_t i = 0; i < ds_sai.size(); i++) {
        cout << ds_sai[i] << (i + 1 < ds_sai.size() ? "; " : "\n");
    }

    // 3. Tap 9 mau Vi du 1.8
    double acc_9e = do_chinh_xac_bo_mot_mau(D9, kc_euclid, ds_sai);
    cout << "Tap 9 mau: " << (int)(acc_9e * D9.size()) << "/" << D9.size() << " = " << acc_9e * 100.0 << "% voi ca hai do do\n";

    return 0;
}