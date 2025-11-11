/*
 *   author:    zhouyuhao
 *   created:   2025-02-12 23:01:03
 *   modified:  2025-05-22 18:49:30
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
        unordered_set<char> win;
        for (int lo = 0, hi = 0; hi < (int)s.size(); hi++) { // [lo, hi]
            while (win.contains(s[hi])) {
                win.erase(s[lo++]);
            }
            res = max(res, hi - lo + 1);
            win.emplace(s[hi]); // defer
        }
        return res;
    }
};
// @lc code=end
