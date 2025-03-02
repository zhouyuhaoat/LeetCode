/*
 *   author:    zhouyuhao
 *   created:   2025-03-02 10:05:19
 *   modified:  2025-03-02 10:12:16
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
        // greedy: cut invalid -> valid
        for (int i = 0, left = 0, right = 0; i < (int)s.size(); i++) {
            s[i] == '(' ? left++ : right++;
            if (right > left) { // invalid: as ())
                left = right = 0;
            } else if (left == right) { // valid
                res = max(res, 2 * left);
            }
        }
        // reverse scan
        for (int i = (int)s.size() - 1, left = 0, right = 0; i >= 0; i--) {
            s[i] == '(' ? left++ : right++;
            if (left > right) { // invalid: as (()
                left = right = 0;
            } else if (left == right) { // valid
                res = max(res, 2 * right);
            }
        }
        return res;
    }
};
// @lc code=end
