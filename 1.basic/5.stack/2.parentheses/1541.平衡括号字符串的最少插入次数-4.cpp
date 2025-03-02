/*
 *   author:    zhouyuhao
 *   created:   2025-01-19 12:12:36
 *   modified:  2025-03-01 23:16:04
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
        // bf: balance factor between left (+2) and right (-1)
        int ins = 0, bf = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(') {
                bf += 2;
            } else {
                bf -= 1;
                if (i + 1 < (int)s.size() && s[i + 1] == ')') {
                    bf -= 1;
                    i++;
                } else {
                    bf -= 1;
                    ins++;
                }
            }
            if (bf < 0) { // unbalanced: right > 2 * left
                // add left to balance right
                bf += 2;
                ins++;
            }
        }
        ins += bf; // add right to balance unpaired left
        return ins;
    }
};
// @lc code=end
