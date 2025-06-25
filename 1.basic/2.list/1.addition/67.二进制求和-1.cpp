/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:38:57
 *   modified:  2025-02-21 12:03:16
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
        ranges::reverse(a), ranges::reverse(b);
        int n = max(a.size(), b.size()), carry = 0;
        for (size_t i = 0; i < n; i++) {
            carry += (i < a.size() ? a[i] - '0' : 0) + (i < b.size() ? b[i] - '0' : 0);
            res.push_back(carry % 2 + '0');
            carry /= 2;
        }
        if (carry != 0) res.push_back(carry + '0');
        ranges::reverse(res);
        return res;
    }
};
// @lc code=end
