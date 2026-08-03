#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#define main main2
#include "../../../contest/template.cpp"
#undef main

#include "../../../geometry/Point.cpp"
#include "../../../geometry/Line.cpp"
#include "../../../geometry/Intersections.cpp"
#include "../../../geometry/IsInPolygon.cpp"
#include "../../../geometry/TangentsAlex.cpp"
#include "../../../geometry/Hull.cpp"

void test() {
    int N = 100000;
    int C = 1e9;
    int Q = 100;
    auto get = [&] (int l, int r) -> int {
      return (ull)rnd() % (r - l + 1) + l;
    };
    auto stupidTangents = [&] (vector<point>& p, point& a) {
      auto cmp = [&](point& lhs, point& rhs) -> bool {
        return sign((lhs - a) % (rhs - a)) > 0;
      };
      int posL = min_element(all(p), cmp) - p.begin();
      int posR = max_element(all(p), cmp) - p.begin();
      return mp(posL, posR);
    };
    for (int test_id = 0; test_id < 50; ++test_id) {
      int n = get(1, N);
      vector<point> p(n);
      for (int i = 0; i < n; ++i) {
        p[i] =vec{(ld)get(-C, C), (ld)get(-C, C)};
      }
      p = hull(p);
      n = p.size();
      for (int i = 0; i < Q; ++i) {
        point a{(ld)-C, (ld)C};
        if (p.size() >= 3) {
          if(isInConvex(p, a) != isIn(p, a)) {
            cerr << "WA convex " << test_id << " " << i << endl;
            cerr << "n = " << n << endl;
            cerr << "p = " << endl;
            for (auto [x, y] : p) {
              cerr << "(" << x << ", " << y << ")" << endl;
            }
            cerr << "a = " << endl;
            cerr << "(" << a.x << " " << a.y << ")" << endl;
            cerr << "ans = " << isIn(p, a) << endl;
            cerr << "out = " << isInConvex(p, a) << endl;
            exit(1);
          }
        }
        if (isIn(p, a)) continue;
        auto ans = stupidTangents(p, a);
        auto out = tangents_alex(p, a);
        bool ok = true;
        if (sign((p[ans.first] - a) % (p[out.first] - a)) != 0) {
          ok = false;
        } else if (sign((p[ans.second] - a) % (p[out.second] - a)) != 0) {
          ok = false;
        }
        if (!ok) {
          cerr << "WA tangents " << test_id << " " << i << endl;
          cerr << "n = " << n << endl;
          cerr << "p = " << endl;
          for (auto [x, y] : p) {
            cerr << "(" << x << ", " << y << ")" << endl;
          }
          cerr << "a = " << endl;
          cerr << "(" << a.x << " " << a.y << ")" << endl;
          cerr << "ans = " << ans.first << " " << ans.second << endl;
          cerr << "out = " << out.first << " " << out.second << endl;
          exit(1);
        }
      }
      cerr << "OK " << test_id << endl;
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    if (a == 1234 && b == 5678) test();
    cout << a + b << endl;
}
