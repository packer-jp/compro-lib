#include <vector>
#include "stirling-number-2-table.hpp"

template<typename T> std::vector<std::vector<T>> bell_number_table(int n, int k) {
    std::vector ret = stirling_number_2_table<T>(n, k);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < k; j++) { ret[i][j + 1] += ret[i][j]; }
    }
    return ret;
}