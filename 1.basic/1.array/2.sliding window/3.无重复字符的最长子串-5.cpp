/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-12 23:01:03
 * 	 modified: 	2025-02-16 13:49:05
 * 	 project: 	LeetCode of labuladong
 * 	 venue: 	226, Harbin
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
        vector<int> pre(128, -1);
        // without repeating chars => previous char outside/before the substring
        // pre: previous index of each char; -1: never appear
        for (int lo = 0, hi = 0; hi < (int)s.size(); hi++) { // [lo, hi]
            // i.e. "abba", pre['a'] = 0, lo = 2
            if (pre[s[hi]] >= lo) {
                lo = pre[s[hi]] + 1; // as long as possible
                // next char possibly be the start of the substring
            } // lo = max(lo, pre[s[hi]] + 1);
            res = max(res, hi - lo + 1);
            pre[s[hi]] = hi;
        }
        return res;
    }
};
// @lc code=end
