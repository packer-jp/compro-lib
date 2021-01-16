#include <vector>

template<typename T> std::vector<std::vector<T>> binomial_table(int n) {
    std::vector ret(n + 1, std::vector<T>(n + 1));
    for (int i = 0; i <= N; i++)ret[i][0] = ret[i][1] = 1;
    for (int i = 0; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
        }
    }
    return ret;
}