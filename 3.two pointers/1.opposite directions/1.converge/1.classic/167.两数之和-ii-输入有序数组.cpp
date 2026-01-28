/*
 *   author:    zhouyuhao
 *   created:   2025-12-16 10:44:44
 *   modified:  2025-12-16 10:54:55
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
        int lo = 0, hi = nums.size() - 1; // two sum
        while (lo < hi) {
            int sum = nums[lo] + nums[hi];
            if (sum > target) {
                hi--;
            } else if (sum < target) {
                lo++;
            } else {
                return {lo + 1, hi + 1};
            }
        }
        return {-1, -1};
    }
};
// @lc code=end
