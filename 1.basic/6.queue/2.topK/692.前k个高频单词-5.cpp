/*
 *   author:    zhouyuhao
 *   created:   2025-03-02 23:14:01
 *   modified:  2025-03-02 23:19:20
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
        auto cmp = [&cnt](const string& a, const string& b) {
            return cnt[a] != cnt[b] ? cnt[a] > cnt[b] : a < b;
        };
        nth_element(res.begin(), res.begin() + k, res.end(), cmp);
        sort(res.begin(), res.begin() + k, cmp);
        return vector<string>(res.begin(), res.begin() + k);
    }
};
// @lc code=end
