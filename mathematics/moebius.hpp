#include <map>
#include <vector>

/*
 * @title メビウス関数
 * @docs docs/graph/moebius.md
 */

std::map<long long, int> moebius(long long n) {
    std::map<long long, int> ret;
    std::vector<int> primes;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            primes.push_back(i);
            while (n % i == 0) { n /= i; }
        }
    }
    if (n != 1) { primes.push_back(n); }
    int m = primes.size();
    for (int i = 0; i < (1 << m); i++) {
        int mul = 1;
        long long d = 1;
        for (int j = 0; j < m; j++) {
            if (i >> j & 1) {
                mul *= -1;
                d *= primes[j];
            }
        }
        ret[d] = mul;
    }
    return ret;
}