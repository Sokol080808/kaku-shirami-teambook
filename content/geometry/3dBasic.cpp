/**
 * Author: talant
 * Date: 2024-09-09
 * Description: Basic 3d geom things
 */
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);
const ld eps = 1e-9;
bool ze(ld x) {
  return fabsl(x) < eps;
}
struct pt {
  ld x, y, z;
  pt operator+(const pt &p) const {
    return pt{x + p.x, y + p.y, z + p.z};
  }
  pt operator-(const pt &p) const {
    return pt{x - p.x, y - p.y, z - p.z};
  }
  ld operator*(const pt &p) const {
    return x * p.x + y * p.y + z * p.z;
  }
  pt operator*(ld a) const {
    return pt{x * a, y * a, z * a};
  }
  pt operator%(const pt &p) const {
    return pt{y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x};
  }
  ld abs() const {
    return sqrtl(*this * *this);
  }
  ld abs2() const {
    return *this * *this;
  }
  pt norm() const {
    ld d = abs();
    return pt{x / d, y / d, z / d};
  }
};
// BEGIN_CODE
struct Plane {
  pt v;
  ld c;
  Plane(pt a, pt b, pt c) {
    v = ((b - a) % (c - a)).norm();
    this->c = a * v;
  }
  ld dist(pt p) {
    return p * v - c;
  }
};
pt projection(pt p, pt a, pt b) {
  pt v = b - a;
  if (ze(v.abs2())) {
    // stub : bad line
    return a;
  }
  return a + v * (((p - a) * v) / (v * v));
}
pair<pt, pt> planesIntersection(Plane a, Plane b) {
  pt dir = a.v % b.v;
  if (ze(dir.abs2())) {
    // stub : parallel planes
    return {pt{1e18, 1e18, 1e18}, pt{1e18, 1e18, 1e18}};
  }
  ld s = a.v * b.v;
  pt v3 = b.v - a.v * s;
  pt h = a.v * a.c + v3 * ((b.c - a.c * s) / (v3 * v3));
  return {h, h + dir};
}
pair<pt, pt> commonPerpendicular(pt a, pt b, pt c, pt d) {
  pt v = (b - a) % (d - c);
  ld S = v.abs();
  if (ze(S)) {
    // stub : parallel lines
    return {pt{1e18, 1e18, 1e18}, pt{1e18, 1e18, 1e18}};
  }
  v = v.norm();
  pt sh = v * (v * c - v * a);
  pt a2 = a + sh;
  ld s1 = ((c - a2) % (d - a2)) * v;
  pt p = a + (b - a) * (s1 / S);
  return {p, p + sh};
}