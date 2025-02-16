/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-13 23:17:33
 * 	 modified: 	2025-02-16 10:17:00
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
        vector<int> res, cnt(26);
        for (char c : p) {
            cnt[c - 'a']++;
        }
        int want = p.size();
        for (int lo = 0, hi = 0; hi < (int)s.size(); hi++) { // [lo, hi]
            if (cnt[s[hi] - 'a']-- > 0) {
                want--;
            }
            while (want == 0) {
                if (hi - lo + 1 == (int)p.size()) {
                    res.emplace_back(lo);
                }
                if (++cnt[s[lo++] - 'a'] > 0) {
                    want++;
                }
            }
        }
        return res;
    }
};
// @lc code=end
