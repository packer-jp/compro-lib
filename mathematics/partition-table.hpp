#include <vector>

template<typename T> std::vector<std::vector<T>> partition_table(int n, int k) {
    std::vector ret(n + 1, std::vector<T>(k + 1));
    ret[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            ret[i][j] = ret[i][j - 1];
            if (j <= i) { ret[i][j] += ret[i - j][j]; }
        }
    }
    return ret;
}