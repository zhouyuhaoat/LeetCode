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
public:
    stack<int> stk_in, stk_out; // out <- in
    /*
        out ] [ in

        front ... end] [front ... end

        in:
        ] [ <---

        flip:
        <------------<
        >---> ] [ --->

        out:
        <--- ] [
    */

    MyQueue() {
    }

    void push(int x) {
        stk_in.emplace(x);
    }

    int pop() {
        int t = peek();
        stk_out.pop();
        return t;
    }

    int peek() {
        if (stk_out.empty()) {
            // when stk_out is empty, flip stk_in into stk_out
            while (!stk_in.empty()) {
                stk_out.emplace(stk_in.top());
                stk_in.pop();
            }
        }
        return stk_out.top();
    }

    bool empty() {
        return stk_in.empty() && stk_out.empty();
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
