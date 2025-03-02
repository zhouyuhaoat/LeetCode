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
        stk.emplace(-1); // (left) sentinel, also used as the boundary
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(') {
                stk.emplace(i); // index
            } else {
                stk.pop();
                if (stk.empty()) { // right > left
                    // the previous part: invalid, cut
                    stk.emplace(i); // update the (left) boundary
                } else {
                    res = max(res, i - stk.top());
                }
            }
        }
        return res;
    }
};
// @lc code=end
