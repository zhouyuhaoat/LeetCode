/*
 *   author:    zhouyuhao
 *   created:   2025-03-02 13:48:48
 *   modified:  2025-03-02 15:04:21
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

struct string_constructor {
    string operator()(auto&& r) const {
        return string(r.begin(), r.end());
    }
};

class Solution {
public:
    string simplifyPath(string path) {
        auto split = [](const string& s, char delim) -> vector<string> {
            vector<string> dir;
            ranges::transform(ranges::split_view(s, delim), back_inserter(dir), string_constructor());
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
