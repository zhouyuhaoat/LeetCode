/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-25 20:12:40
 * 	 modified: 	2024-10-25 20:20:45
 * 	 project: 	LeetCode
 * 	 venue: 	914, Harbin
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
        unordered_set<char> w; // substring -> window
        for (int lo = 0, hi = 0; hi < (int)s.size(); lo++) {
            while (hi < (int)s.size() && w.count(s[hi]) == 0) { // sliding: right in
                w.emplace(s[hi++]);
            }
            res = max(res, hi - lo);
            w.erase(s[lo]); // sliding: left out
        }
        return res;
    }
};
// @lc code=end
