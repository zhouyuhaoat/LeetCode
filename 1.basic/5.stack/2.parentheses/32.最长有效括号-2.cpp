/*
 *   author:    zhouyuhao
 *   created:   2025-03-01 23:30:54
 *   modified:  2025-03-02 10:03:57
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
        for (int i = 0, left = 0; i < (int)s.size(); i++) {
            if (s[i] == '(') {
                left++;
            } else if (left-- == 0) { // no matching open bracket
                s[i] = '*'; // mark the unmatched close bracket
                left++;
            }
        }
        for (int i = s.size() - 1, right = 0; i >= 0; i--) {
            if (s[i] == ')') {
                right++;
            } else if (s[i] == '*') { // reset
                right = 0;
            } else if (right-- == 0) { // no matching close bracket
                s[i] = '*'; // mark the unmatched open bracket
                right++;
            }
        }
        int res = 0, cnt = 0;
        for (char c : s) {
            if (c == '*') { // invalid
                cnt = 0;
            } else {
                res = max(res, ++cnt);
            }
        }
        return res;
    }
};
// @lc code=end
