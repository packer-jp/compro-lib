#include <vector>

/*
 * @title 素因数分解
 * @docs docs/mathematics/prime-factorize.md
 */

template<typename T> std::vector<T> prime_factorize(T n) {
    std::vector<T> ret;
    for (T i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ret.emplace_back(i);
            n /= i;
        }
    }
    if (n != 1) { ret.emplace_back(n); }
    return ret;
}