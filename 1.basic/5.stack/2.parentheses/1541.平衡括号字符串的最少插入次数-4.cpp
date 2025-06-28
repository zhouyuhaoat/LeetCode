/*
 *   author:    zhouyuhao
 *   created:   2025-01-19 12:12:36
 *   modified:  2025-03-01 23:16:04
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=1541 lang=cpp
 *
 * [1541] 平衡括号字符串的最少插入次数
 */

// @lc code=start
class Solution {
public:
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

    int minInsertions(string s) {
        int ins = 0, left = 0, right = 0, k = 2;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
                if (i + 1 < (int)s.size() && s[i + 1] == ')') continue;
                balance(ins, left, right, k);
            }
        }
        ins += k * left - right;
        return ins;
    }
};
// @lc code=end
