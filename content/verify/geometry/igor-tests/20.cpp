// 2021-2022 ICPC NERC (NEERC), North-Western Russia Regional Contest
// (Northern Subregionals) G https://codeforces.com/gym/104011/problem/G
#define main main2
#include "../../../contest/template.cpp"
#undef main

#include "../../../geometry/Point.cpp"
#include "../../../geometry/Line.cpp"
#include "../../../geometry/Intersections.cpp"
#include "../../../geometry/IsHpiEmpty.cpp"

int main() {
    cout.precision(20), cout.setf(ios::fixed);
    int n;
    cin >> n;
    vector<point> p(n);
    for (auto& [x, y] : p) {
        cin >> x >> y;
    }
    int pos = min_element(all(p)) - p.begin();
    rotate(p.begin(), p.begin() + pos, p.end());
    vector<point> v;
    for (int i = 0; i < n; ++i) {
        v.push_back(p[i + 1 < n ? i + 1 : 0] - p[i]);
    }
    vector<int> fpos(n);
    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(all(v), point{0,0} - v[i], cmpHalf) - v.begin();
        pos = pos % n;
        fpos[i] = pos;
    }
    auto check = [&](ld x) -> bool {
        vector<line> lines;
        lines.reserve(2 * n);
        auto addLine = [&](int i, int j) {
            vec v1 = (p[j] - p[i]) * (x / (x + 1));
            vec v2 = (p[j + 1 < n ? j + 1 : 0] - p[i]) * (x / (x + 1));
            lines.push_back(getln(p[i] + v1, p[i] + v2));
        };
        for (int i = 0; i < n; ++i) {
            int pos = fpos[i];
            addLine(i, pos);
            addLine(pos, i);
        }
        return !isHpiEmpty(lines);
    };
    ld L = 1, R = 2;
    for (int it = 0; it < 19; ++it) {
        ld M = sqrt(L * R);
        if (check(M)) {
            R = M;
        } else {
            L = M;
        }
    }
    cout << sqrt(L * R) << endl;
}
