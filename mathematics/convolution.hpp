#include <cmath>
#include <vector>
#include "mod-int.hpp"

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

template<typename T> void fft(std::vector<T> &x, std::vector<T> &w) {
    int n = x.size();
    int m = n >> 1;
    std::vector<T> y(n);
    std::vector<T> *p = &x, *q = &y;
    for (int i = 1; i <= m; i <<= 1) {
        for (int j = 0; j < m; j += i) {
            for (int k = 0; k < i; k++) {
                int u = j + k;
                (*q)[(u << 1) + 0] = ((*p)[u + 0] + (*p)[u + m]);
                (*q)[(u << 1) + 1] = ((*p)[u + 0] - (*p)[u + m]) * w[j];
            }
        }
        std::swap(p, q);
    }
    if (p != &x) { std::copy(p->begin(), p->end(), x.begin()); }
}

template<typename T> void ifft(std::vector<T> &x, std::vector<T> &w) {
    int n = x.size();
    int m = n >> 1;
    std::vector<T> y(n);
    std::vector<T> *p = &x, *q = &y;
    for (int i = m; i > 0; i >>= 1) {
        for (int j = 0; j < m; j += i) {
            for (int k = 0; k < i; k++) {
                int u = j + k;
                (*p)[(u << 1) + 1] *= w[j];
                (*q)[u + 0] = (*p)[(u << 1) + 0] + (*p)[(u << 1) + 1];
                (*q)[u + m] = (*p)[(u << 1) + 0] - (*p)[(u << 1) + 1];
            }
        }
        std::swap(p, q);
    }
    T n_inv = T(1) / n;
    for (int i = 0; i < n; i++) { x[i] = (*p)[i] * n_inv; }
}

template<typename I, typename J>
std::vector<my_complex> convolute(I begin_a, I end_a, J begin_b, J end_b) {
    int n_a = end_a - begin_a, n_b = end_b - begin_b, n;
    for (n = 1; n < n_a + n_b - 1; n <<= 1) {}
    int m = n >> 1;
    std::vector<my_complex> c(n), w(m);
    for (int i = 0; i < n_a; i++) { c[i].real = *(begin_a + i); }
    for (int i = 0; i < n_b; i++) { c[i].imag = *(begin_b + i); }
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
    c.resize(n_a + n_b - 1);
    return c;
}

template<int MOD, int ROOT, typename I, typename J>
std::vector<int> friendly_mod_convolute(I begin_a, I end_a, J begin_b, J end_b) {
    int n_a = end_a - begin_a, n_b = end_b - begin_b;
    int n_ = n_a + n_b - 1, n;
    for (n = 1; n < n_; n <<= 1) {}
    int m = n >> 1;
    std::vector<mod_int<MOD>> a(n), b(n), w(m + 2);
    std::copy(begin_a, end_a, begin(a));
    std::copy(begin_b, end_b, begin(b));
    w[0] = 1, w[1] = mod_int<MOD>(ROOT).pow((MOD - 1) / n);
    for (int i = 2; i < m; i++) { w[i] = w[i - 1] * w[1]; }
    fft(a, w);
    fft(b, w);
    for (int i = 0; i < n; i++) { a[i] *= b[i]; }
    w[1] = w[1].inv();
    for (int i = 2; i < m; i++) { w[i] = w[i - 1] * w[1]; }
    ifft(a, w);
    std::vector<int> ret(n_);
    for (int i = 0; i < n_; i++) { ret[i] = a[i].val; }
    return ret;
}

template<int K = 3, typename I, typename J>
std::vector<int> arbitrary_mod_convolute(I begin_a, I end_a, J begin_b, J end_b, int mod) {
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
    int n_a = end_a - begin_a, n_b = end_b - begin_b;
    int n_ = n_a + n_b - 1, n;
    for (n = 1; n < n_; n <<= 1) {}
    std::vector<int> m(K + 1), prod_m(K + 1, 1);
    std::vector<std::vector<int>> ret(K + 1, std::vector<int>(n_));
    std::copy(MS, MS + K, m.begin());
    m[K] = mod;
    for (int i = 0; i < K; i++) {
        std::vector<int> piece;
        if (i == 0) { piece = friendly_mod_convolute<MS[0], RS[0]>(begin_a, end_a, begin_b, end_b); }
        if (i == 1) { piece = friendly_mod_convolute<MS[1], RS[1]>(begin_a, end_a, begin_b, end_b); }
        if (i == 2) { piece = friendly_mod_convolute<MS[2], RS[2]>(begin_a, end_a, begin_b, end_b); }
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