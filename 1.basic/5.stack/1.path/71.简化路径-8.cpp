/*
 *   author:    zhouyuhao
 *   created:   2025-03-02 13:48:48
 *   modified:  2025-03-02 14:33:36
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
        auto split = [](const string& s, char delim) -> vector<string> {
            vector<string> dir;
            for (auto&& part : ranges::split_view(s, delim)) {
                dir.emplace_back(string(part.begin(), part.end()));
            }
            return dir;
        };
        vector<string> dir = split(path, '/'), stk;
        for (string& d : dir) {
            if (d == "..") {
                if (!stk.empty()) stk.pop_back();
            } else if (!d.empty() && d != ".") {
                stk.emplace_back(d);
            }
        }
        string res;
        for (string& d : stk) {
            res += "/" + d;
        }
        return res.empty() ? "/" : res;
    }
};
// @lc code=end
