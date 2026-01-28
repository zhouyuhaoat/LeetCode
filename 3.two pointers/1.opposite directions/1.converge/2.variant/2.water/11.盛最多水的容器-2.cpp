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
            if (height[lo] < height[hi]) {
                res = max(res, height[lo] * (hi - lo));
                lo++;
            } else {
                res = max(res, height[hi] * (hi - lo));
                hi--;
            }
        }
        return res;
    }
};
// @lc code=end
