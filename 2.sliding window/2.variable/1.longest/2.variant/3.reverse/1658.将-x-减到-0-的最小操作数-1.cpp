/*
 *   author:    zhouyuhao
 *   created:   2025-12-27 17:02:31
 *   modified:  2025-12-28 18:58:44
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 *
 * [1658] 将 x 减到 0 的最小操作数
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = reduce(nums.begin(), nums.end()) - x, n = nums.size(); // reverse
        if (target < 0) return -1;
        if (target == 0) return n;
        int res = 0, sum = 0;
        for (int lo = 0, hi = 0; lo < n; lo++) { // [lo, hi)
            while (hi < n && sum < target) {
                sum += nums[hi++];
            }
            if (sum == target) {
                res = max(res, hi - lo);
            }
            sum -= nums[lo];
        }
        return res == 0 ? -1 : n - res;
    }
};
// @lc code=end
