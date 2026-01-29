/*
 *   author:    zhouyuhao
 *   created:   2025-01-19 12:01:19
 *   modified:  2026-01-29 17:45:23
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
    int minAddToMakeValid(string s) {
        int res = 0, left = 0, right = 0, k = 1;
        for (int i = 0; i < (int)s.size();) {
            count(s, left, i, '('), count(s, right, i, ')');
            balance(res, left, right, k);
        }
        res += k * left - right;
        return res;
    }
};
// @lc code=end
