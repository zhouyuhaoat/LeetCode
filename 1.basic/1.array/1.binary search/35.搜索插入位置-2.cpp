/*
 *   author:    zhouyuhao
 *   created:   2025-02-10 14:59:41
 *   modified:  2025-05-22 13:04:30
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
        int id = distance(nums.begin(), ranges::upper_bound(nums, target));
        return id > 0 && nums[id - 1] == target ? id - 1 : id; // valid -> judge
    }
};
// @lc code=end
