#include <cstdlib>

/*
 * @title 二分探索
 * @docs docs/utility/binary-search.md
 */

template<typename F> long long discrete_binary_search(long long ok, long long ng, F is_ok) {
    while (abs(ok - ng) > 1) {
        long long mid = (ok + ng) / 2;
        (is_ok(mid) ? ok : ng) = mid;
    }
    return ok;
}

template<typename F> double continuous_binary_search(double ok, double ng, F is_ok, int n) {
    for (int i = 0; i < n; i++) {
        double mid = (ok + ng) / 2;
        (is_ok(mid) ? ok : ng) = mid;
    }
    return ok;
}