/*
 *   author:    zhouyuhao
 *   created:   2025-01-27 20:43:32
 *   modified:  2025-12-25 19:14:15
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
        int idx = ranges::lower_bound(nums, target) - nums.begin();
        return idx < (int)nums.size() && nums[idx] == target ? idx : -1; // valid -> judge
    }
};
// @lc code=end
