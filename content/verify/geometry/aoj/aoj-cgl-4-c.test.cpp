#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C"
#define ERROR 0.000001

#define main main2
#include "../../../contest/template.cpp"
#undef main

#include "../../../geometry/Point.cpp"
#include "../../../geometry/Line.cpp"
#include "../../../geometry/Intersections.cpp"
#include "../../../geometry/HalfPlaneIntersection.cpp"

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.precision(20), cout.setf(ios::fixed);

    int n;
    cin >> n;
    vector<vec> arr(n);
    for (auto &el : arr) {
        cin >> el.x >> el.y;
    }
    vector<line> lines;
    for (int i = 0; i < n; ++i) {
        lines.push_back(getln(arr[i], arr[(i + 1) % n]));
    }
    int q;
    cin >> q;
    while (q--) {
        vec v1, v2;
        cin >> v1.x >> v1.y;
        cin >> v2.x >> v2.y;
        line l = getln(v1, v2);
        auto lines2 = lines;
        lines2.push_back(l);
        auto p = hpi(lines2);
        ld res = 0;
        for (int i = 0; i < (int) p.size(); ++i) {
            res += p[i] % p[(i + 1) % p.size()];
        }
        res /= 2;
        cout << res << '\n';
    }
}
