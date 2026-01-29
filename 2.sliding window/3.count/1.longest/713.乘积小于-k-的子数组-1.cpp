/*
 *   author:    zhouyuhao
 *   created:   2025-12-16 16:25:19
 *   modified:  2026-01-27 23:13:01
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
        for (int lo = 0, hi = 0; lo < (int)nums.size(); lo++) { // [lo, hi)
            while (hi < (int)nums.size() && prod < k) {
                prod *= nums[hi++];
            }
            res += prod < k ? hi - lo : hi - lo - 1;
            prod /= nums[lo];
        }
        return res;
    }
};
// @lc code=end
