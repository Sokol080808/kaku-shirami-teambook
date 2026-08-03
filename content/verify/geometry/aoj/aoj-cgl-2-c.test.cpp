#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C"
#define ERROR 0.00000001


#define main main2
#include "../../../contest/template.cpp"
#undef main

#include "../../../geometry/Point.cpp"
#include "../../../geometry/Line.cpp"
#include "../../../geometry/Intersections.cpp"

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
        line l1 = getln(a, b);
        line l2 = getln(c, d);
        vec res;
        assert(intersect(l1, l2, res));
        cout << res.x << " " << res.y << '\n';
    }
}
