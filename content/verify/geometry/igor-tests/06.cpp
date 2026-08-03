// Yandex Algo 2023-2024. C. Геометрия 1 F - Пересечение прямых
// https://ejudge.algocode.ru/cgi-bin/new-client?contest_id=55061

#define main main228
#include "../../../contest/template.cpp"
#undef main

#include "../../../geometry/Point.cpp"
#include "../../../geometry/Line.cpp"
#include "../../../geometry/Intersections.cpp"

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.precision(20), cout.setf(ios::fixed);
    vec a, b, c, d;
    line l, m;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
    l = getln(a, b);
    m = getln(c, d);
    vec ans;
    if (intersect(l, m, ans)) {
        cout << 1 << " " << ans.x << " " << ans.y << endl;
    } else if (l == m) {
        cout << 2 << endl;
    } else {
        cout << 0 << endl;
    }
}
