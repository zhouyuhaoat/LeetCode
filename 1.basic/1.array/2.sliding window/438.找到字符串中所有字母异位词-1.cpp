/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-25 20:26:48
 * 	 modified: 	2024-10-25 20:59:21
 * 	 project: 	LeetCode
 * 	 venue: 	914, Harbin
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
        vector<int> cntp(26);
        for (char c : p) {
            cntp[c - 'a']++;
        }
        vector<int> res, cnts(26);
        for (int i = 0; i < (int)s.size(); i++) {
            cnts[s[i] - 'a']++; // right in
            if (i >= (int)p.size() - 1) { // anagram -> the same length
                if (cntp == cnts) {
                    res.emplace_back(i - p.size() + 1);
                }
                cnts[s[i - p.size() + 1] - 'a']--; // left out
            }
        }
        return res;
    }
};
// @lc code=end
