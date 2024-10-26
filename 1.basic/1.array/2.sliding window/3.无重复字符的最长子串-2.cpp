/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-25 20:14:15
 * 	 modified: 	2024-10-25 20:23:59
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
        int res = 0, h = -1; // head of substring
        // if h = 0, bug when the string only with single char
        vector<int> p(128, -1); // position
        for (int i = 0; i < (int)s.size(); i++) {
            if (p[s[i]] > h) { // the repeat char -> the substring
                h = p[s[i]]; // the previous char
            }
            res = max(res, i - h); // substring: [previous, current)
            p[s[i]] = i; // the current char
        }
        return res;
    }
};
// @lc code=end
