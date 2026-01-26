/*
 *   author:    zhouyuhao
 *   created:   2025-12-26 12:37:56
 *   modified:  2025-12-27 18:10:31
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=2958 lang=cpp
 *
 * [2958] 最多 K 个重复元素的最长子数组
 */

// @lc code=start
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> cnt;
        for (int lo = 0, hi = 0; hi < (int)nums.size(); hi++) { // [lo, hi]
            cnt[nums[hi]]++;
            while (cnt[nums[hi]] > k) {
                cnt[nums[lo++]]--;
            }
            res = max(res, hi - lo + 1);
        }
        return res;
    }
};
// @lc code=end
