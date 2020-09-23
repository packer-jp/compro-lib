#include <vector>

std::vector<bool> get_prime_table(int n) {
    std::vector<bool> ret(n + 1, true);
    if (n >= 0) { ret[0] = false; }
    if (n >= 1) { ret[1] = false; }
    for (int i = 2; i * i <= n; i++) {
        if (!ret[i]) { continue; }
        for (int j = i << 1; j <= n; j += i) {
            ret[j] = false;
        }
    }
    return ret;
}