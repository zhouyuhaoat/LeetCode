/*
 *   author:    zhouyuhao
 *   created:   2025-12-16 15:53:58
 *   modified:  2026-01-24 16:37:49
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
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (nums[mi] > nums[mi + 1]) { // first nums[i] > nums[i + 1]
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return hi;
    }
};
// @lc code=end
