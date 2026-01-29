/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:36:52
 *   modified:  2025-03-01 17:52:30
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=1541 lang=cpp
 *
 * [1541] 平衡括号字符串的最少插入次数
 */

// @lc code=start
class Solution {
public:
    int minInsertions(string s) {
        int res = 0;
        stack<char> stk;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(') {
                stk.push(s[i]);
            } else {
                if (stk.empty()) { // left
                    res++;
                } else {
                    stk.pop();
                }
                if (i + 1 < (int)s.size() && s[i + 1] == ')') { // another right
                    i++;
                } else {
                    res++;
                }
            }
        }
        res += (int)stk.size() * 2;
        return res;
    }
};
// @lc code=end
