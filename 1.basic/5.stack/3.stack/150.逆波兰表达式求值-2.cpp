/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:36:52
 *   modified:  2025-03-01 12:39:14
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
        stack<int> stk;
        for (string& t : tokens) {
            if (!m.contains(t)) {
                stk.emplace(stoi(t));
            } else {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                stk.emplace(m[t](a, b));
            }
        }
        return stk.top();
    }
};
// @lc code=end
