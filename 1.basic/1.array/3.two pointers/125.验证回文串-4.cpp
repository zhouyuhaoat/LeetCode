/*
 *   author:    zhouyuhao
 *   created:   2025-11-14 16:33:40
 *   modified:  2025-11-14 21:48:02
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int lo = 0, hi = s.size() - 1;
        while (lo < hi) {
            if (!isalnum(s[lo])) {
                lo++;
            } else if (!isalnum(s[hi])) {
                hi--;
            } else if (tolower(s[lo]) != tolower(s[hi])) {
                return false;
            } else {
                lo++, hi--;
            }
        }
        return true;
    }
};
// @lc code=end
