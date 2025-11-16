/*
 *   author:    zhouyuhao
 *   created:   2025-02-12 23:01:03
 *   modified:  2025-05-22 18:51:11
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
        /*
            cover: monitor the number of covered chars
            - cover a char: have < need, before in, after out
            - cover: have >= need for all => cover == size
         */
        for (int lo = 0, hi = 0; lo < (int)s.size(); lo++) {
            while (hi < (int)s.size() && cover < (int)t.size()) {
                if (win[s[hi]]++ < tar[s[hi]]) { // have < need before in
                    cover++;
                }
                hi++;
            }
            if (cover == (int)t.size() && hi - lo < len) {
                len = hi - lo;
                res = lo;
            }
            if (--win[s[lo]] < tar[s[lo]]) { // have < need after out
                cover--;
            }
        }
        return res == -1 ? string() : s.substr(res, len);
    }
};
// @lc code=end
