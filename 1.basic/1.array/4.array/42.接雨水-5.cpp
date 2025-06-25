/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 10:07:16
 *   modified:  2025-06-21 22:20:24
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
        int res = 0, boundary = 0;
        int lo = 0, hi = height.size() - 1;
        while (lo < hi) {
            int lower = height[lo] < height[hi] ? height[lo++] : height[hi--];
            boundary = max(boundary, lower);
            res += boundary - lower;
        }
        return res;
    }
};
// @lc code=end
