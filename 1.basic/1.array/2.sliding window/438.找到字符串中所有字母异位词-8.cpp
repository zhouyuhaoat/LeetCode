/*
 *   author:    zhouyuhao
 *   created:   2025-02-12 23:01:03
 *   modified:  2025-05-22 18:53:14
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
        for (int lo = 0, hi = 0; hi < (int)s.size(); hi++) { // [lo, hi]
            cnt[s[hi] - 'a']--;
            while (cnt[s[hi] - 'a'] < 0) { // too many: have > need
                cnt[s[lo] - 'a']++;
                lo++;
            }
            // not too many: have <= need
            if (hi - lo + 1 == (int)p.size()) { // just right: have == need
                res.emplace_back(lo);
            }
        }
        return res;
    }
};
// @lc code=end
