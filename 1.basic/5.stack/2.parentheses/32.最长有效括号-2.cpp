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
        stk.emplace(-1); // boundary & sentinel
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(') {
                stk.emplace(i);
            } else {
                stk.pop();
                if (!stk.empty()) {
                    res = max(res, i - stk.top());
                } else { // unmatched ')'
                    stk.emplace(i);
                }
            }
        }
        return res;
    }
};
// @lc code=end
