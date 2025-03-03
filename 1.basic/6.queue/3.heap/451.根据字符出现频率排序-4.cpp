/*
 *   author:    zhouyuhao
 *   created:   2024-12-14 20:56:34
 *   modified:  2025-03-01 20:33:54
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnt;
        int f = 0;
        for (char& ch : s) {
            f = max(f, ++cnt[ch]);
        }
        vector<string> bucket(f + 1);
        for (auto& [ch, n] : cnt) {
            bucket[n].push_back(ch);
        }
        string res;
        for (int i = f; i > 0; i--) {
            string& b = bucket[i];
            if (!b.empty()) {
                for (char& ch : b) {
                    res += string(i, ch);
                }
            }
        }
        return res;
    }
};
// @lc code=end
