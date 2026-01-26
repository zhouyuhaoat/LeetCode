/*
 *   author:    zhouyuhao
 *   created:   2025-12-16 16:10:59
 *   modified:  2026-01-25 10:52:00
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
        // [0, lo): left of target (exclusive); [hi, size): right of target (inclusive)
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (target > nums.back() && nums[mi] <= nums.back()) { // different segment
                hi = mi;
            } else if (nums[mi] > nums.back() && target <= nums.back()) {
                lo = mi + 1;
            } else { // same segment
                if (nums[mi] >= target) {
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
