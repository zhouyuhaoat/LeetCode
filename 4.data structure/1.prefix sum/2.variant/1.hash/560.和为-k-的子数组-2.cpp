/*
 *   author:    zhouyuhao
 *   created:   2025-12-22 14:59:46
 *   modified:  2025-12-22 23:04:02
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
        int res = 0, pref = 0; // on the fly
        unordered_map<int, int> cnt = {{0, 1}}; // sentinel
        for (int hi : nums) {
            pref += hi; // exclusive -> inclusive
            int lo = pref - k;
            res += cnt.contains(lo) ? cnt[lo] : 0;
            cnt[pref]++;
        }
        return res;
    }
};
// @lc code=end
