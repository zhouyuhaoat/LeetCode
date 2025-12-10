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
        for (int i = 0, left = 0, right = 0; i < (int)s.size(); i++) { // left <- right
            s[i] == '(' ? left++ : right++;
            if (right > left) { // cut if unmatched
                left = right = 0;
            } else if (right == left) {
                res = max(res, right * 2);
            }
        }
        // left > right => reverse => right < left
        for (int i = (int)s.size() - 1, left = 0, right = 0; i >= 0; i--) { // left -> right
            s[i] == ')' ? right++ : left++;
            if (left > right) {
                left = right = 0;
            } else if (left == right) {
                res = max(res, left * 2);
            }
        }
        return res;
    }
};
// @lc code=end
