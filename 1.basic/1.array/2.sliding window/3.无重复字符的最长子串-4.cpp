/*
 *   author:    zhouyuhao
 *   created:   2025-02-14 22:15:17
 *   modified:  2025-05-22 18:49:55
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
        unordered_map<char, bool> win;
        for (int lo = 0, hi = 0; hi < (int)s.size(); hi++) { // [lo, hi]
            while (win[s[hi]] == true) {
                win[s[lo++]] = false;
            }
            res = max(res, hi - lo + 1);
            win[s[hi]] = true;
        }
        return res;
    }
};
// @lc code=end
