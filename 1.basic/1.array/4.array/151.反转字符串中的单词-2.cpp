/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-13 10:07:16
 * 	 modified: 	2025-02-16 20:50:53
 * 	 project: 	LeetCode of labuladong
 * 	 venue: 	226, Harbin
 */

/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
public:
    vector<string> split(const string& s, char delim) {
        char* str = new char[s.size() + 1]; // + 1 for '\0'
        strcpy(str, s.c_str()); // c_str() -> const char*
        vector<string> w;
        char* token = strtok(str, &delim); // split by delim
        while (token != nullptr) {
            if (strlen(token) > 0) {
                w.emplace_back(token);
            }
            token = strtok(nullptr, &delim); // nullptr for the next token
        }
        delete[] str;
        return w;
    }
    string reverseWords(string s) {
        vector<string> w = split(s, ' ');
        string res;
        for (int i = w.size() - 1; i >= 0; i--) {
            res += w[i];
            if (i > 0) res += " ";
        }
        return res;
    }
};
// @lc code=end
