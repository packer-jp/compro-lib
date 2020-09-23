#include <map>
#include <vector>

template<typename T> std::map<T, int> moebius(T n) {
    std::map<T, int> ret;
    std::vector<T> primes;
    for (T i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            primes.push_back(i);
            while (n % i == 0) { n /= i; }
        }
    }
    if (n != 1) { primes.push_back(n); }
    int m = primes.size();
    for (int i = 0; i < (1 << m); i++) {
        int mul = 1;
        T d = 1;
        for (int j = 0; j < m; j++) {
            if (i >> j & 1) { mul *= -1, d *= primes[j]; }
        }
        ret[d] = mul;
    }
    return ret;
}