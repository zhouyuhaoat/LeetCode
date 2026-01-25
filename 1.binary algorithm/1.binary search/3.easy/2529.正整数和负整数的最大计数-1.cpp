/*
 *   author:    zhouyuhao
 *   created:   2025-12-25 10:11:58
 *   modified:  2025-12-25 12:05:17
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
        int pos = ranges::count_if(nums, [](int num) { // positive
            return num > 0;
        });
        int neg = ranges::count_if(nums, [](int num) { // negative
            return num < 0;
        });
        return max(pos, neg);
    }
};
// @lc code=end
