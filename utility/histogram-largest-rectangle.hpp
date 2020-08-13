#include <vector>
#include <stack>

/*
 * @title ヒストグラム最大長方形
 * @docs docs/utility/histogram-largest-rectangle.md
 */

template<typename T> long long histogram_largest_rectangle(const std::vector<T> &h) {
    int n = h.size();
    std::vector<int> left(n), right(n);
    {
        std::stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && h[stk.top()] >= h[i]) { stk.pop(); }
            left[i] = stk.empty() ? 0 : (stk.top() + 1);
            stk.emplace(i);
        }
    }
    {
        std::stack<int> stk;
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && h[stk.top()] >= h[i]) { stk.pop(); }
            right[i] = stk.empty() ? n : stk.top();
            stk.emplace(i);
        }
    }
    T ret = 0;
    for (int i = 0; i < n; i++) { ret = std::max(ret, h[i] * (right[i] - left[i])); }
    return ret;
}