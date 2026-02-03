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
        int lo = 0, hi = nums.size() - 1, idx = hi;
        while (lo <= hi) {
            if (-nums[lo] < nums[hi]) { // additive inverse
                res[idx--] = nums[hi] * nums[hi--];
            } else {
                res[idx--] = nums[lo] * nums[lo++];
            }
        }
        return res;
    }
};
// @lc code=end
