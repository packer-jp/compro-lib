#include <cmath>
#include <utility>
#include <vector>
#include <algorithm>

/*
 * @title 幾何
 * @docs docs/geometry/geometry.md
 */

struct point {
    double x, y;
    point() : x(0), y(0) {};
    point(double x, double y) : x(x), y(y) {}
    static point polar(double r, double th) { return {r * cos(th), r * sin(th)}; }
    point &operator+=(const point &rhs) {
        x += rhs.x, y += rhs.y;
        return *this;
    }
    point &operator-=(const point &rhs) {
        x -= rhs.x, y -= rhs.y;
        return *this;
    }
    point &operator*=(double rhs) {
        x *= rhs, y *= rhs;
        return *this;
    }
    point &operator/=(double rhs) {
        x /= rhs, y /= rhs;
        return *this;
    }
    point operator+() const { return *this; }
    point operator-() const { return {-x, -y}; }
    point operator+(const point &rhs) const { return point(*this) += rhs; }
    point operator-(const point &rhs) const { return point(*this) -= rhs; }
    point operator*(double rhs) const { return point(*this) *= rhs; }
    point operator/(double rhs) const { return point(*this) /= rhs; }
};
constexpr double EPSQ = 1e-16;
double dot(const point &a, const point &b) { return a.x * b.x + a.y * b.y; }
double det(const point &a, const point &b) { return a.x * b.y - a.y * b.x; }
double norm(const point &a) { return dot(a, a); }
double abs(const point &a) { return sqrt(norm(a)); }
double arg(const point &a) { return atan2(a.y, a.x); }
bool operator==(const point &a, const point &b) { return norm(a - b) < EPSQ; }
bool operator!=(const point &a, const point &b) { return std::rel_ops::operator!=(a, b); }
point revolved(const point &a, double th) { return {a.x * cos(th) - a.y * sin(th), a.x * sin(th) + a.y * cos(th)}; }
int ccw(point a, point b, point c) {
    b -= a, c -= a;
    if (det(b, c) > EPSQ) { return 1; }
    if (det(b, c) < -EPSQ) { return -1; }
    if (dot(b, c) < 0) { return 2; }
    if (norm(b) < norm(c)) { return -2; }
    return 0;
}
std::vector<point> convex_hull(std::vector<point> ps) {
    std::sort(ps.begin(), ps.end(),
              [](const point &a, const point &b) -> bool { return a.x < b.x || a.x == b.x && a.y < b.y; });
    int n = ps.size(), k = 0;
    std::vector<point> qs(n * 2);
    for (int i = 0; i < n; qs[k++] = ps[i++]) {
        while (k > 1 && det(qs[k - 1] - qs[k - 2], ps[i] - qs[k - 1]) < -EPSQ) { k--; }
    }
    for (int i = n - 2, t = k; i >= 0; qs[k++] = ps[i--]) {
        while (k > t && det(qs[k - 1] - qs[k - 2], ps[i] - qs[k - 1]) < -EPSQ) { k--; }
    }
    qs.resize(k - 1);
    return qs;
}