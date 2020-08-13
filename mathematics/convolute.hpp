#include <cmath>
#include <vector>
#include "mod-int.hpp"

/*
 * @title 畳み込み
 * @docs docs/mathematics/convolute.md
 */

constexpr double PI = 3.1415926535897932384626433832795028;

struct my_complex {
    double real = 0, imag = 0;
    my_complex() {}
    my_complex(double real) : real(real) {}
    my_complex(double real, double imag) : real(real), imag(imag) {}
    my_complex operator+() const { return *this; }
    my_complex operator-() const { return {-real, -imag}; }
    my_complex &operator+=(const my_complex &rhs) {
        real += rhs.real;
        imag += rhs.imag;
        return *this;
    }
    my_complex &operator-=(const my_complex &rhs) {
        real -= rhs.real;
        imag -= rhs.imag;
        return *this;
    }
    my_complex &operator*=(const my_complex &rhs) {
        double tmp = real * rhs.real - imag * rhs.imag;
        imag = real * rhs.imag + imag * rhs.real;
        real = tmp;
        return *this;
    }
    my_complex &operator/=(const int &rhs) {
        real /= rhs;
        imag /= rhs;
        return *this;
    }
    my_complex operator+(const my_complex &rhs) const { return my_complex(*this) += rhs; }
    my_complex operator-(const my_complex &rhs) const { return my_complex(*this) -= rhs; }
    my_complex operator*(const my_complex &rhs) const { return my_complex(*this) *= rhs; }
    my_complex operator/(const int &rhs) const { return my_complex(*this) /= rhs; }
    my_complex conj() { return {real, -imag}; }
};

template<typename T> void fft(std::vector<T> &x, const std::vector<T> &w) {
    int n = x.size();
    int m = n >> 1;
    std::vector<T> y(n);
    for (int i = 1; i <= m; i <<= 1) {
        for (int j = 0; j < m; j += i) {
            for (int k = 0; k < i; k++) {
                int u = j + k;
                y[(u << 1) + 0] = (x[u + 0] + x[u + m]);
                y[(u << 1) + 1] = (x[u + 0] - x[u + m]) * w[j];
            }
        }
        std::swap(x, y);
    }
}

template<typename T> void ifft(std::vector<T> &x, const std::vector<T> &w) {
    int n = x.size();
    int m = n >> 1;
    std::vector<T> y(n);
    for (int i = m; i > 0; i >>= 1) {
        for (int j = 0; j < m; j += i) {
            for (int k = 0; k < i; k++) {
                int u = j + k;
                x[(u << 1) + 1] *= w[j];
                y[u + 0] = x[(u << 1) + 0] + x[(u << 1) + 1];
                y[u + m] = x[(u << 1) + 0] - x[(u << 1) + 1];
            }
        }
        std::swap(x, y);
    }
    T n_inv = T(1) / n;
    for (int i = 0; i < n; i++) { x[i] *= n_inv; }
}

std::vector<double> convolute(const std::vector<double> &a, const std::vector<double> &b) {
    int n_a = a.size(), n_b = b.size();
    int n_ = n_a + n_b - 1, n;
    for (n = 1; n < n_; n <<= 1) {}
    int m = n >> 1;
    std::vector<my_complex> c(n), w(m);
    for (int i = 0; i < n_a; i++) { c[i].real = a[i]; }
    for (int i = 0; i < n_b; i++) { c[i].imag = b[i]; }
    double theta = -2 * PI / n;
    for (int i = 0; i < m; i++) { w[i] = {cos(i * theta), sin(i * theta)}; }
    fft(c, w);
    auto to_prod = [&](int p, int q) {
        static my_complex miq = {0, -0.25};
        my_complex c_p_sq = c[p] * c[p];
        my_complex c_q_sq = c[q] * c[q];
        c[p] = (c_p_sq - c_q_sq.conj()) * miq;
        c[q] = (c_q_sq - c_p_sq.conj()) * miq;
    };
    to_prod(0, 0);
    for (int i = 1, m = 1; i < n; i += 2) {
        if (i >= m) { m <<= 1; }
        int j = m + (m >> 1) - 1 - i;
        to_prod(i, j);
    }
    for (int i = 0; i < m; i++) { w[i] = w[i].conj(); }
    ifft(c, w);
    std::vector<double> ret(n_);
    for (int i = 0; i < n_; i++) { ret[i] = c[i].real; }
    return ret;
}

template<int MOD, int ROOT>
std::vector<int> friendly_mod_convolute(const std::vector<int> &a, const std::vector<int> &b) {
    int n_a = a.size(), n_b = b.size();
    int n_ = n_a + n_b - 1, n;
    for (n = 1; n < n_; n <<= 1) {}
    int m = n >> 1;
    std::vector<mod_int<MOD>> a_mint(n), b_mint(n), w(m + 2);
    std::copy(a.begin(), a.end(), a_mint.begin()), std::copy(b.begin(), b.end(), b_mint.begin());
    w[0] = 1, w[1] = mod_int<MOD>(ROOT).pow((MOD - 1) / n);
    for (int i = 2; i < m; i++) { w[i] = w[i - 1] * w[1]; }
    fft(a_mint, w);
    fft(b_mint, w);
    for (int i = 0; i < n; i++) { a_mint[i] *= b_mint[i]; }
    w[1] = w[1].inv();
    for (int i = 2; i < m; i++) { w[i] = w[i - 1] * w[1]; }
    ifft(a_mint, w);
    std::vector<int> ret(n_);
    for (int i = 0; i < n_; i++) { ret[i] = a_mint[i].val; }
    return ret;
}

template<int K = 3>
std::vector<int> arbitrary_mod_convolute(const std::vector<int> &a, const std::vector<int> &b, int mod) {
    static constexpr int MS[] = {998244353, 469762049, 167772161}, RS[] = {3, 3, 3};
    static auto safe_mod = [](int a, int m) -> int {
        a %= m;
        if (a < 0) { a += m; }
        return a;
    };
    static auto mod_inv = [](int a, int m) -> int {
        int b = m, x = 1, u = 0;
        while (b) {
            int t = a / b;
            std::swap(a -= t * b, b);
            std::swap(x -= t * u, u);
        }
        return safe_mod(x, m);
    };
    int n_a = a.size(), n_b = b.size();
    int n_ = n_a + n_b - 1, n;
    for (n = 1; n < n_; n <<= 1) {}
    std::vector<int> m(K + 1), prod_m(K + 1, 1);
    std::vector<std::vector<int>> ret(K + 1, std::vector<int>(n_));
    std::copy(MS, MS + K, m.begin());
    m[K] = mod;
    for (int i = 0; i < K; i++) {
        std::vector<int> piece;
        if (i == 0) { piece = friendly_mod_convolute<MS[0], RS[0]>(a, b); }
        if (i == 1) { piece = friendly_mod_convolute<MS[1], RS[1]>(a, b); }
        if (i == 2) { piece = friendly_mod_convolute<MS[2], RS[2]>(a, b); }
        int prod_inv = mod_inv(prod_m[i], m[i]);
        for (int j = 0; j < n_; j++) {
            int mod_m_i = (long long) safe_mod(piece[j] - ret[i][j], m[i]) * prod_inv % m[i];
            for (int k = i + 1; k <= K; k++) {
                ret[k][j] = (ret[k][j] + (long long) mod_m_i * prod_m[k] % m[k]) % m[k];
            }
        }
        for (int j = i + 1; j <= K; j++) { prod_m[j] = (long long) prod_m[j] * m[i] % m[j]; }
    }
    return ret[K];
}
