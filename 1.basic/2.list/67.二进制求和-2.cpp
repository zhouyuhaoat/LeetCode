/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-02 00:02:09
 * 	 modified: 	2024-11-02 00:06:02
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
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        string res;
        while (i >= 0 || j >= 0 || carry > 0) {
            if (i >= 0) carry += a[i--] - '0';
            if (j >= 0) carry += b[j--] - '0';
            res = (char)(carry % 2 + '0') + res;
            carry /= 2;
        }
        return res;
    }
};
// @lc code=end
