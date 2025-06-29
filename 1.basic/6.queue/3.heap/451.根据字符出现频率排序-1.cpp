/*
 *   author:    zhouyuhao
 *   created:   2024-12-10 22:14:16
 *   modified:  2025-03-02 23:46:12
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
        for (char ch : s) {
            cnt[ch]++;
        }
        vector<pair<char, int>> vec(cnt.begin(), cnt.end());
        ranges::sort(vec, [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;
        });
        string res;
        for (auto& [ch, freq] : vec) {
            res += string(freq, ch);
        }
        return res;
    }
};
// @lc code=end
