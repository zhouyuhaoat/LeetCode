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
    queue<int> q;
    /*
        use a queue to implement a stack
        1. enqueue:
            -----------------------
            top <--- bottom new_top
            -----------------------
        2. rotate: after enqueue, rotate the queue by (cycle) moving
            -----------------------
          < top <--- bottom new_top <
          | ----------------------- |
          >------------------------->
        3. after enqueue and rotate:
            -----------------------
            new_top top <--- bottom
            -----------------------
    */

    MyStack() {
    }

    void push(int x) {
        q.emplace(x);
        for (int i = 0; i < (int)q.size() - 1; i++) {
            q.emplace(q.front());
            q.pop();
        }
    }

    int pop() {
        int front = q.front();
        q.pop();
        return front;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};
// @lc code=end
