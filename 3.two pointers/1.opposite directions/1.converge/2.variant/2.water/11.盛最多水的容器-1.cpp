/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 10:07:16
 *   modified:  2025-11-14 11:52:05
 *   project:   LeetCode of labuladong
 *   venue:     226, Harbin
 */

/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, lo = 0, hi = height.size() - 1;
        while (lo < hi) {
            int area = min(height[lo], height[hi]) * (hi - lo);
            res = max(res, area);
            height[lo] < height[hi] ? lo++ : hi--; // move the lower one (bottleneck)
        }
        return res;
    }
};
// @lc code=end
