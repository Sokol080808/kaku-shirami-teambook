#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A"
#define ERROR 0.00000001


#define main main2
#include "../../../contest/template.cpp"
#undef main

#include "../../../geometry/Point.cpp"

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.precision(20), cout.setf(ios::fixed);

    int n;
    cin >> n;
    vector<vec> arr(n);
    for (auto &el : arr) {
        cin >> el.x >> el.y;
    }
    ld res = 0;
    for (int i = 0; i < n; ++i) {
        auto a = arr[i];
        auto b = arr[i + 1 < n ? i + 1 : 0];
        res += a % b;
        // res += arr[i] % arr[(i + 1) ? (i + 1 < n) : 0];
    }
    res /= 2;
    res = abs(res);
    cout << setprecision(1) << res << '\n';
    cout << endl;
}
