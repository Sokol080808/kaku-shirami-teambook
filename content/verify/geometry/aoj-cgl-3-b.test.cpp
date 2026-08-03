#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B"
#define ERROR 0.00000001


#define main main2
#include "../../contest/template.cpp"
#undef main

#include "../../geometry/Point.cpp"

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.precision(20), cout.setf(ios::fixed);

    int n;
    cin >> n;
    vector<vec> arr(n);
    for (auto &el : arr) {
        cin >> el.x >> el.y;
    }
    for (int i = 0; i < n; ++i) {
        if (sign((arr[(i + 2) % n] - arr[i]) % (arr[(i + 1) % n] - arr[i])) > 0) {
            cout << "0\n";
            return 0;
        }
    }
    cout << "1\n";
}
