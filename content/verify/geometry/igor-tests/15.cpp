// Yandex Algo 2023-2024. C. Геометрия 2 F - Выпукл ли многоугольник
// https://ejudge.algocode.ru/cgi-bin/new-client?contest_id=55063
#define main main228
#include "../../../contest/template.cpp"
#undef main

#include "../../../geometry/Point.cpp"
#include "../../../geometry/Hull.cpp"


signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.precision(20), cout.setf(ios::fixed);
    int n;
    cin >> n;
    vector<point> p(n);
    for (auto& [x, y] : p) {
      cin >> x >> y;
    }
    if (hull(p, true).size() == n) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
}
