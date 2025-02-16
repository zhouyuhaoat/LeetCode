/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-13 10:07:16
 * 	 modified: 	2025-02-16 20:45:26
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
    vector<string> split(const string& s) {
        vector<string> w;
        istringstream ss(s);
        string tmp;
        while (ss >> tmp) {
            w.emplace_back(tmp);
        }
        return w;
    }
    string reverseWords(string s) {
        vector<string> w = split(s);
        string res;
        for (int i = w.size() - 1; i >= 0; i--) {
            res += w[i];
            if (i > 0) res += " ";
        }
        return res;
    }
};
// @lc code=end
