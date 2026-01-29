/*
 *   author:    zhouyuhao
 *   created:   2025-03-02 13:48:48
 *   modified:  2026-01-29 14:15:36
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
            ranges::transform(views::split(s, delim), back_inserter(words), ranges::to<string>());
            return words;
        };

        auto join = [](vector<string>& words, char sep) {
            ostringstream ss;
            copy(words.begin(), prev(words.end()), ostream_iterator<string>(ss, string(1, sep).c_str()));
            ss << words.back();
            return ss.str();
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

        return slash + (stk.empty() ? string() : join(stk, slash));
    }
};
// @lc code=end
