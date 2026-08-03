// Yandex Algo 2023-2024. B'. Геометрия 2 B - Замок
// https://ejudge.algocode.ru/cgi-bin/new-client?contest_id=54021
#define main main228
#include "../../../contest/template.cpp"
#undef main

#include "../../../geometry/Point.cpp"
#include "../../../geometry/Line.cpp"
#include "../../../geometry/Intersections.cpp"
#include "../../../geometry/IsInPolygon.cpp"


signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.precision(20), cout.setf(ios::fixed);
    int n;
    cin >> n;
    vector<vector<point>> p(n);
    vector<ld> areas(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        p[i].resize(k);
        for (auto& [x, y] : p[i]) {
            cin >> x >> y;
        }
        ld area = 0;
        for (int j = 0; j < k; ++j) {
            area += p[i][j] % p[i][(j + 1) % k];
        }
        area /= 2;
        area = abs(area);
        areas[i] = area;
    }
    vector<int> order(n);
    iota(all(order), 0);
    sort(all(order), [&](int lhs, int rhs) -> bool { return areas[lhs] < areas[rhs]; }); vector<bool> used(n); int q; cin >> q; for (int i = 0; i < q; ++i) { point a; cin >> a.x >> a.y; int L = -1, R = n; while (L < R - 1) { int M = (L + R) / 2; if (isInConvex(p[order[M]], a)) { R = M; } else { L = M; } } if (R < n) used[R] = true; } ld ans = 0; for (int i = 0; i < n; ++i) { if (used[i]) { ans += areas[order[i]] - (i > 0 ? areas[order[i - 1]] : 0); } } // NOLINT
    cout << ans << endl;
}
