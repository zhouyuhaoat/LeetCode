/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:36:52
 *   modified:  2025-03-02 15:18:45
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
        // reverse polish notation, postfix notation
        stack<int> stk;
        for (string& token : tokens) {
            if (isdigit(token.back())) { // negative begins with '-'
                stk.emplace(stoi(token));
            } else {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                switch (token[0]) {
                    case '+':
                        stk.emplace(a + b);
                        break;
                    case '-':
                        stk.emplace(a - b);
                        break;
                    case '*':
                        stk.emplace(a * b);
                        break;
                    case '/':
                        stk.emplace(a / b);
                        break;
                }
            }
        }
        return stk.top();
    }
};
// @lc code=end
