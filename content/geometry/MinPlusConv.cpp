/**
 * Author: Alexey Vasilyev
 * Date: 2024-08-20
 * Description: Min-Plusconv, A is convex down
 * Time: O(nlogn fast)
 */
// Assumptions: `a` is convex, `opt` has size `n+m-1`
// `opt[k]` will be equal to `arg min(a[k-i] + b[i])`
template<typename T>
void convex_arbitrary_min_plus_conv(T *a, int n, T *b, int m, int *opt) {
    auto rec = [&](auto &&self, int lx, int rx, int ly, int ry) -> void {
        if (lx > rx) return;
        int mx = (lx + rx) >> 1;
        opt[mx] = ly;
        for (int i = ly; i <= ry; ++i)
            if (mx >= i && (mx - opt[mx] >= n || a[mx - opt[mx]] + b[opt[mx]] > a[mx - i] + b[i]))
                opt[mx] = i;
        self(self, lx, mx - 1, ly, opt[mx]);
        self(self, mx + 1, rx, opt[mx], ry);
    };
    rec(rec, 0, n + m - 2, 0, m - 1);
}

// Assumptions: `a` is convex down
template<typename T>
std::vector<T> convex_arbitrary_min_plus_conv(const std::vector<T> &a, const std::vector<T> &b) {
    int n = a.size(), m = b.size();
    int *opt = (int*) malloc(sizeof(int) * (n + m - 1));
    convex_arbitrary_min_plus_conv(a.data(), n, b.data(), m, opt);
    std::vector<T> ans(n + m - 1);
    for (int i = 0; i < n + m - 1; ++i) ans[i] = a[i - opt[i]] + b[opt[i]];
    free(opt);
    return ans;
}
