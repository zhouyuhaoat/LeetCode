/*
 *   author:    zhouyuhao
 *   created:   2025-02-12 23:01:03
 *   modified:  2025-05-22 18:54:19
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cnt(128);
        for (char ch : s1) {
            cnt[ch]++;
        }
        int cover = 0;
        auto update = [&](char ch, int delta) {
            if (cnt[ch] > 0 && delta == -1) cover++;
            cnt[ch] += delta;
            if (cnt[ch] > 0 && delta == 1) cover--;
        };
        for (int lo = 0, hi = 0; hi < (int)s2.size(); hi++) {
            update(s2[hi], -1);
            while (cover == (int)s1.size()) {
                if (hi - lo + 1 == (int)s1.size()) {
                    return true;
                }
                update(s2[lo++], 1);
            }
        }
        return false;
    }
};
// @lc code=end
