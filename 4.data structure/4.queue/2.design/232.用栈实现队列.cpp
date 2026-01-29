/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:37:03
 *   modified:  2025-03-01 19:50:46
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
private:
    stack<int> outStk, inStk;

    void rotate() { // outStk <- inStk
        while (!inStk.empty()) {
            outStk.push(inStk.top());
            inStk.pop();
        }
    }

public:
    MyQueue() {
    }

    void push(int x) {
        inStk.push(x);
    }

    int pop() {
        int top = peek();
        outStk.pop();
        return top;
    }

    int peek() {
        if (outStk.empty()) {
            rotate();
        }
        return outStk.top();
    }

    bool empty() {
        return inStk.empty() && outStk.empty();
    }
};
// @lc code=end
