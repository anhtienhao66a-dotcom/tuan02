#include <iostream>
#include <climits>

using namespace std;

// tra ve false neu tran
bool giai_thua(int n, long long &kq) {
    kq = 1;
    for (int i = 1; i <= n; i++) {
        if (kq > LLONG_MAX / i) {
            return false;
        }
        kq *= i;
    }
    return true;
}

int main() {
    int n;
    while (cin >> n) {
        long long kq;
        if (giai_thua(n, kq)) {
            cout << kq << endl;
        } else {
            cout << "TRAN SO (21! = 51 090 942 171 709 440 000 > 9 223 372 036 854 775 807)" << endl;
        }
    }
    return 0;
}