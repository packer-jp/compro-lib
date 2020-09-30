#include <vector>

template<typename T> std::vector<std::vector<T>> stirling_number_2_table(int n) {
    std::vector ret(n + 1, std::vector<T>(n + 1));
    ret[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        ret[i][1] = ret[i][i] = 1;
        for (int j = 2; j < i; j++) { ret[i][j] = ret[i - 1][j - 1] + j * ret[i - 1][j]; }
    }
    return ret;
}