/*
 *   author:    zhouyuhao
 *   created:   2025-12-16 16:00:28
 *   modified:  2026-01-24 22:39:37
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) { // [hi, size - 1) < back < [0, lo)
            int mi = lo + (hi - lo) / 2;
            if (nums[mi] < nums.back()) { // first < back
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return nums[hi]; // even [hi, size - 1) is empty
    }
};
// @lc code=end
