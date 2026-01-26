/*
 *   author:    zhouyuhao
 *   created:   2025-12-16 15:53:58
 *   modified:  2026-01-24 17:25:47
 *   project:   LeetCode of 0x3f
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        auto it = ranges::adjacent_find(nums, greater<int>());
        return it == nums.end() ? (int)nums.size() - 1 : it - nums.begin();
    }
};
// @lc code=end
