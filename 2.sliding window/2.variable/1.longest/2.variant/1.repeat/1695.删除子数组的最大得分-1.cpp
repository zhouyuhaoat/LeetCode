/*
 *   author:    zhouyuhao
 *   created:   2025-12-27 16:45:14
 *   modified:  2025-12-27 23:40:40
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=1695 lang=cpp
 *
 * [1695] 删除子数组的最大得分
 */

// @lc code=start
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = 0, sum = 0, k = 1;
        unordered_map<int, int> cnt;
        for (int lo = 0, hi = 0; hi < (int)nums.size(); lo++) { // [lo, hi)
            while (hi < (int)nums.size() && cnt[nums[hi]] < k) {
                sum += nums[hi];
                cnt[nums[hi++]]++;
            }
            res = max(res, sum);
            sum -= nums[lo];
            cnt[nums[lo]]--;
        }
        return res;
    }
};
// @lc code=end
