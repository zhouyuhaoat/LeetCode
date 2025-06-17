/*
 *   author:    zhouyuhao
 *   created:   2025-02-12 23:01:03
 *   modified:  2025-05-22 18:53:30
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
        vector<int> cnt1(26), cnt2(26);
        for (char ch : s1) {
            cnt1[ch - 'a']++;
        }
        for (int hi = 0; hi < (int)s2.size(); hi++) {
            cnt2[s2[hi] - 'a']++;
            int lo = hi - s1.size() + 1;
            if (lo >= 0) {
                if (cnt1 == cnt2) {
                    return true;
                }
                cnt2[s2[lo] - 'a']--;
            }
        }
        return false;
    }
};
// @lc code=end
