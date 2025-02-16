/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-12 23:01:03
 * 	 modified: 	2025-02-16 13:31:54
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
        for (int lo = 0, hi = 0; lo <= (int)s.size() - (int)p.size(); lo++) { // [lo, hi)
            while (hi < (int)s.size() && cnt[s[hi] - 'a'] > 0) { // not enough
                cnt[s[hi++] - 'a']--;
            }
            if (hi - lo == (int)p.size()) { // enough
                res.emplace_back(lo);
            }
            cnt[s[lo] - 'a']++;
        }
        return res;
    }
};
// @lc code=end
