/*
 *   author:    zhouyuhao
 *   created:   2025-02-12 23:01:03
 *   modified:  2025-05-22 18:54:28
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cnt(26);
        for (char ch : s1) {
            cnt[ch - 'a']++;
        }
        for (int lo = 0, hi = 0; lo < (int)s2.size(); lo++) {
            while (hi < (int)s2.size() && cnt[s2[hi] - 'a'] > 0) {
                cnt[s2[hi] - 'a']--;
                hi++;
            }
            if (hi - lo == (int)s1.size()) return true;
            cnt[s2[lo] - 'a']++;
        }
        return false;
    }
};
// @lc code=end
