/*
 *   author:    zhouyuhao
 *   created:   2025-02-18 17:38:56
 *   modified:  2025-06-17 22:08:52
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return ranges::unique(nums).begin() - nums.begin();
    }
};
// @lc code=end
