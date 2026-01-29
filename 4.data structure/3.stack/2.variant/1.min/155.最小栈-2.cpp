/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:36:53
 *   modified:  2025-03-01 18:38:54
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
    stack<pair<int, int>> stk; // {value, minimum}

public:
    MinStack() {
        stk.emplace(0, INT_MAX);
    }

    void push(int val) {
        stk.emplace(val, min(val, stk.top().second));
    }

    void pop() {
        stk.pop();
    }

    int top() {
        return stk.top().first;
    }

    int getMin() {
        return stk.top().second;
    }
};
// @lc code=end
