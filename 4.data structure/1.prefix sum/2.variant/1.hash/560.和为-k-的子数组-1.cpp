/*
 *   author:    zhouyuhao
 *   created:   2025-12-22 14:59:46
 *   modified:  2026-01-28 22:26:38
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
        vector<int> pref(nums.size() + 1);
        partial_sum(nums.begin(), nums.end(), pref.begin() + 1);
        unordered_map<int, int> cnt; // hash for look back
        for (int hi : pref) {
            int lo = hi - k;
            res += cnt.contains(lo) ? cnt[lo] : 0;
            cnt[hi]++; // update for future
        }
        return res;
    }
};
// @lc code=end
