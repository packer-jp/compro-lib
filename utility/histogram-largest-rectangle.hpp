#include <vector>
#include <stack>

template<typename T> T histogram_largest_rectangle(const std::vector<T> &h) {
    int n = h.size();
    std::vector<int> left(n);
    {
        std::stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && h[stk.top()] >= h[i]) { stk.pop(); }
            left[i] = stk.empty() ? 0 : (stk.top() + 1);
            stk.emplace(i);
        }
    }
    std::vector<int> right(n);
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