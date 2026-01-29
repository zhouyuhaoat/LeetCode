/*
 *   author:    zhouyuhao
 *   created:   2025-03-02 13:48:48
 *   modified:  2026-01-28 23:28:13
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
        auto split = [](string& s, char delim) {
            return views::split(s, delim) | ranges::to<vector<string>>();
        };

        auto join = [](vector<string>& words, char sep) {
            return views::join_with(words, sep) | ranges::to<string>();
        };

        char slash = '/';
        vector<string> dirs = split(path, slash), stk;
        for (string& dir : dirs) {
            if (dir == "..") {
                if (!stk.empty()) {
                    stk.pop_back();
                }
            } else if (!dir.empty() && dir != ".") {
                stk.push_back(dir);
            }
        }

        return slash + (stk.empty() ? string() : join(stk, slash));
    }
};
// @lc code=end
