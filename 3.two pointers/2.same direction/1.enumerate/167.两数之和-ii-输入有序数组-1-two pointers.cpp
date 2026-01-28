/*
 *   author:    zhouyuhao
 *   created:   2025-12-16 10:49:20
 *   modified:  2025-12-22 22:47:13
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
        for (int lo = 0; lo < (int)nums.size(); lo++) { // fix lo, move hi
            int hi = lower_bound(nums.begin() + lo + 1, nums.end(), target - nums[lo]) - nums.begin();
            if (hi < (int)nums.size() && nums[hi] == target - nums[lo]) {
                return {lo + 1, hi + 1};
            }
        }
        return {-1, -1};
    }
};
// @lc code=end
