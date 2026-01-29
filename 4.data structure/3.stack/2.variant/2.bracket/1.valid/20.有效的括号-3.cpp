/*
 *   author:    zhouyuhao
 *   created:   2025-01-19 11:45:54
 *   modified:  2025-03-01 17:31:52
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
            if (left2right.contains(ch)) { // left: transform itself and push right into stack
                stk.push(left2right[ch]);
            } else { // right: no transform, just compare
                if (stk.empty() || stk.top() != ch) {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};
// @lc code=end
