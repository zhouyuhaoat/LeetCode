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
        vector<int> res, cnt1(128), cnt2(128); // have & need
        for (char ch : p) {
            cnt2[ch]++;
        }
        for (int hi = 0; hi < (int)s.size(); hi++) { // [lo, hi]
            cnt1[s[hi]]++;
            int lo = hi - p.size() + 1;
            if (lo >= 0) {
                if (cnt1 == cnt2) { // anagram: have = need
                    res.push_back(lo);
                }
                cnt1[s[lo]]--;
            }
        }
        return res;
    }
};
// @lc code=end
