/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-26 16:46:05
 * 	 modified: 	2024-10-26 16:46:13
 * 	 project: 	LeetCode
 * 	 venue: 	914, Harbin
 */

/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        vector<string> w;
        istringstream ss(s);
        string tmp;
        while (ss >> tmp) {
            w.emplace_back(tmp);
        }
        string res;
        for (int i = w.size() - 1; i >= 0; i--) {
            res += w[i];
            if (i > 0) res += " ";
        }
        return res;
    }
};
// @lc code=end
