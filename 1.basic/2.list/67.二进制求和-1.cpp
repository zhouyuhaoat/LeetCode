/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-01 23:56:38
 * 	 modified: 	2024-11-02 00:01:39
 * 	 project: 	LeetCode
 * 	 venue: 	226, Harbin
 */

/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int n = max(a.size(), b.size()), carry = 0;
        for (size_t i = 0; i < n; i++) {
            carry += i < a.size() ? a[i] - '0' : 0; // char -> int
            carry += i < b.size() ? b[i] - '0' : 0;
            res.push_back(carry % 2 + '0'); // int -> char
            carry /= 2;
        }
        if (carry != 0) res.push_back(carry + '0');
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
