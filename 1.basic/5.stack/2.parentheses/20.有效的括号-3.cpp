/*
 *   author:    zhouyuhao
 *   created:   2025-11-30 23:36:52
 *   modified:  2025-12-01 17:31:02
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
        unordered_map<char, char> left2right = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        stack<char> stk;
        for (char ch : s) {
            if (left2right.contains(ch)) {
                stk.emplace(ch);
            } else {
                if (stk.empty() || left2right[stk.top()] != ch) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};
// @lc code=end
