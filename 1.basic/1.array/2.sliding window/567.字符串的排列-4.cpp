/*
 *   author:    zhouyuhao
 *   created:   2025-02-12 23:01:03
 *   modified:  2025-05-22 18:53:59
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
        int diff = cnt.size() - ranges::count(cnt, 0);
        auto update = [&](char ch, int add) {
            if (cnt[ch] == 0) diff++;
            cnt[ch] += add;
            if (cnt[ch] == 0) diff--;
        };
        for (int hi = 0; hi < (int)s2.size(); hi++) {
            update(s2[hi], -1);
            int lo = hi - s1.size() + 1;
            if (lo >= 0) {
                if (diff == 0) return true;
                update(s2[lo], 1);
            }
        }
        return false;
    }
};
// @lc code=end
