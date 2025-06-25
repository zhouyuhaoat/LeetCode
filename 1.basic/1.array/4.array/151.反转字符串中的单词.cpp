/*
 *   author:    zhouyuhao
 *   created:   2025-02-13 10:07:16
 *   modified:  2025-06-25 11:58:03
 *   project:   LeetCode of labuladong
 *   venue:     226, Harbin
 */

/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
public:
    vector<string> split(string& s, char delim) {
        vector<string> words;
        istringstream ss(s);
        string token;
        while (ss >> token) { // white space as delimiter
            words.emplace_back(token);
        }
        return words;
    }

    string reverseWords(string s) {
        vector<string> words = split(s, ' ');
        string res;
        for (int i = words.size() - 1; i >= 0; i--) {
            res += words[i];
            if (i > 0) res += " ";
        }
        return res;
    }
};
// @lc code=end
