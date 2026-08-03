#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C"

#define main main2
#include "../../contest/template.cpp"
#undef main

#include "../../geometry/Point.cpp"
#include "../../geometry/Line.cpp"
#include "../../geometry/Intersections.cpp"
#include "../../geometry/IsInPolygon.cpp"

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.precision(20), cout.setf(ios::fixed);

    int n;
    cin >> n;
    vector<vec> arr(n);
    for (auto &el : arr) {
        cin >> el.x >> el.y;
    }
    int q;
    cin >> q;
    while (q--) {
        vec v;
        cin >> v.x >> v.y;
        cout << isIn(arr, v) << '\n';
    }
}
