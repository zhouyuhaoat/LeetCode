/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-26 16:06:45
 * 	 modified: 	2024-10-26 16:09:06
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
        int lo = 0, hi = str.size() - 1;
        while (lo < hi) {
            if (str[lo++] != str[hi--]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
