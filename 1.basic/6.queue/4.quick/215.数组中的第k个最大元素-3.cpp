/*
 *   author:    zhouyuhao
 *   created:   2025-12-02 10:15:00
 *   modified:  2025-12-03 09:24:31
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
        ranges::nth_element(nums, nums.end() - k);
        return nums[nums.size() - k];
    }
};
// @lc code=end
