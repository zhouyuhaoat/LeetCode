/*
 *   author:    zhouyuhao
 *   created:   2025-02-12 23:01:03
 *   modified:  2025-05-22 18:51:22
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> win, tar;
        for (char ch : t) {
            tar[ch]++;
        }
        int res = -1, len = INT_MAX, cover = 0;
        for (int lo = 0, hi = 0; hi < (int)s.size(); hi++) { // [lo, hi]
            if (win[s[hi]]++ < tar[s[hi]]) {
                cover++;
            }
            while (cover == (int)t.size()) {
                if (hi - lo + 1 < len) {
                    len = hi - lo + 1;
                    res = lo;
                }
                if (--win[s[lo]] < tar[s[lo]]) {
                    cover--;
                }
                lo++;
            }
        }
        return res == -1 ? string() : s.substr(res, len);
    }
};
// @lc code=end
