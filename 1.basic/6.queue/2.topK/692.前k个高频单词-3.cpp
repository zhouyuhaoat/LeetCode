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
    struct cmp {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
            return a.first != b.first ? a.first > b.first : a.second < b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        for (string& word : words) {
            cnt[word]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        for (pair<string, int> it : cnt) {
            pq.emplace(it.second, it.first); // {freq, word}
            if ((int)pq.size() > k) {
                pq.pop();
            }
        }
        vector<string> res(k); // reserve for reverse
        while (!pq.empty()) {
            res[--k] = pq.top().second;
            pq.pop();
        }
        return res;
    }
};
// @lc code=end
