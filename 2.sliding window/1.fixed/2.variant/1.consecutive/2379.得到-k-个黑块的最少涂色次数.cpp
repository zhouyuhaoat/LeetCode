/*
 *   author:    zhouyuhao
 *   created:   2025-12-25 23:33:50
 *   modified:  2025-12-25 23:39:43
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=2379 lang=cpp
 *
 * [2379] 得到 K 个黑块的最少涂色次数
 */

// @lc code=start
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int res = INT_MAX, cnt = 0;
        for (int hi = 0; hi < (int)blocks.size(); hi++) { // [lo, hi]
            cnt += blocks[hi] == 'W';
            int lo = hi - k + 1;
            if (lo >= 0) {
                res = min(res, cnt);
                cnt -= blocks[lo] == 'W';
            }
        }
        return res;
    }
};
// @lc code=end
