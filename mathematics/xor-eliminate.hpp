#include <vector>
#include <bitset>

template<typename T> std::vector<T> xor_eliminate(std::vector<T> src) {
    std::vector<T> ret;
    for (int i = 0; i < src.size(); i++) {
        for (int j = src.size() - 1; j > i; j--) {
            int x = src[j]._Find_first(), y = src[j - 1]._Find_first();
            if (x < y) { src[j - 1] ^= src[j]; }
            if (x <= y) { src[j] ^= src[j - 1]; }
        }
        if (src[i].none()) { break; }
        ret.emplace_back(src[i]);
    }
    for (int i = ret.size() - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (ret[j][ret[i]._Find_first()]) { ret[j] ^= ret[i]; }
        }
    }
    return ret;
}