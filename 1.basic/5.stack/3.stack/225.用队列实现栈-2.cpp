/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:37:03
 *   modified:  2025-03-02 10:24:14
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
public:
    queue<int> q; // front <- end
    /*
        -----------------------
        top <--- bottom new_top
        -----------------------

        -----------------------
     <- top <--- bottom new_top <-
     |  -----------------------  |
     |>------------------------->|

        -----------------------
        new_top top <--- bottom
        -----------------------
     */

    MyStack() {
    }

    void push(int x) {
        q.emplace(x);
        // after enqueue, rotate the queue by (cycle) moving
        for (int i = 0; i < (int)q.size() - 1; i++) {
            q.emplace(q.front());
            q.pop();
        }
    }

    int pop() {
        int f = q.front();
        q.pop();
        return f;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
