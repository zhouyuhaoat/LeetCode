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
private:
    queue<int> q;

    void rotate() {
        for (int i = 0; i < (int)q.size() - 1; i++) {
            q.emplace(q.front());
            q.pop();
        }
    }

public:
    MyStack() {
    }

    void push(int x) {
        q.emplace(x);
        rotate();
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
