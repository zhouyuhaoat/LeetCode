/*
 *   author:    zhouyuhao
 *   created:   2025-02-12 23:01:03
 *   modified:  2025-05-22 18:51:57
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
        vector<int> res, cntS(128), cntP(128); // have, need
        for (char ch : p) {
            cntP[ch]++;
        }
        for (int hi = 0; hi < (int)s.size(); hi++) {
            cntS[s[hi]]++;
            int lo = hi - p.size() + 1; // lo: the start of the substring
            if (lo >= 0) { // prerequisite: same length
                if (cntP == cntS) { // anagram: have = need
                    res.emplace_back(lo);
                }
                cntS[s[lo]]--; // fixed-length
            }
        }
        return res;
    }
};
// @lc code=end
