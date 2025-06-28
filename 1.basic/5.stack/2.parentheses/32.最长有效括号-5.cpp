/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:36:52
 *   modified:  2025-03-01 18:30:04
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
        vector<int> dp(s.size(), 0);
        // dp[i]: the length of longest valid parentheses ending with i
        for (int i = 1; i < (int)s.size(); i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') { // ... [i - 2] ()
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else {
                    int id = i - 1 - dp[i - 1];
                    if (id >= 0 && s[id] == '(') { // ... [id - 1] ( ... [i - 1] )
                        dp[i] = (id >= 1 ? dp[id - 1] : 0) + dp[i - 1] + 2;
                    }
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
// @lc code=end
