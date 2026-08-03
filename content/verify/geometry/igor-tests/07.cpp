// Yandex Algo 2023-2024. C. Геометрия 1 G - Пусти козла в огород - 1
// https://ejudge.algocode.ru/cgi-bin/new-client?contest_id=55061

#define main main228
#include "../../../contest/template.cpp"
#undef main

#include "../../../geometry/Point.cpp"
#include "../../../geometry/Line.cpp"
#include "../../../geometry/Intersections.cpp"

const ld PI = acos(-1);

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.precision(20), cout.setf(ios::fixed);
    point a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    auto calc = [](vec lhs, vec rhs) -> ld {
        ld sgn = sign(lhs % rhs);
        if (!sgn) {
            return 180;
        }
        if (sgn < 0) {
            swap(lhs, rhs);
        }
        return atan2(lhs % rhs, lhs * rhs) / (2 * PI) * 360;
    };
    cout << max({calc(b - a, c - a), calc(c - b, a - b), calc(a - c, b - c)}) << endl;
}
