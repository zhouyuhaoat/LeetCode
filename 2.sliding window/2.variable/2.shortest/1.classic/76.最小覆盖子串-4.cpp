/*
 *   author:    zhouyuhao
 *   created:   2025-02-12 23:01:03
 *   modified:  2025-05-22 18:51:43
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
        vector<int> cnt(128);
        for (char ch : t) {
            cnt[ch]++;
        }
        int res = -1, len = INT_MAX, cover = 0;
        auto update = [&](char ch, int delta) {
            if (cnt[ch] > 0 && delta == -1) cover++; // before in
            cnt[ch] += delta;
            if (cnt[ch] > 0 && delta == 1) cover--; // after out
        };
        for (int lo = 0, hi = 0; hi < (int)s.size(); hi++) { // [lo, hi]
            update(s[hi], -1);
            while (cover == (int)t.size()) {
                if (hi - lo + 1 < len) {
                    len = hi - lo + 1;
                    res = lo;
                }
                update(s[lo++], 1);
            }
        }
        return res == -1 ? string() : s.substr(res, len);
    }
};
// @lc code=end
