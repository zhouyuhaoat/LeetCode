/*
 *   author:    zhouyuhao
 *   created:   2025-01-19 11:43:45
 *   modified:  2025-03-01 17:26:01
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            // left: push right into stack
            if (c == '(') {
                stk.emplace(')');
            } else if (c == '[') {
                stk.emplace(']');
            } else if (c == '{') {
                stk.emplace('}');
            } else {
                // right: compare with itself
                if (stk.empty() || stk.top() != c) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};
// @lc code=end
