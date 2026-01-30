/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:38:57
 *   modified:  2025-02-22 11:39:53
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
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
        int i = a.size() - 1, j = b.size() - 1, carry = 0; // reverse addition
        while (i >= 0 || j >= 0 || carry) {
            int sum = (i >= 0 ? a[i--] - '0' : 0) + (j >= 0 ? b[j--] - '0' : 0) + carry;
            res = (char)(sum % 2 + '0') + res;
            carry = sum / 2;
        }
        return res;
    }
};
// @lc code=end
