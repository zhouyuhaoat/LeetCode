/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-26 16:09:43
 * 	 modified: 	2024-10-26 16:11:04
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
        int lo = 0, hi = s.size() - 1;
        while (lo < hi) {
            while (lo < hi && !isalnum(s[lo])) {
                lo++;
            }
            while (lo < hi && !isalnum(s[hi])) {
                hi--;
            }
            if (lo < hi && tolower(s[lo++]) != tolower(s[hi--])) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
