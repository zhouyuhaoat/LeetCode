/*
 *   author:    zhouyuhao
 *   created:   2025-01-19 11:41:38
 *   modified:  2025-03-01 17:30:15
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
            if (c == '(' || c == '[' || c == '{') { // left: push itself into stack
                stk.emplace(c);
            } else {
                if (stk.empty()) return false;
                // right: compare with left
                if (c == ')' && stk.top() != '(') return false;
                if (c == ']' && stk.top() != '[') return false;
                if (c == '}' && stk.top() != '{') return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};
// @lc code=end
