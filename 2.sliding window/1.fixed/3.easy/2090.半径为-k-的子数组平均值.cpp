/*
 *   author:    zhouyuhao
 *   created:   2025-12-25 23:19:47
 *   modified:  2025-12-25 23:39:07
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=2090 lang=cpp
 *
 * [2090] 半径为 k 的子数组平均值
 */

// @lc code=start
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size(), len = 2 * k + 1;
        vector<int> res(n, -1);
        if (n < len) return res;
        long long sum = 0;
        for (int hi = 0; hi < n; hi++) { // [lo, hi]
            sum += nums[hi];
            int lo = hi - len + 1;
            if (lo >= 0) {
                res[hi - k] = sum / len; // mi
                sum -= nums[lo];
            }
        }
        return res;
    }
};
// @lc code=end
