// Yandex Algo 2023-2024. C. Геометрия 2 B - Пересекаем окружности
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
    int t;
    cin >> t;
    while (t--) {
      point o1, o2;
      ld r1, r2;
      cin >> o1.x >> o1.y >> r1 >> o2.x >> o2.y >> r2;
      point I1, I2;
      int ans = intersect(o1, r1, o2, r2, I1, I2);
      if (!ans || ans == 3) {
        cout << ans << endl;
      } else if (ans == 1) {
        cout << ans << "\n" << I1.x << " " << I1.y << endl;
      } else if (ans == 2) {
        point fans = (I1 + I2) / 2;
        cout << ans << "\n"
             << fans.x << " " << fans.y << "\n"
             << len(o1 - fans) << " " << len(I1 - fans) << "\n"
             << I1.x << " " << I1.y << "\n"
             << I2.x << " " << I2.y << endl;
      }
    }
}
