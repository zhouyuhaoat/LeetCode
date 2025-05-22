/*
 *   author:    zhouyuhao
 *   created:   2025-01-22 23:15:11
 *   modified:  2025-05-22 12:53:18
 *   project:   LeetCode of labuladong
 *   venue:     Nanjing
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
        auto [first, last] = ranges::equal_range(nums, target); // [first, last)
        return first < last
                   ? vector<int>{static_cast<int>(first - nums.begin()), static_cast<int>(last - nums.begin() - 1)}
                   : vector<int>{-1, -1};
    }
};
// @lc code=end
