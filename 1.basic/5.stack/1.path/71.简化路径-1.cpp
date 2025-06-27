/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:36:51
 *   modified:  2025-03-01 16:43:17
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
        auto split = [](const string& s, char delim) {
            // first, last and continuous delimiters -> empty string
            vector<string> words;
            istringstream ss(s);
            string token;
            while (getline(ss, token, delim)) {
                words.emplace_back(token);
            }
            return words;
        };
        vector<string> dirs = split(path, '/'), stk;
        // using vector to simulate stack for reverse
        for (string& dir : dirs) {
            if (dir == "..") {
                if (!stk.empty()) stk.pop_back();
            } else if (!dir.empty() && dir != ".") {
                stk.emplace_back(dir);
            }
        }
        string res;
        if (stk.empty()) {
            res = "/";
        } else {
            for (string& dir : stk) {
                res += "/" + dir;
            }
        }
        return res;
    }
};
// @lc code=end
