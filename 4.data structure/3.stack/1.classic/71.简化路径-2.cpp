/*
 *   author:    zhouyuhao
 *   created:   2025-03-02 13:48:48
 *   modified:  2026-01-29 14:06:17
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
            vector<string> words;
            for (auto&& token : s | views::split(delim)) {
                words.push_back(string(token.begin(), token.end()));
            }
            return words;
        };

        auto join = [](vector<string>& words, char sep) {
            return accumulate(words.begin(), words.end(), string(), [&](string a, string& b) {
                return move(a) + sep + b;
            });
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

        return stk.empty() ? string(1, slash) : join(stk, slash);
    }
};
// @lc code=end
