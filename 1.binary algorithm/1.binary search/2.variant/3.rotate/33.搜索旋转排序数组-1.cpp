/*
 *   author:    zhouyuhao
 *   created:   2025-12-16 16:10:59
 *   modified:  2026-01-25 11:07:41
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
private:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size();
        auto it = ranges::partition_point(views::iota(lo, hi), [&](int mi) {
            return nums[mi] > nums.back();
        });
        return *it;
    }

public:
    int search(vector<int>& nums, int target) {
        int lo = 0, mi = findMin(nums), hi = nums.size();
        target > nums.back() ? hi = mi : lo = mi; // left segment > right segment
        int idx = lower_bound(nums.begin() + lo, nums.begin() + hi - 1, target) - nums.begin();
        return nums[idx] == target ? idx : -1;
    }
};
// @lc code=end
