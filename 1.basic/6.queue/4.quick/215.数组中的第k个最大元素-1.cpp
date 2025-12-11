/*
 *   author:    zhouyuhao
 *   created:   2024-12-10 22:04:27
 *   modified:  2025-12-03 09:28:50
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
        nth_element(nums.begin(), nums.begin() + (k - 1), nums.end(), greater<int>());
        return nums[k - 1];
    }
};
// @lc code=end
