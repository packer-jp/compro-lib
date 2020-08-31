#include <bitset>

/*
 * @title ビットリバース
 * @docs docs/utility/bit-reverse.md
 */

template<typename T> T bit_reverse(T x) {
    for (int i = 0; i < x.size() / 2; i++) {
        bool tmp = x[x.size() - i - 1];
        x[x.size() - i - 1] = x[i], x[i] = tmp;
    }
    return x;
}