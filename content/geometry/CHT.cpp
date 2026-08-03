/**
 * Author: Allvik
 * Date: 2022-08-09
 * Description: CHT for minimum, k is decreasing, works for equal slopes
 */

struct line {
    int k, b;
    int eval(int x) {
        return k * x + b;
    }
}; 
struct part {
    line a;
    ld x;
};
ld intersection(line a, line b) {
    return (ld) (a.b - b.b) / (b.k - a.k);
}
struct ConvexHullMin {
    vector <part> st;
    void add(line a) {
        if (!st.empty() && st.back().a.k == a.k) {
            if (st.back().a.b > a.b) st.pop_back();
            else return;
        }
        while (st.size() > 1 && intersection(st[st.size() - 2].a, a) <= st[st.size() - 2].x) st.pop_back();
        if (!st.empty()) st.back().x = intersection(st.back().a, a);
        st.push_back({a, INF});
    }
    int get_val(int x) {
        int l = -1, r = (int)st.size() - 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (st[m].x < x) l = m;
            else r = m;
        }
        return st[r].a.eval(x);
    }
};
