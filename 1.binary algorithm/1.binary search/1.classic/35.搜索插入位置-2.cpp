/*
 *   author:    zhouyuhao
 *   created:   2025-02-10 14:59:41
 *   modified:  2025-12-25 19:13:27
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
        int idx = ranges::upper_bound(nums, target) - nums.begin(); // stability
        return idx > 0 && nums[idx - 1] == target ? idx - 1 : idx; // valid -> judge
    }
};
// @lc code=end
