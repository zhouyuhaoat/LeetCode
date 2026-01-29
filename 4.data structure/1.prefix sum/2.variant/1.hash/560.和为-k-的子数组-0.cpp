/*
 *   author:    zhouyuhao
 *   created:   2025-12-22 14:59:46
 *   modified:  2025-12-22 19:24:18
 *   project:   LeetCode of 0x3f
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        vector<int> pref(nums.size() + 1); // range query
        partial_sum(nums.begin(), nums.end(), pref.begin() + 1);
        for (int hi = 0; hi < (int)pref.size(); hi++) { // fix hi, move lo
            for (int lo = 0; lo < hi; lo++) {
                if (pref[hi] - pref[lo] == k) { // combinations: [lo, hi)
                    res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end
