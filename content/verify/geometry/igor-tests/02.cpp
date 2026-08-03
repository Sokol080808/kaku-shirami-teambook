// Yandex Algo 2023-2024. C. Геометрия 1 B - Угол между векторами
// https://ejudge.algocode.ru/cgi-bin/new-client?contest_id=55061
#define main main228
#include "../../../contest/template.cpp"
#undef main

#include "../../../geometry/Point.cpp"

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.precision(20), cout.setf(ios::fixed);
    vec a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    cout << abs(getAngle(a, b)) << endl;
}
