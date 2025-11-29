/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 10:07:16
 *   modified:  2025-11-14 11:52:11
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
        int res = 0, bound = INT_MAX; // the lower one of bound
        int lo = 0, hi = height.size() - 1;
        while (lo < hi) {
            // move the lower one until higher
            if (height[lo] < height[hi]) {
                bound = height[lo];
                res = max(res, bound * (hi - lo));
                while (lo < hi && height[lo] <= bound) lo++;
            } else {
                bound = height[hi];
                res = max(res, bound * (hi - lo));
                while (lo < hi && height[hi] <= bound) hi--;
            }
        }
        return res;
    }
};
// @lc code=end
