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
            outStk.emplace(inStk.top());
            inStk.pop();
        }
    }

public:
    MyQueue() {
    }

    void push(int x) {
        inStk.emplace(x);
    }

    int pop() {
        int top = peek();
        outStk.pop();
        return top;
    }

    int peek() {
        if (outStk.empty()) rotate();
        return outStk.top();
    }

    bool empty() {
        return inStk.empty() && outStk.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
