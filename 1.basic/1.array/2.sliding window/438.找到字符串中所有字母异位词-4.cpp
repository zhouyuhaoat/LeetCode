/*
 *   author:    zhouyuhao
 *   created:   2025-02-12 23:01:03
 *   modified:  2025-05-22 18:52:32
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
        vector<int> res, cnt(26);
        for (char ch : p) {
            cnt[ch - 'a']++;
        }
        int diff = cnt.size() - ranges::count(cnt, 0);
        auto update = [&](int ch, int add) {
            if (cnt[ch] == 0) diff++; // same before update -> different after update
            cnt[ch] += add;
            if (cnt[ch] == 0) diff--; // same after update
        };
        for (int hi = 0; hi < (int)s.size(); hi++) {
            update(s[hi] - 'a', -1);
            int lo = hi - (int)p.size() + 1;
            if (lo >= 0) {
                if (diff == 0) {
                    res.emplace_back(lo);
                }
                update(s[lo] - 'a', 1);
            }
        }
        return res;
    }
};
// @lc code=end
