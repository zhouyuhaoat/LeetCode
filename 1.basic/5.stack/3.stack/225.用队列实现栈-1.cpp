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
    queue<int> q1, q2; // main, auxiliary
    /*
        use two queues to implement a stack
        1. q1:
            ---------------
            top <--- bottom
            ---------------
        2. q2:
            -------
            new_top
            -------
        3. q2 <- q1: after enqueue, push all elements in q1 into q2
            -----------------------
            new_top top <--- bottom
            -----------------------
        4. swap(q1, q2):
    */

    MyStack() {
    }

    void push(int x) {
        q2.emplace(x);
        while (!q1.empty()) {
            q2.emplace(q1.front());
            q1.pop();
        }
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

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
