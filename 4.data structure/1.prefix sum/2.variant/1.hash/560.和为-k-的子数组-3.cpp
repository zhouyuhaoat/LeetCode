/*
 *   author:    zhouyuhao
 *   created:   2025-12-22 14:59:46
 *   modified:  2026-01-28 22:29:50
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
        int res = 0, pref = 0;
        unordered_map<int, int> cnt;
        for (int hi : nums) {
            cnt[pref]++; // update for present
            pref += hi;
            int lo = pref - k;
            res += cnt.contains(lo) ? cnt[lo] : 0;
        }
        return res;
    }
};
// @lc code=end
