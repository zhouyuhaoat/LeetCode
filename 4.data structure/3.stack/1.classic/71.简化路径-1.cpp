/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:36:51
 *   modified:  2026-01-29 13:16:06
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
            istringstream ss(s);
            string token;
            while (getline(ss, token, delim)) {
                words.push_back(token);
            }
            return words;
        };

        auto join = [](vector<string>& words, char sep) {
            string s;
            for (string& token : words) {
                s += sep + token;
            }
            return s;
        };

        char slash = '/';
        vector<string> dirs = split(path, slash), stk;
        // using vector to simulate stack for reverse
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
