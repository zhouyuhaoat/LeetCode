/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:36:51
 *   modified:  2025-03-01 23:04:11
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
            // first/last/continuous delim -> empty string
            vector<string> dir;
            string tmp;
            for (char ch : s) {
                if (ch == delim) {
                    dir.emplace_back(tmp);
                    tmp.clear();
                } else {
                    tmp += ch;
                }
            }
            if (!tmp.empty()) dir.emplace_back(tmp);
            return dir;
        };
        // using std::vector to simulate stack if need reverse
        vector<string> dir = split(path, '/'), stk;
        for (string& d : dir) {
            if (d == "..") {
                if (!stk.empty()) stk.pop_back();
            } else if (!d.empty() && d != ".") {
                stk.emplace_back(d);
            }
        }
        string res;
        if (stk.empty()) {
            res = "/";
        } else {
            for (string& d : stk) {
                res += "/" + d;
            }
        }
        return res;
    }
};
// @lc code=end
