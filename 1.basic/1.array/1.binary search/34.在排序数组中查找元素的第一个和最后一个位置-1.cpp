/*
 *   author:    zhouyuhao
 *   created:   2025-01-22 23:08:01
 *   modified:  2025-05-22 12:55:42
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
        int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        if (first <= last) { // valid range
            return {first, last}; // [first, last]
        } else {
            return {-1, -1};
        }
    }
};
// @lc code=end
