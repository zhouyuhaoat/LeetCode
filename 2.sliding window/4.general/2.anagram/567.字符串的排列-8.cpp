/*
 *   author:    zhouyuhao
 *   created:   2025-02-12 23:01:03
 *   modified:  2025-05-22 18:54:38
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
        vector<int> cnt(128);
        for (char ch : s1) {
            cnt[ch]++;
        }
        for (int lo = 0, hi = 0; hi < (int)s2.size(); hi++) {
            cnt[s2[hi]]--;
            while (cnt[s2[hi]] < 0) {
                cnt[s2[lo++]]++;
            }
            if (hi - lo + 1 == (int)s1.size()) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
