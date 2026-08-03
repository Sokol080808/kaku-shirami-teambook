// Yandex Algo 2023-2024. C. Геометрия 2 E - Точка в многоугольнике
// https://ejudge.algocode.ru/cgi-bin/new-client?contest_id=55063
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
#ifndef LOCAL
    freopen("point.in", "r", stdin);
    freopen("point.out", "w", stdout);
#endif
    int n;
    cin >> n;
    point a;
    cin >> a.x >> a.y;
    vector<point> p(n);
    for (auto& [x, y] : p) {
        cin >> x >> y;
    }
    if (isIn(p, a)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
