#include <vector>

/*
 * @title 素因数分解
 * @docs docs/mathematics/get-prime-factors.md
 */

std::vector<std::pair<long long, int>> get_prime_factors(long long n) {
    std::vector<std::pair<long long, int>> ret;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back({i, 1});
            n /= i;
        }
        while (n % i == 0) {
            ret.back().second++;
            n /= i;
        }
    }
    if (n != 1) { ret.push_back({n, 1}); }
    return ret;
}