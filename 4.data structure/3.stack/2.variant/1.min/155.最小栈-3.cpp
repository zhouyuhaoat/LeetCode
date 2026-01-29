/*
 *   author:    zhouyuhao
 *   created:   2025-01-19 13:09:01
 *   modified:  2025-03-01 19:43:21
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
    stack<int> stk, minStk; // sync -> async

public:
    MinStack() {
        minStk.push(INT_MAX);
    }

    void push(int val) {
        stk.push(val);
        if (val <= minStk.top()) { // minimum value
            minStk.push(val);
        }
    }

    void pop() {
        if (minStk.top() == stk.top()) { // minimum value
            minStk.pop();
        }
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minStk.top();
    }
};
// @lc code=end
