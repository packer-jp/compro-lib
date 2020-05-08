#include <iostream>
#include <utility>
#include <vector>

/*
 * @title Modulo Integer
 * @docs docs/mathematics/mod-int.md
 */

template<int MOD = 1000000007>
struct mod_int {
    int val;
    mod_int(long long val_ = 0) : val(val_ % MOD) { if (val < 0) { val += MOD; }}
    bool operator==(const mod_int &rhs) const { return val == rhs.val; }
    bool operator!=(const mod_int &rhs) const { return std::rel_ops::operator!=(*this, rhs); }
    mod_int &operator+=(const mod_int &rhs) {
        if ((val += rhs.val) >= MOD) { val -= MOD; }
        return *this;
    }
    mod_int &operator-=(const mod_int &rhs) {
        if ((val += MOD - rhs.val) >= MOD) { val -= MOD; }
        return *this;
    }
    mod_int &operator*=(const mod_int &rhs) {
        val = (int) ((long long) val * rhs.val % MOD);
        return *this;
    }
    mod_int &operator/=(const mod_int &rhs) { return *this *= rhs.inv(); }
    mod_int operator+() const { return *this; }
    mod_int operator-() const { return -val; }
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
    mod_int operator+(const mod_int &rhs) const { return mod_int(*this) += rhs; }
    mod_int operator-(const mod_int &rhs) const { return mod_int(*this) -= rhs; }
    mod_int operator*(const mod_int &rhs) const { return mod_int(*this) *= rhs; }
    mod_int operator/(const mod_int &rhs) const { return mod_int(*this) /= rhs; }
    mod_int inv() const {
        int a = val, b = MOD, x = 1, u = 0;
        while (b) {
            int t = a / b;
            std::swap(a -= t * b, b);
            std::swap(x -= t * u, u);
        }
        return x;
    }
    mod_int pow(long long n) const {
        if (n < 0) { return pow(-n).inv(); }
        mod_int ret = 1, mul = *this;
        while (n) {
            if (n & 1) { ret *= mul; }
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }
    friend std::istream &operator>>(std::istream &is, mod_int &rhs) {
        long long v;
        is >> v;
        rhs = v;
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const mod_int &rhs) { return os << rhs.val; }
    struct combination {
        std::vector<mod_int> fact{1, 1}, f_inv{1, 1}, inv{0, 1};
        void calc(int n) {
            while (fact.size() <= n) {
                int i = fact.size();
                fact.push_back(fact[i - 1] * i);
                inv.push_back(-inv[MOD % i] * (MOD / i));
                f_inv.push_back(f_inv[i - 1] * inv[i]);
            }
        }
        mod_int P(int n, int r) { return r < 0 || n < r ? 0 : (calc(n), fact[n] * f_inv[n - r]); }
        mod_int C(int n, int r) { return r < 0 || n < r ? 0 : (calc(n), fact[n] * f_inv[r] * f_inv[n - r]); }
        mod_int H(int n, int r) { return C(n + r - 1, r); }
    };
};