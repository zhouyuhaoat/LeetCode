/*
 *   author:    zhouyuhao
 *   created:   2024-12-10 22:14:07
 *   modified:  2025-03-03 08:22:52
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
        auto cmp = [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second != b.second ? a.second > b.second : a.first < b.first;
            // sort by frequency in ascending order, then by lexicographical order in descending order
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);
        for (auto& it : cnt) {
            pq.emplace(it);
            if ((int)pq.size() > k) {
                pq.pop();
            }
        }
        vector<string> res;
        while (!pq.empty()) {
            res.emplace_back(pq.top().first);
            pq.pop();
        }
        ranges::reverse(res);
        return res;
    }
};
// @lc code=end
