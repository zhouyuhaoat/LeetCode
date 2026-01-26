/*
 *   author:    zhouyuhao
 *   created:   2025-12-25 23:41:50
 *   modified:  2025-12-26 11:55:13
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=2841 lang=cpp
 *
 * [2841] 几乎唯一子数组的最大和
 */

// @lc code=start
class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long res = 0, sum = 0;
        unordered_map<int, int> cnt; // freq
        for (int hi = 0; hi < (int)nums.size(); hi++) { // [lo, hi]
            sum += nums[hi];
            cnt[nums[hi]]++;
            int lo = hi - k + 1;
            if (lo >= 0) {
                if ((int)cnt.size() >= m) {
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
