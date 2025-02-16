/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-12 23:01:03
 * 	 modified: 	2025-02-15 21:34:39
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
        vector<int> res, cnts(26), cntp(26); // have, need
        for (char c : p) {
            cntp[c - 'a']++;
        }
        for (int i = 0; i < (int)s.size(); i++) {
            cnts[s[i] - 'a']++;
            if (i >= (int)p.size() - 1) { // prerequisite: same length
                if (cntp == cnts) { // anagram: have = need
                    res.emplace_back(i - p.size() + 1);
                }
                cnts[s[i - p.size() + 1] - 'a']--;
            }
        }
        return res;
    }
};
// @lc code=end
