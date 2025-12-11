/*
 *   author:    zhouyuhao
 *   created:   2024-12-14 16:40:57
 *   modified:  2025-12-04 09:40:57
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
        int maxFreq = 0;
        for (string& word : words) {
            maxFreq = max(maxFreq, ++cnt[word]);
        }
        vector<vector<string>> buckets(maxFreq + 1);
        for (auto& [word, freq] : cnt) {
            buckets[freq].emplace_back(word);
        }
        vector<string> res;
        for (int freq = maxFreq; freq >= 1 && (int)res.size() < k; freq--) {
            if (buckets[freq].empty()) continue;
            ranges::sort(buckets[freq]);
            for (auto& word : buckets[freq]) {
                res.emplace_back(word);
                if ((int)res.size() == k) break;
            }
        }
        return res;
    }
};
// @lc code=end
