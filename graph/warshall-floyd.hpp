template<typename T, typename I, typename F, typename G>
std::vector<std::vector<T>> get_dist(I begin, I end, F f, G g) {
    std::vector<std::vector<T>> ret;
    std::copy(begin, end, ret.begin())
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                T dist = f(ret[i][k], ret[k][j]);
                if (g(ret[i][j], dist)) { ret[i][j] = dist; }
            }
        }
    }
    return ret;
}