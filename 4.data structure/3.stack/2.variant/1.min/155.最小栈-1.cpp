/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:36:53
 *   modified:  2025-03-01 18:38:03
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
    stack<int> stk, minStk; // auxiliary stack

public:
    MinStack() {
        minStk.push(INT_MAX); // sentinel
    }

    void push(int val) {
        stk.push(val);
        minStk.push(min(minStk.top(), val));
    }

    void pop() {
        stk.pop();
        minStk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minStk.top();
    }
};
// @lc code=end
