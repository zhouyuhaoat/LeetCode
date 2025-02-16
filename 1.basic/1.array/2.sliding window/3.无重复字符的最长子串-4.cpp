/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-14 22:15:17
 * 	 modified: 	2025-02-15 21:27:27
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
        unordered_map<char, bool> w;
        for (int lo = 0, hi = 0; hi < (int)s.size(); hi++) { // [lo, hi]
            while (w[s[hi]] == true) {
                w[s[lo++]] = false;
            }
            res = max(res, hi - lo + 1);
            w[s[hi]] = true;
        }
        return res;
    }
};
// @lc code=end
