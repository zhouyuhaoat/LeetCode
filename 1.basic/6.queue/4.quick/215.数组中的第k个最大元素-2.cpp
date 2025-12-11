/*
 *   author:    zhouyuhao
 *   created:   2025-12-02 10:15:00
 *   modified:  2025-12-03 09:30:20
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
        ranges::nth_element(nums, nums.begin() + (k - 1), greater<int>());
        return nums[k - 1];
    }
};
// @lc code=end
