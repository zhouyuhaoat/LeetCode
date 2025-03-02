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
        auto split = [](const string& s, char delim) -> vector<string> {
            // first/last/continuous delim -> empty string
            vector<string> dir;
            istringstream ss(s);
            string tmp;
            while (getline(ss, tmp, delim)) {
                dir.emplace_back(tmp);
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
