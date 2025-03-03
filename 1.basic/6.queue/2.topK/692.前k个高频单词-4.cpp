/*
 *   author:    zhouyuhao
 *   created:   2025-03-02 23:05:13
 *   modified:  2025-03-02 23:08:54
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
        auto cmp = [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second != b.second ? a.second < b.second : a.first > b.first;
            // sort by frequency in descending order, then by lexicographical order in ascending order
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cnt.begin(), cnt.end(), cmp);
        vector<string> res;
        while (k--) {
            res.emplace_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
// @lc code=end
