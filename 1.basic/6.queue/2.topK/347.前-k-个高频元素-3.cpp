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
        int mc = 0;
        for (int num : nums) {
            mc = max(mc, ++cnt[num]);
        }
        vector<list<int>> bucket(mc + 1);
        for (auto& [num, freq] : cnt) {
            bucket[freq].emplace_back(num);
        }
        vector<int> res;
        for (int i = bucket.size() - 1; i >= 0 && (int)res.size() < k; i--) {
            if (bucket[i].empty()) continue;
            res.insert(res.end(), bucket[i].begin(), bucket[i].end());
        }
        return res;
    }
};
// @lc code=end
