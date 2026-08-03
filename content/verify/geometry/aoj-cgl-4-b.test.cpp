#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B"
#define ERROR 0.000001

#define main main2
#include "../../contest/template.cpp"
#undef main

#include "../../geometry/Point.cpp"
#include "../../geometry/Hull.cpp"
#include "../../geometry/Diameter.cpp"

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.precision(20), cout.setf(ios::fixed);

    int n;
    cin >> n;
    vector<vec> arr(n);
    for (auto &el : arr) {
        cin >> el.x >> el.y;
    }
    cout << diameter(arr) << '\n';
}
