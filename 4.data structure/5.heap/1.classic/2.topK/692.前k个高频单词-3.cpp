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
        auto cmp = [](pair<string, int>& a, pair<string, int>& b) { // descend freq, ascend lex
            return a.second != b.second ? a.second < b.second : a.first > b.first;
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cnt.begin(), cnt.end(), cmp);
        vector<string> res;
        res.reserve(k);
        while (k--) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
// @lc code=end
