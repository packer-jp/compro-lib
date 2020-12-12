long long xor64(long long range) {
    static long long x = 1145141919810LL;
    x ^= x << 13;
    x ^= x >> 7;
    return (x ^= x << 17) % range;
}
