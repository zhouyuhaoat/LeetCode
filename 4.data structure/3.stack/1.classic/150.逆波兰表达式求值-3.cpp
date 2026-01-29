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
        unordered_map<string, function<int(int, int)>> eval = {
            {"+", [](int a, int b) { return a + b; }},
            {"-", [](int a, int b) { return a - b; }},
            {"*", [](int a, int b) { return a * b; }},
            {"/", [](int a, int b) { return a / b; }},
        };
        int top = -1; // using vector to simulate stack is faster
        vector<int> stk((tokens.size() + 1) / 2); // at most half numbers
        for (string& token : tokens) {
            if (!eval.contains(token)) {
                stk[++top] = stoi(token);
            } else {
                int b = stk[top--], a = stk[top--];
                stk[++top] = eval[token](a, b);
            }
        }
        return stk[top];
    }
};
// @lc code=end
