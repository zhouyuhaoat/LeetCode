/*
 *   author:    zhouyuhao
 *   created:   2026-01-25 11:00:22
 *   modified:  2026-01-25 11:04:31
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
        auto it = ranges::partition_point(views::iota(lo, hi), [&](int mi) {
            return nums[mi] >= nums.back();
        });
        return nums[*it];
    }
};
// @lc code=end
