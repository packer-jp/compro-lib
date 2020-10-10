#include <iostream>
#include <utility>
#include <vector>
#include <cassert>

template<int MOD = 1000000007>
struct mod_int {
    int v;
    mod_int(long long v_ = 0) : v(v_ % MOD) { if (v < 0) { v += MOD; }}
    static int mod() { return MOD; }
    int val() const { return v; }
    mod_int &operator+=(const mod_int &a) {
        if ((v += a.v) >= MOD) { v -= MOD; }
        return *this;
    }
    mod_int &operator-=(const mod_int &a) {
        if ((v += MOD - a.v) >= MOD) { v -= MOD; }
        return *this;
    }
    mod_int &operator*=(const mod_int &a) {
        v = (int) ((long long) v * a.v % MOD);
        return *this;
    }
    mod_int &operator/=(const mod_int &a) { return *this *= a.inv(); }
    mod_int operator+() const { return *this; }
    mod_int operator-() const { return -v; }
    mod_int operator++() { return *this += 1; }
    mod_int operator--() { return *this -= 1; }
    mod_int operator++(signed) {
        const mod_int ret(*this);
        ++*this;
        return ret;
    }
    mod_int operator--(signed) {
        const mod_int ret(*this);
        --*this;
        return ret;
    }
    mod_int inv() const {
        int a = v, b = MOD, x = 1, u = 0;
        while (b) {
            int t = a / b;
            std::swap(a -= t * b, b), std::swap(x -= t * u, u);
        }
        return x;
    }
    mod_int pow(long long n) const {
        if (n < 0) { return pow(-n).inv(); }
        mod_int ret = 1, mul = *this;
        while (n) {
            if (n & 1) { ret *= mul; }
            mul *= mul, n >>= 1;
        }
        return ret;
    }
    friend bool operator==(const mod_int &a, const mod_int &b) { return a.v == b.v; }
    friend bool operator!=(const mod_int &a, const mod_int &b) { return std::rel_ops::operator!=(a, b); }
    friend mod_int operator+(mod_int a, const mod_int &b) { return a += b; }
    friend mod_int operator-(mod_int a, const mod_int &b) { return a -= b; }
    friend mod_int operator*(mod_int a, const mod_int &b) { return a *= b; }
    friend mod_int operator/(mod_int a, const mod_int &b) { return a /= b; }
    friend std::istream &operator>>(std::istream &is, mod_int &a) {
        long long v;
        is >> v, a = v;
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const mod_int &a) { return os << a.v; }
};

template<int &MOD>
struct runtime_mod_int {
    int v;
    runtime_mod_int(long long v_ = 0) : v(v_ % MOD) { if (v < 0) { v += MOD; }}
    static int mod() { return MOD; }
    int val() const { return v; }
    runtime_mod_int &operator+=(const runtime_mod_int &a) {
        if ((v += a.v) >= MOD) { v -= MOD; }
        return *this;
    }
    runtime_mod_int &operator-=(const runtime_mod_int &a) {
        if ((v += MOD - a.v) >= MOD) { v -= MOD; }
        return *this;
    }
    runtime_mod_int &operator*=(const runtime_mod_int &a) {
        v = (int) ((long long) v * a.v % MOD);
        return *this;
    }
    runtime_mod_int &operator/=(const runtime_mod_int &a) { return *this *= a.inv(); }
    runtime_mod_int operator+() const { return *this; }
    runtime_mod_int operator-() const { return -v; }
    runtime_mod_int operator++() { return *this += 1; }
    runtime_mod_int operator--() { return *this -= 1; }
    runtime_mod_int operator++(signed) {
        const runtime_mod_int ret(*this);
        ++*this;
        return ret;
    }
    runtime_mod_int operator--(signed) {
        const runtime_mod_int ret(*this);
        --*this;
        return ret;
    }
    runtime_mod_int inv() const {
        int a = v, b = MOD, x = 1, u = 0;
        while (b) {
            int t = a / b;
            std::swap(a -= t * b, b), std::swap(x -= t * u, u);
        }
        return x;
    }
    runtime_mod_int pow(long long n) const {
        if (n < 0) { return pow(-n).inv(); }
        runtime_mod_int ret = 1, mul = *this;
        while (n) {
            if (n & 1) { ret *= mul; }
            mul *= mul, n >>= 1;
        }
        return ret;
    }
    friend bool operator==(const runtime_mod_int &a, const runtime_mod_int &b) { return a.v == b.v; }
    friend bool operator!=(const runtime_mod_int &a, const runtime_mod_int &b) {
        return std::rel_ops::operator!=(a, b);
    }
    friend runtime_mod_int operator+(runtime_mod_int a, const runtime_mod_int &b) { return a += b; }
    friend runtime_mod_int operator-(runtime_mod_int a, const runtime_mod_int &b) { return a -= b; }
    friend runtime_mod_int operator*(runtime_mod_int a, const runtime_mod_int &b) { return a *= b; }
    friend runtime_mod_int operator/(runtime_mod_int a, const runtime_mod_int &b) { return a /= b; }
    friend std::istream &operator>>(std::istream &is, runtime_mod_int &a) {
        long long v;
        is >> v, a = v;
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const runtime_mod_int &a) { return os << a.v; }
};

template<typename T>
struct combination {
    std::vector<T> fact, finv, inv;
    combination(int n) : fact(n + 1), finv(n + 1), inv(n + 1) {
        fact[0] = fact[1] = finv[0] = finv[1] = inv[1] = 1;
        for (int i = 2; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
            inv[i] = -inv[T::mod() % i] * (T::mod() / i);
            finv[i] = finv[i - 1] * inv[i];
        }
    }
    T P(int n, int r) { return r < 0 || n < r ? 0 : (fact[n] * finv[n - r]); }
    T C(int n, int r) { return P(n, r) * finv[r]; }
    T H(int n, int r) { return C(n + r - 1, r); }
    T catalan(int n) { return C(2 * n, n) * inv[n + 1]; }
};