/*
 *   author:    zhouyuhao
 *   created:   2025-02-12 23:16:43
 *   modified:  2025-05-22 18:52:07
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
        vector<int> res, cntS(26), cntP(26);
        for (char ch : p) {
            cntP[ch - 'a']++;
        }
        /*
            diff: count difference between strings
            anagram: have = need => diff = 0
        */
        int diff = ranges::count_if(cntP, [&cntP, &cntS, i = 0](int val) mutable {
            return cntP[i] != cntS[i++];
        });
        for (int hi = 0; hi < (int)s.size(); hi++) {
            int& right = cntS[s[hi] - 'a'];
            if (right == cntP[s[hi] - 'a']) { // same -> different
                diff++;
            } else if (right == cntP[s[hi] - 'a'] - 1) { // different -> same
                diff--;
            }
            right++;
            int lo = hi - p.size() + 1;
            if (lo >= 0) {
                if (diff == 0) {
                    res.emplace_back(lo);
                }
                int& left = cntS[s[lo] - 'a'];
                if (left == cntP[s[lo] - 'a']) { // same -> different
                    diff++;
                } else if (left == cntP[s[lo] - 'a'] + 1) { // different -> same
                    diff--;
                }
                left--;
            }
        }
        return res;
    }
};
// @lc code=end
