/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 10:07:16
 *   modified:  2025-06-21 22:00:33
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
        int res = 0;
        for (int lo = 0, hi = height.size() - 1; lo < hi;) {
            int h = min(height[lo], height[hi]);
            res = max(res, h * (hi - lo));
            // move lower until both sides are higher
            while (lo < hi && height[lo] <= h) lo++;
            while (lo < hi && height[hi] <= h) hi--;
        }
        return res;
    }
};
// @lc code=end
