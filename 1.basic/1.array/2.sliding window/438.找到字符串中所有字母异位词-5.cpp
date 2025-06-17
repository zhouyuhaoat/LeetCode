/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 23:17:33
 *   modified:  2025-05-22 18:52:44
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
        /*
            anagram: have = need; cover: have >= need
            anagram is a special case of cover, cover is a general case of anagram
            cover + same length => cover each char a time => just right => anagrams
        */
        vector<int> res, cnt(26);
        for (char ch : p) {
            cnt[ch - 'a']++;
        }
        int cover = 0;
        for (int lo = 0, hi = 0; lo < (int)s.size(); lo++) { // [lo, hi)
            while (hi < (int)s.size() && cover < (int)p.size()) {
                if (cnt[s[hi] - 'a']-- > 0) {
                    cover++;
                }
                hi++;
            }
            if (cover == (int)p.size() && hi - lo == (int)p.size()) {
                res.emplace_back(lo);
            }
            if (++cnt[s[lo] - 'a'] > 0) {
                cover--;
            }
        }
        return res;
    }
};
// @lc code=end
