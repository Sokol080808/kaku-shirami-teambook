// Yandex Algo 2023-2024. C. Геометрия 2 G - Теодор Рузвельт
// https://ejudge.algocode.ru/cgi-bin/new-client?contest_id=55063
#define main main228
#include "../../../contest/template.cpp"
#undef main

#include "../../../geometry/Point.cpp"
#include "../../../geometry/Line.cpp"
#include "../../../geometry/Intersections.cpp"
#include "../../../geometry/IsInPolygon.cpp"


signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.precision(20), cout.setf(ios::fixed);
    int n, m, k;
    cin >> n >> m >> k;
    vector<point> p(n);
    for (auto& [x, y] : p) {
      cin >> x >> y;
    }
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
      point a;
      cin >> a.x >> a.y;
      if (isInConvex(p, a)) {
        ++cnt;
      }
    }
    if (cnt >= k) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
}
