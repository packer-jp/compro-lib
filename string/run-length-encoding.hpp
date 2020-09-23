#include <vector>

template<typename T> std::vector<std::pair<T, int>> run_length_encoding(const std::vector<T> src) {
    std::vector<std::pair<T, int>> ret;
    if (src.size() > 0) { ret.push_back({src[0], 1}); }
    for (int i = 1; i < src.size(); i++) {
        if (src[i] == ret.back().first) { ret.back().second++; }
        else { ret.push_back({src[i], 1}); }
    }
    return ret;
}