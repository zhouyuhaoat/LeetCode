/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 11:47:14
 *   modified:  2025-12-26 12:19:37
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_map<char, int> cnt;
        for (int lo = 0, hi = 0; hi < (int)s.size(); hi++) { // [lo, hi]
            cnt[s[hi]]++; // no defer
            while (cnt[s[hi]] > 1) {
                cnt[s[lo++]]--;
            }
            res = max(res, hi - lo + 1);
        }
        return res;
    }
};
// @lc code=end
