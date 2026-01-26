/*
 *   author:    zhouyuhao
 *   created:   2025-02-12 23:01:03
 *   modified:  2026-01-25 23:25:52
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
        vector<int> idx(128, -1); // previous
        for (int lo = 0, hi = 0; hi < (int)s.size(); hi++) { // [lo, hi]
            if (idx[s[hi]] >= lo) { // repeat
                lo = idx[s[hi]] + 1;
            }
            res = max(res, hi - lo + 1);
            idx[s[hi]] = hi;
        }
        return res;
    }
};
// @lc code=end
