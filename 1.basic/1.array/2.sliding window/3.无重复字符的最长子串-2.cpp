/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-12 23:01:03
 * 	 modified: 	2025-02-15 21:26:24
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
        unordered_set<char> w;
        for (int lo = 0, hi = 0; hi < (int)s.size(); hi++) { // [lo, hi]
            while (w.contains(s[hi])) {
                w.erase(s[lo++]);
            }
            res = max(res, hi - lo + 1);
            w.emplace(s[hi]);
        }
        return res;
    }
};
// @lc code=end
