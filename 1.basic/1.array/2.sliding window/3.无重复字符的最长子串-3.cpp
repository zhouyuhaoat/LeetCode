/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-12 23:01:03
 * 	 modified: 	2025-02-15 21:27:20
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
        for (int lo = 0, hi = 0; hi < (int)s.size(); lo++) { // [lo, hi)
            while (hi < (int)s.size() && w[s[hi]] == false) {
                w[s[hi++]] = true;
            }
            res = max(res, hi - lo);
            w[s[lo]] = false;
        }
        return res;
    }
};
// @lc code=end
