#include <vector>

/*
 * @title 素因数分解 (複数クエリ)
 * @docs docs/mathematics/multi-prime-factorize.md
 */

std::vector<int> smallest_prime_factors(int n) {
    std::vector<int> ret(n + 1);
    for (int i = 0; i <= n; i++) { ret[i] = i; }
    for (int i = 2; i * i <= n; i++) {
        if (ret[i] < i) { continue; }
        for (int j = i * i; j <= n; j += i) {
            if (ret[j] == j) { ret[j] = i; }
        }
    }
    return ret;
}

std::vector<int> prime_factorize(int n, const std::vector<int> &spf) {
    std::vector<int> ret;
    while (n > 1) {
        ret.emplace_back(spf[n]);
        n /= spf[n];
    }
    return ret;
}