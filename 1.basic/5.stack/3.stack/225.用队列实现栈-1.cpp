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
public:
    queue<int> q, q_in; // main, auxiliary
    /*
        q:
        ---------------
        top <--- bottom
        ---------------

        q_in:
        -------
        new_top
        -------

        q_in <- q:
        -----------------------
        new_top top <--- bottom
        -----------------------
    */

    MyStack() {
    }

    void push(int x) {
        q_in.emplace(x);
        // after enqueue, push all elements in q into q_in
        while (!q.empty()) {
            q_in.emplace(q.front());
            q.pop();
        }
        swap(q, q_in);
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
