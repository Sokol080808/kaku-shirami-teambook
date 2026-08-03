/**
 * Author: alexxela12345,daubi,talant
 * Date: 2024-08-03
 * Description: struct Line
 */

struct line {
    ld a, b, c;
    void norm() {
        // for half planes
        ld d = len({a, b});
        assert(sign(d) > 0);
        a /= d;
        b /= d;
        c /= d;
    }
    ld eval(point p) const { return a * p.x + b * p.y + c; }
    bool isIn(point p) const { return sign(eval(p)) >= 0; }
    bool operator==(const line &other) const {
        return sign(a * other.b - b * other.a) == 0 &&
               sign(a * other.c - c * other.a) == 0 &&
               sign(b * other.c - c * other.b) == 0;
    }
};
line getln(point a, point b) {
    line res;
    res.a = a.y - b.y;
    res.b = b.x - a.x;
    res.c = -(res.a * a.x + res.b * a.y);
    res.norm();
    return res;
}
