/*
 *   author:    zhouyuhao
 *   created:   2025-11-30 21:59:34
 *   modified:  2025-12-01 09:54:44
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
private:
    stack<long long> stk;
    long long min;

public:
    MinStack() {
    }

    void push(int val) {
        if (stk.empty()) { // first element
            stk.emplace(0);
            min = val;
        } else {
            stk.emplace(val - min); // difference with previous minimum
            min = std::min(min, (long long)val);
        }
    }

    void pop() {
        if (stk.top() < 0) { // minimum value
            min = min - stk.top(); // recover previous minimum
        }
        stk.pop();
    }

    int top() {
        if (stk.top() > 0) { // normal value
            return min + stk.top(); // recompute original value
        }
        return min; // current minimum
    }

    int getMin() {
        return min;
    }
};
// @lc code=end
