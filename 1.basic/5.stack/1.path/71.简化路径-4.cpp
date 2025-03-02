/*
 *   author:    zhouyuhao
 *   created:   2025-01-19 11:05:27
 *   modified:  2025-03-01 12:25:45
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
        auto split = [](const string& s, char delim) -> vector<string> {
            vector<string> dir;
            istringstream ss(s);
            string tmp;
            while (getline(ss, tmp, delim)) {
                // skip invalid string
                if (tmp.empty() || tmp == ".") continue;
                if (tmp == "..") {
                    if (!dir.empty()) dir.pop_back();
                } else {
                    dir.emplace_back(tmp);
                }
            }
            return dir;
        };
        vector<string> dir = split(path, '/');
        string res;
        for (string& d : dir) {
            res += "/" + d;
        }
        return res.empty() ? "/" : res;
    }
};
// @lc code=end
