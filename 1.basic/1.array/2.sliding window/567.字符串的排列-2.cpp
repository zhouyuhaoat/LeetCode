/*
 *   author:    zhouyuhao
 *   created:   2025-02-12 23:35:12
 *   modified:  2025-05-22 18:53:41
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
        int diff = ranges::count_if(cnt1, [&cnt1, &cnt2, i = 0](int val) mutable {
            return cnt1[i] != cnt2[i++];
        });
        for (int hi = 0; hi < (int)s2.size(); hi++) {
            int& right = cnt2[s2[hi] - 'a'];
            if (right == cnt1[s2[hi] - 'a']) {
                diff++;
            } else if (right == cnt1[s2[hi] - 'a'] - 1) {
                diff--;
            }
            right++;
            int lo = hi - s1.size() + 1;
            if (lo >= 0) {
                if (diff == 0) return true;
                int& left = cnt2[s2[lo] - 'a'];
                if (left == cnt1[s2[lo] - 'a']) {
                    diff++;
                } else if (left == cnt1[s2[lo] - 'a'] + 1) {
                    diff--;
                }
                left--;
            }
        }
        return false;
    }
};
// @lc code=end
