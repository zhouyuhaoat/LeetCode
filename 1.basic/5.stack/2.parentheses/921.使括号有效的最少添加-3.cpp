/*
 *   author:    zhouyuhao
 *   created:   2025-01-19 12:01:19
 *   modified:  2025-03-01 23:14:20
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=921 lang=cpp
 *
 * [921] 使括号有效的最少添加
 */

// @lc code=start
class Solution {
public:
    int minAddToMakeValid(string s) {
        // bf: balance factor between left (+1) and right (-1)
        int ins = 0, bf = 0;
        for (char& c : s) {
            bf += c == '(' ? 1 : -1;
            if (bf < 0) { // unbalanced: right > left
                // add left to balance right
                bf++;
                ins++;
            }
        }
        ins += bf; // add right to balance unpaired left
        return ins;
    }
};
// @lc code=end
