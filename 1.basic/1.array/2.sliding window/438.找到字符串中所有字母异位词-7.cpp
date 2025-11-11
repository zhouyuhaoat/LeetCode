/*
 *   author:    zhouyuhao
 *   created:   2025-02-12 23:01:03
 *   modified:  2025-05-22 18:53:04
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
        vector<int> res, cnt(128);
        for (char ch : p) {
            cnt[ch]++;
        }
        for (int lo = 0, hi = 0; lo < (int)s.size(); lo++) {
            while (hi < (int)s.size() && cnt[s[hi]] > 0) { // not enough: have < need
                cnt[s[hi]]--;
                hi++;
            }
            // enough: have >= need
            if (hi - lo == (int)p.size()) { // just right: have == need
                res.emplace_back(lo);
            }
            cnt[s[lo]]++;
        }
        return res;
    }
};
// @lc code=end
