#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A"

#define main main2
#include "../../../contest/template.cpp"
#undef main

#include "../../../geometry/Point.cpp"
#include "../../../geometry/Hull.cpp"

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.precision(20), cout.setf(ios::fixed);

    int n;
    cin >> n;
    vector<vec> arr(n);
    for (auto &el : arr) {
        cin >> el.x >> el.y;
    }
    arr = hull(arr, true);
    cout << arr.size() << '\n';
    rotate(arr.begin(), min_element(all(arr), [&](auto a, auto b) {
        return mp(a.y, a.x) < mp(b.y, b.x);
    }), arr.end());
    for (auto el : arr) {
        cout << (int)el.x << " " << (int)el.y << '\n';
    }
}
