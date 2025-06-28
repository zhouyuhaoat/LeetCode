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
public:
    stack<int> stk, minStk; // auxiliary stack for minimums

    MinStack() {
        minStk.emplace(INT_MAX); // sentinel
    }

    void push(int val) {
        stk.emplace(val);
        minStk.emplace(min(minStk.top(), val));
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

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
