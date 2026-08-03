#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A"

#define main main2
#include "../../../contest/template.cpp"
#undef main

#include "../../../geometry/Point.cpp"

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.precision(20), cout.setf(ios::fixed);

    int q;
    cin >> q;
    while (q--) {
        vec a, b, c, d;
        cin >> a.x >> a.y;
        cin >> b.x >> b.y;
        cin >> c.x >> c.y;
        cin >> d.x >> d.y;
        if (sign((d - c) % (b - a)) == 0) {
            cout << "2\n";
        } else if (sign((b - a) * (d - c)) == 0) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }
}
