/*
 *   author:    zhouyuhao
 *   created:   2024-12-14 16:30:11
 *   modified:  2025-03-02 11:14:00
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int maxFreq = 0;
        for (int num : nums) {
            maxFreq = max(maxFreq, ++cnt[num]);
        }
        vector<list<int>> buckets(maxFreq + 1);
        for (auto& [num, freq] : cnt) {
            buckets[freq].emplace_back(num);
        }
        vector<int> res;
        for (int i = buckets.size() - 1; i >= 0 && (int)res.size() < k; i--) {
            if (buckets[i].empty()) continue;
            res.insert(res.end(), buckets[i].begin(), buckets[i].end());
        }
        return res;
    }
};
// @lc code=end
