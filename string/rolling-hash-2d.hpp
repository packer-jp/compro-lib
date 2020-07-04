#include <random>
#include <vector>
#include <cassert>

/*
 * @title 二次元ローリングハッシュ
 * @docs docs/string/rolling-hash-2d.md
 */

struct rolling_hash_2d {
    using ull = unsigned long long;
    static constexpr ull MASK30 = (1ULL << 30) - 1;
    static constexpr ull MASK31 = (1ULL << 31) - 1;
    static constexpr ull MOD = (1ULL << 61) - 1;
    static constexpr ull POSITIVIZER = MOD << 2;
    static std::vector<ull> pow_base_y, pow_base_x;
    int h, w;
    std::vector<std::vector<ull>> hash;
    static void push_pow_y(int h) {
        while (pow_base_y.size() <= h) { pow_base_y.push_back(calc_mod(mul(pow_base_y.back(), pow_base_y[1]))); }
    }
    static void push_pow_x(int w) {
        while (pow_base_x.size() <= w) { pow_base_x.push_back(calc_mod(mul(pow_base_x.back(), pow_base_x[1]))); }
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
    static ull connect_y(ull uhs, ull dhs, int dh) {
        push_pow_y(dh);
        return calc_mod(mul(uhs, pow_base_y[dh]) + dhs);
    }
    static ull connect_x(ull lhs, ull rhs, int rw) {
        push_pow_x(rw);
        return calc_mod(mul(lhs, pow_base_x[rw]) + rhs);
    }
    template<typename T> rolling_hash_2d(const std::vector<std::vector<T>> &src)
        : h(src.size()), w(src[0].size()), hash(h + 1, std::vector<ull>(w + 1)) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                hash[i + 1][j + 1] = calc_mod((mul(hash[i][j + 1], pow_base_y[1]) + src[i][j]));
            }
        }
        for (int i = 1; i <= h; i++) {
            for (int j = 0; j < w; j++) {
                hash[i][j + 1] = calc_mod((mul(hash[i][j], pow_base_x[1]) + hash[i][j + 1]));
            }
        }
        push_pow_y(h);
        push_pow_x(w);
    }
    ull get_hash(int y0, int x0, int y1, int x1) const {
        ull hl = calc_mod(POSITIVIZER - mul(hash[y0][x0], pow_base_y[y1 - y0]) + hash[y1][x0]);
        ull hr = calc_mod(POSITIVIZER - mul(hash[y0][x1], pow_base_y[y1 - y0]) + hash[y1][x1]);
        return calc_mod(POSITIVIZER - mul(hl, pow_base_x[x1 - x0]) + hr);
    }
};
std::vector<rolling_hash_2d::ull> rolling_hash_2d::pow_base_y{1, rng()};
std::vector<rolling_hash_2d::ull> rolling_hash_2d::pow_base_x{1, rng()};