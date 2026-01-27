/*
 *   author:    zhouyuhao
 *   created:   2025-12-26 12:35:21
 *   modified:  2025-12-27 16:31:17
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=3634 lang=cpp
 *
 * [3634] 使数组平衡的最少移除数目
 */

// @lc code=start
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        ranges::sort(nums); // for max and min in sorted window
        for (int lo = 0, hi = 0; hi < n; lo++) { // [lo, hi)
            while (hi < n && nums[hi] <= (long long)nums[lo] * k) {
                hi++;
            }
            res = max(res, hi - lo);
        }
        return n - res; // reverse
    }
};
// @lc code=end
