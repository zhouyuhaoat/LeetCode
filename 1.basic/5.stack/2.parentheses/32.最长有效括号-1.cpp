/*
 *   author:    zhouyuhao
 *   created:   2025-03-01 23:30:54
 *   modified:  2025-03-02 09:49:04
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
        stack<int> stk;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(') {
                stk.emplace(i); // index
            } else if (!stk.empty()) {
                s[stk.top()] = s[i] = '*'; // mark open and close if valid
                stk.pop();
            }
        }
        int res = 0, cnt = 0; // longest continuous substring of valid
        for (char ch : s) {
            if (ch == '*') {
                cnt++;
            } else {
                res = max(res, cnt);
                cnt = 0; // reset
            }
        }
        return max(cnt, res);
    }
};
// @lc code=end
