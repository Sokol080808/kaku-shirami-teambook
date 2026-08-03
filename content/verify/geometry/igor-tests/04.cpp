// Yandex Algo 2023-2024. C. Геометрия 1 D - Пересечение отрезков
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
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
    if (intersects(a, b, c, d)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
