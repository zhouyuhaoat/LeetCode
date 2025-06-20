/*
 *   author:    zhouyuhao
 *   created:   2025-02-18 17:56:04
 *   modified:  2025-06-19 16:09:53
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        for (int lo = 0, hi = nums.size() - 1, pos = hi; lo <= hi; pos--) {
            /*
                multiply
                1. twice: compare square values directly
                2. once: compare additive inverse of smaller and original value of larger indirectly since sorted
            */
            if (-nums[lo] > nums[hi]) {
                res[pos] = nums[lo] * nums[lo];
                lo++;
            } else {
                res[pos] = nums[hi] * nums[hi];
                hi--;
            }
        }
        return res;
    }
};
// @lc code=end
