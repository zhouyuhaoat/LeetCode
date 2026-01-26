/*
 *   author:    zhouyuhao
 *   created:   2025-02-12 23:01:03
 *   modified:  2025-05-22 18:50:19
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
        vector<int> idx(128, -1);
        for (int lo = -1, hi = 0; hi < (int)s.size(); hi++) { // (lo, hi] = [lo + 1, hi]
            lo = max(lo, idx[s[hi]]);
            res = max(res, hi - lo);
            idx[s[hi]] = hi;
        }
        return res;
    }
};
// @lc code=end
