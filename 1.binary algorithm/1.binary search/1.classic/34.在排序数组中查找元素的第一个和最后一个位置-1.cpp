/*
 *   author:    zhouyuhao
 *   created:   2025-01-20 22:16:41
 *   modified:  2025-12-28 12:34:49
 *   project:   LeetCode of labuladong
 *   venue:     226, Harbin
 */

/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = distance(nums.begin(), ranges::lower_bound(nums, target));
        if (first == (int)nums.size() || nums[first] != target) return {-1, -1}; // not found
        int last = distance(nums.begin(), ranges::upper_bound(nums, target));
        return {first, last - 1}; // [first, last) -> [first, last - 1]
    }
};
// @lc code=end
