/**
 * Author: Igor Markelov
 * Date: 2022-11-12
 * Description: Build suffix array
 * Time: O(n \log(n))
 */
vector<int> buildSuffixArray(string &s) {
    // Remove, if you want to sort cyclic shifts
    s += (char)(1);
    int n = s.size();
    vector<int> a(n);
    iota(all(a), 0);
    stable_sort(all(a), [&](int i, int j) { return s[i] < s[j]; });
    vector<int> c(n);
    int cc = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || s[a[i]] != s[a[i - 1]]) {
            c[a[i]] = cc++;
        } else {
            c[a[i]] = c[a[i - 1]];
        }
    }
    for (int L = 1; L < n; L *= 2) {
        vector<int> cnt(n);
        for (auto i : c) {
            cnt[i]++;
        }
        vector<int> pref(n);
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + cnt[i - 1];
        }
        vector<int> na(n);
        for (int i = 0; i < n; i++) {
            int pos = (a[i] - L + n) % n;
            na[pref[c[pos]]++] = pos;
        }
        a = na;
        vector<int> nc(n);
        cc = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0 || c[a[i]] != c[a[i - 1]] ||
                c[(a[i] + L) % n] != c[(a[i - 1] + L) % n]) {
                nc[a[i]] = cc++;
            } else {
                nc[a[i]] = nc[a[i - 1]];
            }
        }
        c = nc;
    }
    a.erase(a.begin());
    s.pop_back();
    return a;
}
