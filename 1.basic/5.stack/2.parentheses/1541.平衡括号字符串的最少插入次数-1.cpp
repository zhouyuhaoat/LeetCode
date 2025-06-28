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
        int ins = 0;
        stack<char> stk;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(') {
                stk.emplace(s[i]);
            } else {
                if (stk.empty()) {
                    if (i + 1 < (int)s.size() && s[i + 1] == ')') {
                        ins++, i++; // )): insert left
                    } else {
                        ins += 2; // ): insert left and another right
                    }
                } else {
                    stk.pop();
                    if (i + 1 < (int)s.size() && s[i + 1] == ')') {
                        i++; // ()): insert nothing
                    } else {
                        ins++; // (): insert another right
                    }
                }
            }
        }
        while (!stk.empty()) {
            stk.pop();
            ins += 2; // (: insert right and another right
        }
        return ins;
    }
};
// @lc code=end
