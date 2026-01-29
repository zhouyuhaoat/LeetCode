/*
 *   author:    zhouyuhao
 *   created:   2025-12-16 10:49:20
 *   modified:  2026-01-28 20:29:46
 *   project:   LeetCode of 0x3f
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int hi = 0; hi < (int)nums.size(); hi++) {
            int lo = lower_bound(nums.begin(), nums.begin() + hi, target - nums[hi]) - nums.begin();
            if (lo < hi && nums[lo] + nums[hi] == target) { // combinations: lo, hi
                return {lo + 1, hi + 1};
            }
        }
        return {-1, -1};
    }
};
// @lc code=end
