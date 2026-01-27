/*
 *   author:    zhouyuhao
 *   created:   2025-12-26 12:35:21
 *   modified:  2025-12-27 16:30:29
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
        int res = 0;
        ranges::sort(nums);
        for (int lo = 0, hi = 0; hi < (int)nums.size(); hi++) { // [lo, hi]
            while (nums[hi] > (long long)nums[lo] * k) {
                lo++;
            }
            res = max(res, hi - lo + 1);
        }
        return (int)nums.size() - res;
    }
};
// @lc code=end
