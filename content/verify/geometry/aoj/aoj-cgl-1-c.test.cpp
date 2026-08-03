#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C"

#define main main2
#include "../../../contest/template.cpp"
#undef main

#include "../../../geometry/Point.cpp"

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.precision(20), cout.setf(ios::fixed);

    vec a, b;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    int q;
    cin >> q;
    while (q--) {
        vec c;
        cin >> c.x >> c.y;
        if (sign((b - a) % (c - a)) > 0) {
            cout << "COUNTER_CLOCKWISE\n";
        } else if (sign((b - a) % (c - a)) < 0) {
            cout << "CLOCKWISE\n";
        } else if (sign((c - a) * (b - a) - len2(b - a)) > 0) {
            cout << "ONLINE_FRONT\n";
        } else if (sign((c - a) * (b - a)) < 0) {
            cout << "ONLINE_BACK\n";
        } else {
            cout << "ON_SEGMENT\n";
        }
    }
}
