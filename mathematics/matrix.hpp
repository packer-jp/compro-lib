#include <iostream>
#include <vector>
#include <cassert>
#include <utility>

template<typename S>
struct matrix {
    using T = typename S::T;
    std::vector<std::vector<T>> data;
    matrix(int h, int w) : data(h, std::vector<T>(w, S::zero())) {}
    matrix(const std::vector<std::vector<T>> &src) : data(src) {}
    std::vector<T> &operator[](int i) { return data[i]; }
    const std::vector<T> &operator[](int i) const { return data[i]; }
    int height() const { return data.size(); }
    int width() const { return data[0].size(); }
    static matrix id(int n) {
        matrix ret(n, n);
        for (int i = 0; i < n; i++) { ret[i][i] = S::one(); }
        return ret;
    }
    matrix &operator+=(const matrix &a) {
        for (int i = 0; i < height(); i++) {
            for (int j = 0; j < width(); j++) {
                (*this)[i][j] = S::plus((*this)[i][j], a[i][j]);
            }
        }
        return *this;
    }
    matrix &operator-=(const matrix &a) {
        for (int i = 0; i < height(); i++) {
            for (int j = 0; j < width(); j++) {
                (*this)[i][j] = S::plus((*this)[i][j], S::minus(a[i][j]));
            }
        }
        return *this;
    }
    matrix &operator*=(const matrix &a) {
        std::vector<std::vector<T>> ret(height(), std::vector<T>(a.width(), S::zero()));
        for (int i = 0; i < height(); i++) {
            for (int j = 0; j < a.width(); j++) {
                for (int k = 0; k < width(); k++) {
                    ret[i][j] = S::plus(ret[i][j], S::cross((*this)[i][k], a[k][j]));
                }
            }
        }
        data = ret;
        return *this;
    }
    matrix &operator/=(const matrix &a) { return *this *= a.inv(); }
    matrix operator+() const { return *this; }
    matrix operator-() const { return matrix(height(), width()) -= *this; }
    friend bool operator==(const matrix &a, const matrix &b) {
        if (a.height() != b.height() || a.width() != b.width()) { return false; }
        for (int i = 0; i < a.height(); i++) {
            for (int j = 0; j < a.width(); j++) {
                if (a[i][j] != b[i][j]) { return false; }
            }
        }
        return true;
    }
    friend bool operator!=(const matrix &a, const matrix &b) { return std::rel_ops::operator!=(a, b); }
    friend matrix operator+(matrix a, const matrix &b) { return a += b; }
    friend matrix operator-(matrix a, const matrix &b) { return a -= b; }
    friend matrix operator*(matrix a, const matrix &b) { return a *= b; }
    friend matrix operator/(matrix a, const matrix &b) { return a /= b; }
    matrix reduced() const {
        std::vector ret(data);
        for (int i = 0, m = 0; i < width() && m < height(); i++) {
            for (int j = m + 1; j < height(); j++) {
                if (S::less_abs(ret[m][i], ret[j][i])) { swap(ret[m], ret[j]); }
            }
            if (S::less_abs(ret[m][i], S::eps())) { continue; }
            for (int j = width() - 1; j >= i; j--) { ret[m][j] = S::cross(ret[m][j], S::inv(ret[m][i])); }
            for (int j = 0; j < height(); j++) {
                if (j == m) { continue; }
                for (int k = width() - 1; k >= i; k--) {
                    ret[j][k] = S::plus(ret[j][k], S::minus(S::cross(ret[m][k], ret[j][i])));
                }
            }
            m++;
        }
        return ret;
    }
    matrix inv() const {
        matrix id_ = id(height()), ex(std::vector(height(), std::vector<T>(width() << 1)));
        for (int i = 0; i < height(); i++) {
            for (int j = 0; j < width(); j++) { ex[i][j] = (*this)[i][j]; }
            for (int j = 0; j < width(); j++) { ex[i][width() + j] = id_[i][j]; }
        }
        ex = ex.reduced();
        std::vector ret(height(), std::vector<T>(width()));
        for (int i = 0; i < height(); i++) {
            for (int j = 0; j < width(); j++) {
                ret[i][j] = ex[i][width() + j];
            }
        }
        return ret;
    }
    matrix pow(long long n) const {
        matrix ret = id(height()), mul = *this;
        while (n > 0) {
            if (n & 1) { ret *= mul; }
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }
    friend std::ostream &operator<<(std::ostream &os, const matrix &rhs) {
        for (int i = 0; i < rhs.height(); i++) {
            os << (i == 0 ? "{{" : " {");
            for (int j = 0; j < rhs.width(); j++) {
                os << rhs[i][j] << (j + 1 == rhs.width() ? "}" : ", ");
            }
            os << (i == rhs.height() - 1 ? "}" : ",\n");
        }
        return os;
    }
};

struct double_mat {
    using T = double;
    static T plus(const T &a, const T &b) { return a + b; }
    static T cross(const T &a, const T &b) { return a * b; }
    static T zero() { return 0; }
    static T one() { return 1; }
    static T minus(const T &a) { return -a; }
    static T inv(const T &a) { return 1 / a; }
    static T eps() { return 1e-10; };
    static bool less_abs(const T &a, const T &b) { return std::abs(a) < std::abs(b); };
};
