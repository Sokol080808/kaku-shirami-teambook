// Yandex Algo 2023-2024. C. Геометрия 2 C - Прямая и окружность
// https://ejudge.algocode.ru/cgi-bin/new-client?contest_id=55063
#define main main228
#include "../../../contest/template.cpp"
#undef main

#include "../../../geometry/Point.cpp"
#include "../../../geometry/Line.cpp"
#include "../../../geometry/Tangents.cpp"
#include "../../../geometry/Intersections.cpp"


signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.precision(20), cout.setf(ios::fixed);
    point o;
    ld r;
    line l;
    cin >> o.x >> o.y >> r >> l.a >> l.b >> l.c;
    point I1, I2;
    l.norm();
    int ans = intersect(o, r, l, I1, I2);
    if (!ans) {
      cout << ans << endl;
    } else if (ans == 1) {
      cout << ans << "\n" << I1.x << " " << I1.y << endl;
    } else if (ans == 2) {
      cout << ans << "\n" << I1.x << " " << I1.y << "\n" << I2.x << " " << I2.y << endl;
    }
}
