/**
 * Author: Andrew He, chilli
 * Date: 2019-05-07
 * License: CC0
 * Source: folklore
 * Description: Computes the minimum circle that encloses a set of points.
 * Time: expected O(n)
 * Status: stress-tested
 */

ld ccRadius(const vec& A, const vec& B, const vec& C) {
	return len(B-A)*len(C-B)*len(A-C)/abs((B-A)%(C-A))/2;
}
vec circumcenter(const vec& A, const vec& B, const vec& C) {
	vec b = C-A, c = B-A;
	return A + ort(b*(c*c)-c*(b*b))/(b%c)/2;
}

pair<vec, ld> mindisk(vector<vec> ps) {
	shuffle(all(ps), rnd);
	vec o = ps[0];
	ld r = 0, EPS = 1 + 1e-8;
	for (int i = 0; i < ps.size(); ++i) {
         if (len(o - ps[i]) > r * EPS) {
            o = ps[i], r = 0;
            for (int j = 0; j < i; ++j) {
                if (len(o - ps[j]) > r * EPS) {
                    o = (ps[i] + ps[j]) / 2;
                    r = len(o - ps[i]);
                    for (int k = 0; k < j; ++k) {
                         if (len(o - ps[k]) > r * EPS) {
                            o = circumcenter(ps[i], ps[j], ps[k]);
                            r = len(o - ps[i]);
                        }
                    }
                }
            }
        }
    }
    return {o, r};
}
