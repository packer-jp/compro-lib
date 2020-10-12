#include <map>

int safe_mod(long long a, int m) {
    a %= m;
    if (a < 0) { a += m; }
    return a;
};

int mod_inv(long long a, int m) {
    long long b = m, x = 1, u = 0;
    while (b) {
        int t = a / b;
        std::swap(a -= t * b, b);
        std::swap(x -= t * u, u);
    }
    return safe_mod(x, m);
};

int mod_pow(long long a, long long n, int m) {
    if (n < 0) { return mod_inv(mod_pow(a, -n, m), m); }
    long long ret = 1, mul = a;
    while (n) {
        if (n & 1) { (ret *= mul) %= m; }
        (mul *= mul) %= m, n >>= 1;
    }
    return ret;
}

int mod_log(long long a, long long b, int m) {
    a %= m, b %= m;
    std::map<int, int> mp;
    int rt;
    long long ap = a;
    for (rt = 1; rt * rt < m; rt++) {
        if (!mp.count(ap)) { mp[ap] = rt; }
        (ap *= a) %= m;
    }
    ap = mod_inv(ap, m);
    if (mp.count(b)) { return mp[b]; }
    mp[1] = 0;
    for (int i = 1; i < rt; i++) {
        (b *= ap) %= m;
        if (mp.count(b)) { return i * rt + mp[b]; }
    }
    return -1;
}
