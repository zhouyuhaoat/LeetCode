/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 10:07:16
 *   modified:  2025-11-14 11:52:26
 *   project:   LeetCode of labuladong
 *   venue:     226, Harbin
 */

/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, bound = 0; // the lower one of bound
        int lo = 0, hi = height.size() - 1;
        while (lo < hi) {
            int base = height[lo] < height[hi] ? height[lo++] : height[hi--]; // the lower one of height
            res += max(0, bound - base);
            bound = max(bound, base); // update for future
        }
        return res;
    }
};
// @lc code=end
