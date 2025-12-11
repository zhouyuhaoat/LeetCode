/*
 *   author:    zhouyuhao
 *   created:   2024-12-14 16:40:57
 *   modified:  2025-12-04 09:39:23
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
        unordered_map<string, int> cnt;
        for (string& word : words) {
            cnt[word]++;
        }
        vector<string> res;
        for (auto& [word, _] : cnt) {
            res.emplace_back(word);
        }
        ranges::partial_sort(res, res.begin() + k, [&](const string& a, const string& b) {
            return cnt[a] != cnt[b] ? cnt[a] > cnt[b] : a < b;
        });
        return {res.begin(), res.begin() + k};
    }
};
// @lc code=end
