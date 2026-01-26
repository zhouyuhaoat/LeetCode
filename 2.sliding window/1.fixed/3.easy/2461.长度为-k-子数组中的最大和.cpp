/*
 *   author:    zhouyuhao
 *   created:   2025-12-25 23:45:25
 *   modified:  2025-12-26 11:58:09
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=2461 lang=cpp
 *
 * [2461] 长度为 K 子数组中的最大和
 */

// @lc code=start
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = 0, sum = 0;
        unordered_map<int, int> cnt; // freq
        for (int hi = 0; hi < (int)nums.size(); hi++) { // [lo, hi]
            sum += nums[hi];
            cnt[nums[hi]]++;
            int lo = hi - k + 1;
            if (lo >= 0) {
                if ((int)cnt.size() == k) {
                    res = max(res, sum);
                }
                sum -= nums[lo];
                if (--cnt[nums[lo]] == 0) {
                    cnt.erase(nums[lo]);
                }
            }
        }
        return res;
    }
};
// @lc code=end
