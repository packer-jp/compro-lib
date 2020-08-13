/*
 * @title XorShift
 * @docs docs/utility/xor64.md
 */

long long xor64(long long range) {
    static unsigned long long x = 1145141919810ULL;
    x ^= x << 13;
    x ^= x >> 7;
    return (x ^= x << 17) % range;
}
