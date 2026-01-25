/*
 *   author:    zhouyuhao
 *   created:   2025-12-25 10:11:58
 *   modified:  2025-12-25 19:16:56
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=2529 lang=cpp
 *
 * [2529] 正整数和负整数的最大计数
 */

// @lc code=start
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto [first, last] = ranges::equal_range(nums, 0);
        int pos = nums.end() - last, neg = first - nums.begin();
        return max(pos, neg);
    }
};
// @lc code=end
