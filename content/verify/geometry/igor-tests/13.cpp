// Yandex Algo 2023-2024. C. Геометрия 2 D - Площадь многоугольника
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
    int n;
    cin >> n;
    vector<point> p(n);
    for (auto& [x, y] : p) {
      cin >> x >> y;
    }
    ld ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += p[i] % p[(i + 1) % n];
    }
    ans = abs(ans) / 2;
    cout << (ll)(ans) << (sign(ans - (ll)ans) == 1 ? ".5" : "") << endl;
}
