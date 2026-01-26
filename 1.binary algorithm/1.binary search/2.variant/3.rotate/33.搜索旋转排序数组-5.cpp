/*
 *   author:    zhouyuhao
 *   created:   2025-12-16 16:10:59
 *   modified:  2026-01-25 11:10:14
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
        auto isRight = [&](int mi) {
            if (nums[mi] > nums.back()) {
                return target > nums.back() && nums[mi] >= target;
            } else {
                return target > nums.back() || nums[mi] >= target;
            }
        };

        int lo = 0, hi = nums.size();
        auto it = ranges::partition_point(views::iota(lo, hi), [&](int mi) {
            return !isRight(mi);
        });
        return nums[*it] == target ? *it : -1;
    }
};
// @lc code=end
