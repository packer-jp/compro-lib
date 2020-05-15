#include <iostream>
#include <vector>
#include <cassert>
#include <utility>

/*
 * @title 行列
 * @docs docs/mathematics/matrix.md
 */

template<typename M>
struct matrix {
    using T = typename M::T;
    int h, w;
    std::vector<std::vector<T>> data;
    matrix(int h, int w) : h(h), w(w), data(h, std::vector<T>(w, M::id_pl())) {}
    matrix(const std::vector<std::vector<T>> &src) : h(src.size()), w(src[0].size()), data(src) {}
    std::vector<T> &operator[](int i) { return data[i]; }
    const std::vector<T> &operator[](int i) const { return data[i]; }
    static matrix identity(int n) {
        matrix ret(n, n);
        for (int i = 0; i < n; i++) { ret[i][i] = M::id_cr(); }
        return ret;
    }
    bool operator==(const matrix &rhs) const {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (data[i][j] != rhs[i][j]) { return false; }
            }
        }
        return true;
    }
    bool operator!=(const matrix &rhs) const { return std::rel_ops::operator!=(*this, rhs); }
    matrix &operator+=(const matrix &rhs) {
        assert(h == rhs.h && w == rhs.w);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                (*this)[i][j] = M::pl((*this)[i][j], rhs[i][j]);
            }
        }
        return *this;
    }
    matrix &operator-=(const matrix &rhs) {
        assert(h == rhs.h && w == rhs.w);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                (*this)[i][j] = M::pl((*this)[i][j], M::inv_pl(rhs[i][j]));
            }
        }
        return *this;
    }
    matrix &operator*=(const matrix &rhs) {
        assert(w == rhs.h);
        std::vector<std::vector<T>> ret(h, std::vector<T>(rhs.w, M::id_pl()));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < rhs.w; j++) {
                for (int k = 0; k < w; k++) {
                    ret[i][j] = M::pl(ret[i][j], M::cr((*this)[i][k], rhs[k][j]));
                }
            }
        }
        data = ret;
        h = data.size(), w = data[0].size();
        return *this;
    }
    matrix &operator/=(const matrix &rhs) { return *this *= rhs.inv(); }
    matrix operator+() const { return *this; }
    matrix operator-() const { return matrix(h, w) -= (*this); }
    matrix operator+(const matrix &rhs) const { return matrix(*this) += rhs; }
    matrix operator-(const matrix &rhs) const { return matrix(*this) -= rhs; }
    matrix operator*(const matrix &rhs) const { return matrix(*this) *= rhs; }
    matrix operator/(const matrix &rhs) const { return matrix(*this) /= rhs; }
    matrix inv() const {
        assert(h == w);
        matrix id = identity(h);
        std::vector<std::vector<T>> ex(h, std::vector<T>(w << 1));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) { ex[i][j] = (*this)[i][j]; }
            for (int j = 0; j < w; j++) { ex[i][w + j] = id[i][j]; }
        }
        for (int i = 0; i < h; i++) {
            for (int j = i; j < w; j++) {
                if (!M::is_id_pl(ex[i][j])) {
                    swap(ex[i], ex[j]);
                    break;
                }
            }
            if (M::is_id_pl(ex[i][i])) { return matrix(0, 0); }
            T inv = M::inv_cr(ex[i][i]);
            for (int j = i + 1; j < w << 1; j++) { ex[i][j] = M::cr(ex[i][j], inv); }
            for (int j = i + 1; j < h; j++) {
                for (int k = i + 1; k < w << 1; k++) {
                    ex[j][k] = M::pl(ex[j][k], M::inv_pl(M::cr(ex[i][k], ex[j][i])));
                }
            }
        }
        for (int i = h - 1; i > 0; i--) {
            for (int j = i - 1; j >= 0; j--) {
                for (int k = w; k < w << 1; k++) {
                    ex[j][k] = M::pl(ex[j][k], M::inv_pl(M::cr(ex[i][k], ex[j][i])));
                }
            }
        }
        std::vector<std::vector<T>> ret(h, std::vector<T>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                ret[i][j] = ex[i][w + j];
            }
        }
        return ret;
    }
    matrix pow(long long n) const {
        assert(h == w);
        matrix ret = identity(h), mul = *this;
        while (n > 0) {
            if (n & 1) { ret *= mul; }
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }
    friend std::ostream &operator<<(std::ostream &os, const matrix &rhs) {
        for (int i = 0; i < rhs.h; i++) {
            os << "[";
            for (int j = 0; j < rhs.w; j++) {
                os << rhs[i][j] << (j + 1 == rhs.w ? "]\n" : ",");
            }
        }
        return os;
    }
};

struct double_mat {
    using T = double;
    static constexpr double EPS = 1e-15;
    static T op_pl(const T &a, const T &b) { return a + b; }
    static T op_cr(const T &a, const T &b) { return a * b; }
    static T id_pl() { return 0; }
    static T id_cr() { return 1; }
    static T inv_pl(const T &a) { return -a; }
    static T inv_cr(const T &a) { return 1 / a; }
    static bool is_id_pl(const T &a) { return std::abs(a) < EPS; };
};