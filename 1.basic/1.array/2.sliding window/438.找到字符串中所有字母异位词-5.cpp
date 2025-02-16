/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-13 23:17:33
 * 	 modified: 	2025-02-16 13:05:26
 * 	 project: 	LeetCode of labuladong
 * 	 venue: 	226, Harbin
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
        // each char in anagram either in or out, no multiple, no frequency, no redundant
        // each char in pattern is important, and need to be covered by substring
        // anagram: have = need; cover: have >= need
        // anagram is a special case of cover, cover is a general case of anagram
        // fixed-length sliding window -> variable-length sliding window
        // fixed-length + judge anagram by statistics -> cover + judge anagram by length
        vector<int> res, cnt(26);
        for (char c : p) {
            cnt[c - 'a']++;
        }
        int want = p.size();
        // want: monitor the number of covered chars
        // cover a char: have < need, before in, after out
        // cover: have >= need => want = 0
        // want = 0 + same length => cover each char a time => just right => anagrams
        for (int lo = 0, hi = 0; lo <= (int)s.size() - (int)p.size(); lo++) { // [lo, hi)
            while (hi < (int)s.size() && want > 0) {
                if (cnt[s[hi++] - 'a']-- > 0) {
                    want--;
                }
            }
            if (want == 0 && hi - lo == (int)p.size()) {
                res.emplace_back(lo);
            }
            if (++cnt[s[lo] - 'a'] > 0) {
                want++;
            }
        }
        return res;
    }
};
// @lc code=end
