/*
 *   author:    zhouyuhao
 *   created:   2025-01-27 20:43:32
 *   modified:  2025-05-22 13:06:05
 *   project:   LeetCode of labuladong
 *   venue:     501, Shangrao
 */

/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int id = distance(nums.begin(), ranges::lower_bound(nums, target));
        return id < (int)nums.size() && nums[id] == target ? id : -1; // valid -> judge
    }
};
// @lc code=end
