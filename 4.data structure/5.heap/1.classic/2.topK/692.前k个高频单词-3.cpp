/*
 *   author:    zhouyuhao
 *   created:   2024-12-14 21:52:11
 *   modified:  2025-03-03 08:26:15
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
        auto cmp = [](pair<string, int>& a, pair<string, int>& b) {
            return a.second != b.second ? a.second > b.second : a.first < b.first;
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);
        for (auto& it : cnt) {
            pq.push(it);
            if ((int)pq.size() > k) {
                pq.pop();
            }
        }
        vector<string> res(k); // reserve for reverse
        while (!pq.empty()) {
            res[--k] = pq.top().first;
            pq.pop();
        }
        return res;
    }
};
// @lc code=end
