/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 09:52:02
 *   modified:  2025-06-19 14:08:44
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
        string revStr(str.rbegin(), str.rend());
        return str == revStr;
    }
};
// @lc code=end
