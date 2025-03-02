/*
 *   author:    zhouyuhao
 *   created:   2025-03-01 12:08:22
 *   modified:  2025-03-01 23:07:33
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
            char* str = new char[s.size() + 1]; // + 1 for '\0'
            strcpy(str, s.c_str()); // c_str() -> const char*
            char* token = strtok(str, &delim); // split by delim
            while (token != nullptr) {
                // also can convert char* to string by 'string tmp(token);'
                if (strcmp(token, "..") == 0) {
                    if (!dir.empty()) dir.pop_back();
                } else if (strlen(token) > 0 && strcmp(token, ".") != 0) {
                    dir.emplace_back(token);
                }
                token = strtok(nullptr, &delim); // nullptr for the next token
            }
            delete[] str;
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
