#include <vector>
#include <bitset>

/*
 * @title xor掃き出し
 * @docs docs/mathematics/xor-eliminate.md
 */

template<int N>
std::vector<std::bitset<N>> xor_eliminate(std::vector<std::bitset<N>> src) {
    std::vector<std::bitset<N>> ret;
    for (std::bitset<N> e : src) {
        for (std::bitset<N> b : ret) { if (e[b._Find_first()]) { e ^= b; }}
        if (e.any()) { ret.emplace_back(e); }
    }
    return ret;
}