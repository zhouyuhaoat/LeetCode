/*
 *   author:    zhouyuhao
 *   created:   2025-12-26 12:15:52
 *   modified:  2025-12-26 12:40:26
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=3090 lang=cpp
 *
 * [3090] 每个字符最多出现两次的最长子字符串
 */

// @lc code=start
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int res = 0, k = 2;
        unordered_map<char, int> cnt;
        for (int lo = 0, hi = 0; hi < (int)s.size(); lo++) { // [lo, hi)
            while (hi < (int)s.size() && cnt[s[hi]] < k) {
                cnt[s[hi++]]++;
            }
            res = max(res, hi - lo);
            cnt[s[lo]]--;
        }
        return res;
    }
};
// @lc code=end
