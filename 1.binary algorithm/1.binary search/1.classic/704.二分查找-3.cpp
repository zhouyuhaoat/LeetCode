/*
 *   author:    zhouyuhao
 *   created:   2025-01-27 20:43:32
 *   modified:  2025-12-25 19:15:09
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
        int idx = lower_bound(nums.begin(), nums.end() - 1, target) - nums.begin();
        return nums[idx] == target ? idx : -1; // bound the index in the range
    }
};
// @lc code=end
