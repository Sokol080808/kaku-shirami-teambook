// Yandex Algo 2023-2024. C. Геометрия 2 A - Касательные к окружности
// https://ejudge.algocode.ru/cgi-bin/new-client?contest_id=55063
#define main main228
#include "../../../contest/template.cpp"
#undef main

#include "../../../geometry/Point.cpp"
#include "../../../geometry/Line.cpp"
#include "../../../geometry/Tangents.cpp"


signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.precision(20), cout.setf(ios::fixed);
    point o, p;
    ld r;
    cin >> o.x >> o.y >> r >> p.x >> p.y;
    point I1, I2;
    int ans = tangents(o, r, p, I1, I2);
    if (!ans) {
      cout << ans << endl;
    } else if (ans == 1) {
      cout << ans << "\n" << I1.x << " " << I1.y << endl;
    } else if (ans == 2) {
      cout << ans << "\n" << I1.x << " " << I1.y << "\n" << I2.x << " " << I2.y << endl;
    }
}
