#include <algorithm>
#include <vector>

/*
 * @title 約数列挙
 * @docs docs/mathematics/get-divisors.md
 */

std::vector<long long> get_divisors(long long n) {
    std::vector<long long> ret;
    long long i;
    for (i = 1; i * i < n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            ret.push_back(n / i);
        }
    }
    if (i * i == n) { ret.push_back(i); }
    std::sort(ret.begin(), ret.end());
    return ret;
}