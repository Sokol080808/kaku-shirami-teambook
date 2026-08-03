/**
 * Author: Iurii Pustovalov
 * Date: 2022-11-08
 * Description: Calculates min-cyclic-shift of s, Duval decomposition
 * Time: O(n)
 */
string minshift(string s) {
    int i = 0, ans = 0;
    s += s; // Remove for lyndon decomposition 
    int n = s.size();
    while (i < n / 2) { // (i < n) lyndon
        ans = i;
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j]) {
            if (s[k] < s[j])
                k = i;
            else
                ++k;
            ++j;
        }
        while (i <= k) {
            // s.substr(i,j-k) - simple string
            i += j - k;
        }
    }
    return s.substr(ans, n / 2);
}
