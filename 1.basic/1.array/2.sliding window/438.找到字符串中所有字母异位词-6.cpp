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
        for (int lo = 0, hi = 0; hi < (int)s.size(); hi++) { // [lo, hi]
            if (cnt[s[hi]]-- > 0) {
                cover++;
            }
            while (cover == (int)p.size()) {
                if (hi - lo + 1 == (int)p.size()) {
                    res.emplace_back(lo);
                }
                if (++cnt[s[lo]] > 0) {
                    cover--;
                }
                lo++;
            }
        }
        return res;
    }
};
// @lc code=end
