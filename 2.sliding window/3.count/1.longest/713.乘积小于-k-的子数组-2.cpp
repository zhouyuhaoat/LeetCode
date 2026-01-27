/*
 *   author:    zhouyuhao
 *   created:   2025-12-16 16:25:19
 *   modified:  2025-12-16 19:05:51
 *   project:   LeetCode of 0x3f
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int res = 0, prod = 1;
        for (int lo = 0, hi = 0; hi < (int)nums.size(); hi++) { // [lo, hi]
            prod *= nums[hi];
            while (prod >= k) {
                prod /= nums[lo++];
            }
            res += hi - lo + 1;
        }
        return res;
    }
};
// @lc code=end
