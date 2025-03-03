/*
 *   author:    zhouyuhao
 *   created:   2025-03-02 15:55:30
 *   modified:  2025-03-02 15:56:32
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
        partial_sort(nums.begin(), nums.begin() + nums.size() - k + 1, nums.end());
        return nums[nums.size() - k];
    }
};
// @lc code=end
