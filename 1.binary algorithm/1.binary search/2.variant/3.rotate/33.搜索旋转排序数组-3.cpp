/*
 *   author:    zhouyuhao
 *   created:   2025-12-16 16:10:59
 *   modified:  2026-01-25 23:02:49
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size();
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (nums[mi] > nums.back()) {
                if (target > nums.back() && nums[mi] >= target) { // is right
                    hi = mi;
                } else {
                    lo = mi + 1;
                }
            } else {
                if (target > nums.back() || (target <= nums.back() && nums[mi] >= target)) { // is right
                    hi = mi;
                } else {
                    lo = mi + 1;
                }
            }
        }
        return nums[hi] == target ? hi : -1;
    }
};
// @lc code=end
