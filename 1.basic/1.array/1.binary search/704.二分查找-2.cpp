/*
 *   author:    zhouyuhao
 *   created:   2025-01-27 20:43:32
 *   modified:  2025-05-21 20:45:09
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
        if (ranges::binary_search(nums, target)) {
            return distance(nums.begin(), ranges::lower_bound(nums, target));
        } else {
            return -1;
        }
    }
};
// @lc code=end
