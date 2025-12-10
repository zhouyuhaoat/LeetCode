/*
 *   author:    zhouyuhao
 *   created:   2025-01-19 12:01:19
 *   modified:  2025-03-01 23:14:20
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=921 lang=cpp
 *
 * [921] 使括号有效的最少添加
 */

// @lc code=start
class Solution {
private:
    void balance(int& ins, int& left, int& right, int k) {
        int mod = right % k;
        if (mod != 0) { // aligning
            ins += k - mod, right += k - mod;
        }
        if (right >= k * left) {
            ins += right / k - left;
            left = 0, right = 0;
        } else {
            left -= right / k, right = 0;
        }
    }

public:
    int minAddToMakeValid(string s) {
        int ins = 0, left = 0, right = 0, k = 1;
        for (int i = 0, n = s.size(); i < n;) {
            while (i < n && s[i] == '(') {
                left++;
                i++;
            }
            while (i < n && s[i] == ')') {
                right++;
                i++;
            }
            balance(ins, left, right, k);
        }
        ins += k * left - right;
        return ins;
    }
};
// @lc code=end
