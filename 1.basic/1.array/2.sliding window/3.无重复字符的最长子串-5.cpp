/*
 *   author:    zhouyuhao
 *   created:   2025-02-12 23:01:03
 *   modified:  2025-05-22 18:50:06
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
        vector<int> prev(128, -1);
        // repeat => previous char inside/after the substring
        // prev: previous index of the char; -1: never appear
        for (int lo = 0, hi = 0; hi < (int)s.size(); hi++) { // [lo, hi]
            if (prev[s[hi]] >= lo) {
                lo = prev[s[hi]] + 1; // lo: the start of the substring
            }
            res = max(res, hi - lo + 1);
            prev[s[hi]] = hi;
        }
        return res;
    }
};
// @lc code=end
