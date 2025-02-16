/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-12 23:16:43
 * 	 modified: 	2025-02-13 20:04:09
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
        vector<int> cnts(26), cntp(26);
        for (char c : p) {
            cntp[c - 'a']++;
        }
        // dif: count difference between strings
        // anagram: have = need => dif = 0
        int dif = ranges::count_if(cntp, [&cntp, &cnts, i = 0](int val) mutable {
            return cntp[i] != cnts[i++];
        });
        vector<int> res;
        for (int i = 0; i < (int)s.size(); i++) {
            int& r = cnts[s[i] - 'a'];
            if (r == cntp[s[i] - 'a']) { // same -> different
                dif++;
            } else if (r == cntp[s[i] - 'a'] - 1) { // different -> same
                dif--;
            }
            r++;
            if (i >= (int)p.size() - 1) {
                if (dif == 0) {
                    res.emplace_back(i - p.size() + 1);
                }
                int& l = cnts[s[i - p.size() + 1] - 'a'];
                if (l == cntp[s[i - p.size() + 1] - 'a']) { // same -> different
                    dif++;
                } else if (l == cntp[s[i - p.size() + 1] - 'a'] + 1) { // different -> same
                    dif--;
                }
                l--;
            }
        }
        return res;
    }
};
// @lc code=end
