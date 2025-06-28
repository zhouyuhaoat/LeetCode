/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:36:53
 *   modified:  2025-03-01 17:35:30
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
public:
    int minAddToMakeValid(string s) {
        int ins = 0;
        stack<char> stk;
        for (char ch : s) {
            if (ch == '(') {
                stk.emplace(ch);
            } else {
                if (!stk.empty() && stk.top() == '(') {
                    stk.pop();
                } else {
                    ins++; // insert left for right
                }
            }
        }
        ins += stk.size(); // insert right for remaining left
        return ins;
    }
};
// @lc code=end
