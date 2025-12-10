/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:36:53
 *   modified:  2025-03-01 23:15:42
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
        int ins = 0, left = 0; // stack -> variable
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(') {
                left++;
            } else {
                left > 0 ? left-- : ins++;
                if (i + 1 < (int)s.size() && s[i + 1] == ')') {
                    i++;
                } else {
                    ins++;
                }
            }
        }
        ins += left * 2;
        return ins;
    }
};
// @lc code=end
