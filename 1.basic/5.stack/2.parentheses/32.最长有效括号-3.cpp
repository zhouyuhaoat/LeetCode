/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:36:52
 *   modified:  2025-03-01 23:27:59
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        stack<int> stk;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(') {
                stk.emplace(i); // index
            } else {
                /*
                    boundary: last unmatched
                    - the index of the last unmatched ')'
                    - the top of the stack
                    - popping a matched '(' for this ')'
                */
                if (!stk.empty() && s[stk.top()] == '(') {
                    stk.pop();
                    res = max(res, i - (stk.empty() ? -1 : stk.top()));
                } else {
                    stk.emplace(i);
                }
            }
        }
        return res;
    }
};
// @lc code=end
