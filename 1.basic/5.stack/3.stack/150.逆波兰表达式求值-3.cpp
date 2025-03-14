/*
 *   author:    zhouyuhao
 *   created:   2025-01-19 11:14:10
 *   modified:  2025-03-01 17:19:57
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int(int, int)>> m = {
            {"+", [](int a, int b) { return a + b; }},
            {"-", [](int a, int b) { return a - b; }},
            {"*", [](int a, int b) { return a * b; }},
            {"/", [](int a, int b) { return a / b; }}
        };
        // using array to simulate stack is faster than using std::stack
        int top = -1, n = tokens.size();
        vector<int> stk((n + 1) / 2); // at most (n+1)/2 numbers
        for (string& t : tokens) {
            if (!m.contains(t)) {
                stk[++top] = stoi(t);
            } else {
                int b = stk[top--], a = stk[top--];
                stk[++top] = m[t](a, b);
            }
        }
        return stk[top];
    }
};
// @lc code=end
