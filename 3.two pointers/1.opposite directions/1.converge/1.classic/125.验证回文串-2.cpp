/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 09:52:02
 *   modified:  2026-01-28 12:59:16
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
private:
    bool helper(string& s) {
        return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
    }

public:
    bool isPalindrome(string s) {
        string str;
        for (char ch : s) {
            if (isalnum(ch)) {
                str += tolower(ch);
            }
        }
        return helper(str);
    }
};
// @lc code=end
