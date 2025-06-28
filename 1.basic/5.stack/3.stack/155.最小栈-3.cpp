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
public:
    /*
        synchronous -> asynchronous
        - maintain auxiliary stack only when necessary
        - necessary: include equal
    */
    stack<int> stk, minStk;

    MinStack() {
        minStk.emplace(INT_MAX);
    }

    void push(int val) {
        stk.emplace(val);
        if (val <= minStk.top()) {
            minStk.emplace(val);
        }
    }

    void pop() {
        int top = stk.top();
        stk.pop();
        if (top == minStk.top()) {
            minStk.pop();
        }
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minStk.top();
    }
};
// @lc code=end
