/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:36:51
 *   modified:  2025-03-01 17:15:39
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        auto split = [](string s, char delim) -> stack<string> {
            stack<string> stk;
            string tmp;
            s += delim; // add delim to the end for the last word
            for (char ch : s) {
                if (ch == delim) {
                    if (tmp.empty()) continue;
                    if (tmp == "..") {
                        if (!stk.empty()) stk.pop();
                    } else if (tmp != ".") {
                        stk.emplace(tmp);
                    }
                    tmp.clear();
                } else {
                    tmp += ch;
                }
            }
            return stk;
        };
        stack<string> stk = split(path, '/');
        string res;
        while (!stk.empty()) {
            res = "/" + stk.top() + res; // reverse
            stk.pop();
        }
        return res.empty() ? "/" : res;
    }
};
// @lc code=end
