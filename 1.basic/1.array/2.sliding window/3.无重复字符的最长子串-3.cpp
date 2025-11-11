/*
 *   author:    zhouyuhao
 *   created:   2025-02-12 23:01:03
 *   modified:  2025-05-22 18:49:41
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
        unordered_map<char, bool> win; // set -> map
        for (int lo = 0, hi = 0; hi < (int)s.size(); lo++) {
            while (hi < (int)s.size() && win[s[hi]] == false) {
                win[s[hi++]] = true;
            }
            res = max(res, hi - lo);
            win[s[lo]] = false;
        }
        return res;
    }
};
// @lc code=end
