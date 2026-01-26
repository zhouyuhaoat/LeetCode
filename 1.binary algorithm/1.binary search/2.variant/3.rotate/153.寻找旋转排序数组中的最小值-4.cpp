/*
 *   author:    zhouyuhao
 *   created:   2025-12-16 16:00:28
 *   modified:  2026-01-24 20:39:32
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
        int lo = 0, hi = nums.size();
        while (lo < hi) { // [hi, size) <= back < [0, lo)
            int mi = lo + (hi - lo) / 2;
            if (nums[mi] <= nums.back()) { // first <= back
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return nums[hi]; // [hi, size) must not be empty
    }
};
// @lc code=end
