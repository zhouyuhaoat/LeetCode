/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 09:52:02
 *   modified:  2025-06-19 15:21:39
 *   project:   LeetCode of labuladong
 *   venue:     226, Harbin
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
        for (int lo = 0, hi = s.size() - 1; lo < hi;) {
            while (lo < hi && !isalnum(s[lo])) lo++;
            while (lo < hi && !isalnum(s[hi])) hi--;
            // after while, s[lo] and s[hi] are alphanumeric or lo >= hi
            if (tolower(s[lo++]) != tolower(s[hi--])) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
