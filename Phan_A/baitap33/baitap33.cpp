#include <iostream>
#include <utility>

using namespace std;

pair<int, int> phan_tich(long long n) {
    int so_chu_so = 0;
    int tong_chu_so = 0;
    while (n > 0) {
        tong_chu_so += n % 10;
        so_chu_so++;
        n /= 10;
    }
    return {so_chu_so, tong_chu_so};
}

int main() {
    long long n;
    while (cin >> n) {
        pair<int, int> ans = phan_tich(n);
        cout << ans.first << " " << ans.second << endl;
    }
    return 0;
}