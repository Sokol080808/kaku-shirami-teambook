#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#define main main2
#include "../../../contest/template.cpp"
#undef main

#include "../../../geometry/Point.cpp"
#include "../../../geometry/Line.cpp"
#include "../../../geometry/Intersections.cpp"
#include "../../../geometry/IsHpiEmpty.cpp"
#include "../../../geometry/HalfPlaneIntersection.cpp"

void test() {
    int N = 10;
    int C = 10;
    auto get = [&](int l, int r) -> int {
        return (ull)rnd() % (r - l + 1) + l;
    };
    auto getPoint = [&]() -> point {
        return {get(-C, C), get(-C, C)};
    };
    for (int test_id = 0;test_id<10000; ++test_id) {
        int n = get(1, N);
        vector<line> lines(n);
        for (int i = 0; i < n; ++i) {
            point a = getPoint();
            point b = getPoint();
            while (a == b) {
                b = getPoint();
            }
            lines[i] = getln(a, b);
        }
        // cerr << "n = " << n << endl;
        // cerr << "lines = " << endl;
        // for (auto [a, b, c] : lines) {
        //   cerr << "x * " << a << " + y * " << b << " + " << c << " = 0"
        //   << endl;
        // }
        const ld C = 1e9;
        vector<point> box = {{-C, -C}, {C, -C}, {C, C}, {-C, C}};
        for (int i = 0; i < 4; ++i) {
            lines.push_back(getln(box[i], box[(i + 1) % 4]));
        }
        bool ans = hpi(lines).empty();
        lines.resize(n);
        bool out = isHpiEmpty(lines);
        if (ans == 0 && out == 1) {
            cerr << "WA isHpiEmpty " << test_id << endl;
            cerr << "n = " << n << endl;
            cerr << "lines = " << endl;
            for (auto [a, b, c] : lines) {
                cerr << "x * " << a << " + y * " << b << " + " << c
                     << " = 0" << endl;
            }
            cerr << "ans = " << ans << endl;
            cerr << "out = " << out << endl;
            exit(1);
        }
        cerr << "OK " << test_id << " ans = " << ans << endl;
    }

}

int main() {
    int a, b;
    cin >> a >> b;
    if (a == 1234 && b == 5678) test();
    cout << a + b << endl;
}
