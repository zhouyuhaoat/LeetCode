/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:36:53
 *   modified:  2025-03-01 23:12:07
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
        /*
            stack: all same elements
            - all left parentheses
            - maintain the stack => update variable regarding the stack size
        */
        int ins = 0, left = 0;
        for (char ch : s) {
            if (ch == '(') {
                left++;
            } else {
                left > 0 ? left-- : ins++;
            }
        }
        ins += left;
        return ins;
    }
};
// @lc code=end
