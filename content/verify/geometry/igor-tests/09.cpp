// Yandex Algo 2023-2024. C. Геометрия 1 I - Пусти козла в огород - 4
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
    point a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    vec v1, v2;
    v1 = norm(b - a);
    v2 = norm(c - a);
    line l = getln(a, a + v1 + v2);
    v1 = norm(a - b);
    v2 = norm(c - b);
    line m = getln(b, b + v1 + v2);
    point ans;
    if (intersect(l, m, ans)) {
      cout << ans.x << " " << ans.y << endl;
    } else {
      assert(false);
    }
}
