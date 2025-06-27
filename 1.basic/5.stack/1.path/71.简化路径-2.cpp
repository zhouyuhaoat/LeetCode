/*
 *   author:    zhouyuhao
 *   created:   2025-03-02 13:48:48
 *   modified:  2025-03-02 14:29:15
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
        auto split = [](const string& s, char delim) {
            vector<string> words;
            for (auto&& token : s | ranges::views::split(delim)) {
                words.emplace_back(string(token.begin(), token.end()));
            }
            return words;
        };
        vector<string> dirs = split(path, '/'), stk;
        for (string& dir : dirs) {
            if (dir == "..") {
                if (!stk.empty()) stk.pop_back();
            } else if (!dir.empty() && dir != ".") {
                stk.emplace_back(dir);
            }
        }
        string res;
        for (string& dir : stk) {
            res += "/" + dir;
        }
        return res.empty() ? "/" : res;
    }
};
// @lc code=end
