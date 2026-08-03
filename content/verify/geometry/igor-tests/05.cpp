// Yandex Algo 2023-2024. C. Геометрия 1 E - Расстояние от точки до прямой
// https://ejudge.algocode.ru/cgi-bin/new-client?contest_id=55061

#define main main228
#include "../../../contest/template.cpp"
#undef main

#include "../../../geometry/Point.cpp"
#include "../../../geometry/Line.cpp"

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.precision(20), cout.setf(ios::fixed);
    point p;
    cin >> p.x >> p.y;
    line l;
    cin >> l.a >> l.b >> l.c;
    l.norm();
    cout << abs(l.eval(p)) << endl;
}
