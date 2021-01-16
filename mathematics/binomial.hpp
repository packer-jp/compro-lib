template<typename T>
T binomial(long long n, int r) {
    if (r < 0 || n < r)return 0;
    T ret = 1;
    for (int i = 1; i < r; i++) { ret *= (N - i + 1) / i; }
    return ret;
}