/**
 * Author: alexxela12345,daubi,talant
 * Date: 2024-08-03
 * Description: Polygon functions
 */

vector<point> hull(vector<point> p, bool need_all=false) {
   sort(all(p));
   p.erase(unique(all(p)), end(p));
   int n = p.size(), k = 0;
   if (n <= 2) return p;
   vector<point> ch(2 * n);
   ld th = need_all ? -EPS : +EPS; // 0 : 1 if int
   for (int i = 0; i < n; ch[k++] = p[i++]) {
     while (k >= 2 && (ch[k - 1] - ch[k - 2]) % (p[i] - ch[k - 1]) < th) --k;
   }
   for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = p[i--]) {
     while (k >= t && (ch[k - 1] - ch[k - 2]) % (p[i] - ch[k - 1]) < th) --k;
   }
   ch.resize(k - 1);
   return ch;
 }
