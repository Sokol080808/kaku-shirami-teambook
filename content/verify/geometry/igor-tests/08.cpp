// Yandex Algo 2023-2024. C. Геометрия 1 H - Биссектриса
// https://ejudge.algocode.ru/cgi-bin/new-client?contest_id=55061

#define main main228
#include "../../../contest/template.cpp"
#undef main

#include "../../../geometry/Point.cpp"
#include "../../../geometry/Line.cpp"

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.precision(20), cout.setf(ios::fixed);
    point x, y, z;
    cin >> x.x >> x.y >> y.x >> y.y >> z.x >> z.y;
    y = norm(y - x);
    z = norm(z - x);
    line l = getln(x, x + y + z);
    cout << l.a << " " << l.b << " " << l.c << endl;
}
