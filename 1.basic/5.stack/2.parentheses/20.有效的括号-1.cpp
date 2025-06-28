/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:36:52
 *   modified:  2025-03-01 17:31:02
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
        unordered_map<char, char> right2left = {{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> stk;
        for (char ch : s) {
            if (!right2left.contains(ch)) { // left: push itself into stack
                stk.emplace(ch);
            } else { // right: compare with left
                if (stk.empty() || stk.top() != right2left[ch]) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};
// @lc code=end
