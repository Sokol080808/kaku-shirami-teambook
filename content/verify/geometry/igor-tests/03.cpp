// Yandex Algo 2023-2024. C. Геометрия 1 C - Точка в углу
// https://ejudge.algocode.ru/cgi-bin/new-client?contest_id=55061
#define main main228
#include "../../../contest/template.cpp"
#undef main

#include "../../../geometry/Point.cpp"

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.precision(20), cout.setf(ios::fixed);

    vec a, o, b, p;
    cin >> a.x >> a.y >> o.x >> o.y >> b.x >> b.y >> p.x >> p.y;
    a = a - o;
    b = b - o;
    if (sign(a % b) <= 0) {
        swap(a, b);
    }
    p = p - o;
    bool ok = true;
    if (sign(a % b) == 1) {
        ok = sign(a % p) >= 0 && sign(p % b) >= 0;
    } else {
        ok = !(sign(a % p) < 0 && sign(p % b) < 0);
    }
    if (ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

}
