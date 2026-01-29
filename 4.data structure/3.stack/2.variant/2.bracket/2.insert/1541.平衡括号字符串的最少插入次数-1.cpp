/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:36:53
 *   modified:  2025-03-01 17:53:06
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
    int minInsertions(string s) {
        int res = 0, n = s.size();
        stack<char> stk;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                stk.push(s[i]);
            } else {
                if (stk.empty()) {
                    if (i + 1 < n && s[i + 1] == ')') {
                        res++, i++; // )): insert left
                    } else {
                        res += 2; // ): insert left and another right
                    }
                } else {
                    stk.pop();
                    if (i + 1 < n && s[i + 1] == ')') {
                        i++; // ()): insert nothing
                    } else {
                        res++; // (): insert another right
                    }
                }
            }
        }
        while (!stk.empty()) {
            stk.pop();
            res += 2; // (: insert right and another right
        }
        return res;
    }
};
// @lc code=end
