#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B"
#define ERROR 0.000000001

#define main main2
#include "../../contest/template.cpp"
#undef main

#include "../../geometry/Point.cpp"

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.precision(20), cout.setf(ios::fixed);

    vec a, b;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    vec v = norm(ort(b - a));
    int q;
    cin >> q;
    while (q--) {
        vec u;
        cin >> u.x >> u.y;
        u = u - v * (v * u - a * v) * 2;
        cout << u.x << " " << u.y << '\n';
    }
}
