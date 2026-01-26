/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 23:17:33
 *   modified:  2025-05-22 18:52:54
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res, cnt(128);
        for (char ch : p) {
            cnt[ch]++;
        }
        int cover = 0;
        auto update = [&](char ch, int delta) {
            if (cnt[ch] > 0 && delta == -1) cover++;
            cnt[ch] += delta;
            if (cnt[ch] > 0 && delta == 1) cover--;
        };
        for (int lo = 0, hi = 0; hi < (int)s.size(); hi++) { // [lo, hi]
            update(s[hi], -1);
            while (cover == (int)p.size()) {
                if (hi - lo + 1 == (int)p.size()) {
                    res.push_back(lo);
                }
                update(s[lo++], 1);
            }
        }
        return res;
    }
};
// @lc code=end
