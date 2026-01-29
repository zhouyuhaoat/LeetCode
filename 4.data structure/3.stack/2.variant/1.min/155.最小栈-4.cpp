/*
 *   author:    zhouyuhao
 *   created:   2025-11-30 21:59:34
 *   modified:  2026-01-29 16:25:39
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
    long long minVal; // minimum value
    stack<long long> stk;

public:
    MinStack() {
    }

    void push(int val) {
        if (stk.empty()) { // first element
            stk.push(0);
            minVal = val;
        } else {
            stk.push(val - minVal); // difference with (previous) minimum value
            minVal = min(minVal, (long long)val);
        }
    }

    void pop() {
        if (stk.top() <= 0) { // minimum value
            minVal = minVal - stk.top(); // restore (previous) minimum value
        }
        stk.pop();
    }

    int top() {
        if (stk.top() > 0) { // normal value
            return minVal + stk.top(); // recompute (original) normal value
        }
        return minVal; // (current) minimum value
    }

    int getMin() {
        return minVal;
    }
};
// @lc code=end
