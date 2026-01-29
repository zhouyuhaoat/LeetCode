/*
 *   author:    zhouyuhao
 *   created:   2025-12-22 10:56:45
 *   modified:  2026-01-28 20:29:32
 *   project:   LeetCode of 0x3f
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int hi = 0; hi < (int)nums.size(); hi++) {
            for (int lo = 0; lo < hi; lo++) {
                if (nums[lo] + nums[hi] == target) { // combinations: lo, hi
                    return {lo, hi};
                }
            }
        }
        return {};
    }
};
// @lc code=end
