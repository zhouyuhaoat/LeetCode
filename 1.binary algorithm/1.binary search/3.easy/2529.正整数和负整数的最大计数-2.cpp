/*
 *   author:    zhouyuhao
 *   created:   2025-12-25 10:11:58
 *   modified:  2025-12-25 12:00:10
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
        int pos = 0, neg = 0;
        for (int num : nums) {
            if (num > 0) {
                pos++;
            } else if (num < 0) {
                neg++;
            }
        }
        return max(pos, neg);
    }
};
// @lc code=end
