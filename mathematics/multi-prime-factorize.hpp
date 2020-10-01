#include <vector>
#include <numeric>

struct multi_prime_factorize {
    std::vector<int> spf;
    multi_prime_factorize(int n) : spf(n + 1) {
        std::iota(spf.begin(), spf.end(), 0LL);
        for (int i = 2; i * i <= n; i++) {
            if (spf[i] < i) { continue; }
            for (int j = i * i; j <= n; j += i) {
                if (spf[j] == j) { spf[j] = i; }
            }
        }
    }
    std::vector<int> prime_factorize(int a) {
        std::vector<int> ret;
        while (a > 1) {
            ret.emplace_back(spf[a]);
            a /= spf[a];
        }
        return ret;
    }
};