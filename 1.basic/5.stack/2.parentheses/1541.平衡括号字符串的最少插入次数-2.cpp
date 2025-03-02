/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:36:52
 *   modified:  2025-03-01 17:52:30
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
            char c = s[i];
            if (c == '(') {
                stk.emplace('(');
            } else {
                // left
                if (stk.empty()) {
                    ins++;
                } else {
                    stk.pop();
                }
                // another right
                if (i + 1 < (int)s.size() && s[i + 1] == ')') {
                    i++;
                } else {
                    ins++;
                }
            }
        }
        ins += stk.size() * 2;
        return ins;
    }
};
// @lc code=end
