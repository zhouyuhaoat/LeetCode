/*
 *   author:    zhouyuhao
 *   created:   2025-02-10 14:59:41
 *   modified:  2025-05-21 20:49:34
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return distance(nums.begin(), ranges::lower_bound(nums, target));
    }
};
// @lc code=end
