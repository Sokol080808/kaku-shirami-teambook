/**
 * Author: Igor Markelov
 * Date: 2022-11-18
 * Description: Rotating calipers.
 * Time: O(n)
 */

ld diameter(vector<point> p) {
    p = hull(p);
    int n = p.size();
    if (n <= 1) {
        return 0;
    }
    if (n == 2) {
        return len(p[0] - p[1]);
    }
    ld ans = 0;
    int i = 0, j = 1;
    while (i < n) {
        while (sign((p[(i + 1) % n] - p[i]) % (p[(j + 1) % n] - p[j])) >= 0) {
            chkmax(ans, len(p[i] - p[j]));
            j = (j + 1) % n;
        }
        chkmax(ans, len(p[i] - p[j]));
        ++i;
    }
    return ans;
}