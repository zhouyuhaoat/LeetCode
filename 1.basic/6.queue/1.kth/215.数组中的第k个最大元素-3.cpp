/*
 *   author:    zhouyuhao
 *   created:   2024-12-12 10:25:39
 *   modified:  2025-03-01 20:23:24
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + (nums.size() - k), nums.end());
        return nums[nums.size() - k];
    }
};
// @lc code=end
