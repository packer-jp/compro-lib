#include <algorithm>
#include <vector>

/*
 * @title 約数列挙
 * @docs docs/mathematics/get-divisors.md
 */

template<typename T> std::vector<T> get_divisors(T n) {
    std::vector<T> ret;
    T i;
    for (i = 1; i * i < n; i++) {
        if (n % i == 0) {
            ret.emplace_back(i);
            ret.emplace_back(n / i);
        }
    }
    if (i * i == n) { ret.emplace_back(i); }
    std::sort(ret.begin(), ret.end());
    return ret;
}