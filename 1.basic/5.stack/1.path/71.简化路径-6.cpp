/*
 *   author:    zhouyuhao
 *   created:   2025-03-02 13:37:15
 *   modified:  2025-03-02 13:54:48
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
#include <ranges>

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dir;
        for (auto&& part : path | ranges::views::split('/')) {
            string s(part.begin(), part.end());
            if (s.empty() || s == ".") continue;
            if (s != "..") {
                dir.emplace_back(s);
            } else if (!dir.empty()) {
                dir.pop_back();
            }
        }
        string res;
        for (string& d : dir) {
            res += '/' + d;
        }
        return res.empty() ? "/" : res;
    }
};
// @lc code=end
