#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <iomanip>

using namespace std;

// Tinh binh phuong khoang cach Euclid de toi uu thoi gian chay
double kc_euclid_sq(const vector<double>& u, const vector<double>& v) {
    double sum = 0.0;
    for (size_t i = 0; i < u.size(); i++) {
        double diff = u[i] - v[i];
        sum += diff * diff;
    }
    return sum;
}

int lang_gieng_gan_nhat(const vector<double>& q, const vector<vector<double>>& D) {
    double min_d2 = 1e18;
    int best_idx = -1;
    for (size_t i = 0; i < D.size(); i++) {
        double d2 = kc_euclid_sq(q, D[i]);
        if (d2 < min_d2) {
            min_d2 = d2;
            best_idx = (int)i;
        }
    }
    return best_idx;
}

vector<vector<double>> sinh_du_lieu(int n, int d, mt19937& rng) {
    uniform_real_distribution<double> dist(0.0, 1.0);
    vector<vector<double>> data(n, vector<double>(d));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) data[i][j] = dist(rng);
    }
    return data;
}

int main() {
    mt19937 rng(12345);
    int d = 20, q_size = 1000;
    auto Q = sinh_du_lieu(q_size, d, rng);
    vector<int> N_list = {1000, 10000, 100000};
    vector<double> T;

    cout << "=== DO THOI GIAN C++ (-O2) ===\n";
    volatile long long dummy = 0; // Tranh trinh bien dich -O2 toi uu xoa vong lap

    for (int n : N_list) {
        auto D = sinh_du_lieu(n, d, rng);
        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < q_size; i++) {
            dummy += lang_gieng_gan_nhat(Q[i], D);
        }
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> diff = end - start;
        T.push_back(diff.count());
        cout << "n = " << n << ": " << fixed << setprecision(4) << diff.count() << " s\n";
    }
    cout << "Ti le T(10^4)/T(10^3) = " << fixed << setprecision(2) << T[1] / T[0] << "\n";
    cout << "Ti le T(10^5)/T(10^4) = " << fixed << setprecision(2) << T[2] / T[1] << "\n";
    return 0;
}