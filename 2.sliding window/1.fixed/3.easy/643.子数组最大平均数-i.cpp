/*
 *   author:    zhouyuhao
 *   created:   2025-12-25 19:57:04
 *   modified:  2025-12-25 20:06:46
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int res = INT_MIN, sum = 0;
        for (int hi = 0; hi < (int)nums.size(); hi++) { // [lo, hi]
            sum += nums[hi];
            int lo = hi - k + 1;
            if (lo >= 0) {
                res = max(res, sum);
                sum -= nums[lo];
            }
        }
        return (double)res / k;
    }
};
// @lc code=end
