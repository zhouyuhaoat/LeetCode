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
        /*
            greedy
            - cut if invalid, update if valid
            - invalid
                - right > left if scan from left to right, as ())
                - left > right if scan from right to left, as (()
                - reverse scan
            - valid
                - left == right
                - balance
        */
        for (int i = 0, left = 0, right = 0; i < (int)s.size(); i++) {
            s[i] == '(' ? left++ : right++;
            if (right > left) {
                left = right = 0;
            } else if (left == right) {
                res = max(res, 2 * left);
            }
        }
        for (int i = (int)s.size() - 1, left = 0, right = 0; i >= 0; i--) {
            s[i] == '(' ? left++ : right++;
            if (left > right) {
                left = right = 0;
            } else if (left == right) {
                res = max(res, 2 * right);
            }
        }
        return res;
    }
};
// @lc code=end
