/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-26 16:06:45
 * 	 modified: 	2024-10-26 16:07:49
 * 	 project: 	LeetCode
 * 	 venue: 	914, Harbin
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
        for (char c : s) {
            if (isalnum(c)) {
                str += tolower(c);
            }
        }
        string rev(str.rbegin(), str.rend());
        return str == rev;
    }
};
// @lc code=end
