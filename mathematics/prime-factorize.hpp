#include <vector>

/*
 * @title 素因数分解
 * @docs docs/mathematics/prime-factorize.md
 */

template<typename T=long long>
std::vector<T> prime_factorize(T n) {
    std::vector<T> ret;
    for (long long i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ret.emplace_back(i);
            n /= i;
        }
    }
    if (n != 1) { ret.push_back(n); }
    return ret;
}