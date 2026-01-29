/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:37:03
 *   modified:  2025-03-01 20:15:48
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
    queue<int> q1, q2; // buffer queue

    void rotate() { // q1 -> q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
    }

public:
    MyStack() {
    }

    void push(int x) {
        q2.push(x);
        rotate();
        swap(q1, q2);
    }

    int pop() {
        int front = q1.front();
        q1.pop();
        return front;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};
// @lc code=end
