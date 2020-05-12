#include <random>
#include <vector>
#include <cassert>

/*
 * @title ローリングハッシュ
 * @docs docs/string/rolling-hash.md
 */

struct rolling_hash {
    using ull = unsigned long long;
    static constexpr ull MASK30 = (1ULL << 30) - 1;
    static constexpr ull MASK31 = (1ULL << 31) - 1;
    static constexpr ull MOD = (1ULL << 61) - 1;
    static constexpr ull POSITIVIZER = MOD << 2;
    static std::vector<ull> pow_base;
    int n;
    std::vector<ull> hash;
    static void push_hash(int n) {
        while (pow_base.size() <= n) { pow_base.push_back(calc_mod(mul(pow_base.back(), pow_base[1]))); }
    }
    static ull rng() {
        std::random_device rd;
        return std::uniform_int_distribution<ull>(MOD >> 1, MOD - 1)(rd);
    }
    static ull mul(ull a, ull b) {
        ull au = a >> 31;
        ull ad = a & MASK31;
        ull bu = b >> 31;
        ull bd = b & MASK31;
        ull mid = ad * bu + au * bd;
        return (au * bu << 1) + (mid >> 30) + ((mid & MASK30) << 31) + ad * bd;
    }
    static ull calc_mod(ull val) {
        val = (val & MOD) + (val >> 61);
        if (val >= MOD) { val -= MOD; }
        return val;
    }
    static ull connect(ull lhs, ull rhs, int rn) {
        push_hash(rn);
        return calc_mod(mul(lhs, pow_base[rn]) + rhs);
    }
    template<typename T> rolling_hash(const std::vector<T> &src) : n(src.size()), hash(n + 1) {
        for (int i = 0; i < src.size(); i++) { hash[i + 1] = calc_mod(mul(hash[i], pow_base[1]) + src[i]); }
        push_hash(n);
    }
    ull get_hash(int l, int r) const {
        assert(0 <= l && l < n);
        assert(0 < r && r <= n);
        return calc_mod(POSITIVIZER - mul(hash[l], pow_base[r - l]) + hash[r]);
    }
};
std::vector<rolling_hash::ull> rolling_hash::pow_base{1, rng()};