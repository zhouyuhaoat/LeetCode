/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 09:52:02
 *   modified:  2025-06-19 15:44:31
 *   project:   LeetCode of labuladong
 *   venue:     226, Harbin
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
        for (int lo = 0, hi = nums.size() - 1, pos = hi; lo <= hi; pos--) { // reverse merge
            int power1 = nums[lo] * nums[lo], power2 = nums[hi] * nums[hi];
            if (power1 > power2) {
                res[pos] = power1;
                lo++;
            } else {
                res[pos] = power2;
                hi--;
            }
        }
        return res;
    }
};
// @lc code=end
