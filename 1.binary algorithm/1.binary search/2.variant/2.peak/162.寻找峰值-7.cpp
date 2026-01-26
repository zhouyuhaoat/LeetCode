/*
 *   author:    zhouyuhao
 *   created:   2025-12-16 15:53:58
 *   modified:  2026-01-24 16:38:47
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
        int lo = 0, hi = nums.size() - 1;
        auto it = ranges::partition_point(views::iota(lo, hi), [&](int mi) {
            return nums[mi] < nums[mi + 1]; // first false
        });
        return *it;
    }
};
// @lc code=end
