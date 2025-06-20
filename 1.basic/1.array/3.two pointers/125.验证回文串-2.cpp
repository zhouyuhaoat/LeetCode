/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 09:52:02
 *   modified:  2025-06-19 14:09:14
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
        string str;
        for (char ch : s) {
            if (isalnum(ch)) {
                str += tolower(ch);
            }
        }
        for (int lo = 0, hi = str.size() - 1; lo < hi; lo++, hi--) {
            if (str[lo] != str[hi]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
