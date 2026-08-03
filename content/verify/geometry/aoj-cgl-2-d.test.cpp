#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D"
#define ERROR 0.00000001


#define main main2
#include "../../contest/template.cpp"
#undef main

#include "../../geometry/Point.cpp"
#include "../../geometry/Line.cpp"
#include "../../geometry/Intersections.cpp"

ld dist_segvec(vec a, vec b, vec v) {
    if (sign((a - b) * (v - b)) >= 0 && sign((b - a) * (v - a)) >= 0) {
        return abs((a - b) % (v - b) / len(a - b));
    }
    return min(len(a - v), len(b - v));
}

ld dist_segseg(vec a, vec b, vec c, vec d) {
    if (intersects(a, b, c, d)) {
        return 0;
    }
    return min({dist_segvec(a, b, c), dist_segvec(a, b, d), dist_segvec(c, d, a), dist_segvec(c, d, b)});
}

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
        cout << dist_segseg(a, b, c, d) << '\n';
    }
}
