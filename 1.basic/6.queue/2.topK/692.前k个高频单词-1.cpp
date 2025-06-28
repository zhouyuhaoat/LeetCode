/*
 *   author:    zhouyuhao
 *   created:   2024-12-14 16:40:57
 *   modified:  2025-03-02 22:52:18
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 */

// @lc code=start
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt; // word -> freq
        for (string& word : words) {
            cnt[word]++;
        }
        vector<string> res;
        for (auto& [word, _] : cnt) {
            res.emplace_back(word);
        }
        ranges::sort(res, [&cnt](const string& a, const string& b) {
            return cnt[a] != cnt[b] ? cnt[a] > cnt[b] : a < b;
        });
        res.erase(res.begin() + k, res.end());
        return res;
    }
};
// @lc code=end
