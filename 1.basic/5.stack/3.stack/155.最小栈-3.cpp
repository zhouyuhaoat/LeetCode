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
    // synchronous -> asynchronous
    // maintain mst synchronous when necessary
    stack<int> stk, mst;

    MinStack() {
        mst.emplace(INT_MAX);
    }

    void push(int val) {
        stk.emplace(val);
        if (val <= mst.top()) {
            mst.emplace(val);
        }
    }

    void pop() {
        int top = stk.top();
        stk.pop();
        if (top == mst.top()) {
            mst.pop();
        }
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return mst.top();
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
