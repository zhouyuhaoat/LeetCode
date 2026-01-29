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
private:
    void count(string& s, int& cnt, int& i, char ch) { // consecutive
        while (i < (int)s.size() && s[i] == ch) {
            cnt++;
            i++;
        }
    }

    void balance(int& ins, int& left, int& right, int k) {
        if (int mod = right % k; mod != 0) { // align
            int need = k - mod;
            ins += need, right += need;
        }
        if (int part = right / k; part >= left) { // match
            ins += part - left;
            left = 0, right = 0;
        } else {
            left -= part, right = 0;
        }
    }

public:
    int minInsertions(string s) {
        int res = 0, left = 0, right = 0, k = 2;
        for (int i = 0; i < (int)s.size();) {
            count(s, left, i, '('), count(s, right, i, ')');
            balance(res, left, right, k);
        }
        res += k * left - right;
        return res;
    }
};
// @lc code=end
