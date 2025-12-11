/*
 *   author:    zhouyuhao
 *   created:   2024-12-14 16:30:11
 *   modified:  2025-12-04 09:36:11
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
        vector<vector<int>> buckets(maxFreq + 1);
        for (auto [num, freq] : cnt) {
            buckets[freq].emplace_back(num);
        }
        vector<int> res;
        for (int freq = maxFreq; freq >= 1 && (int)res.size() < k; freq--) {
            if (buckets[freq].empty()) continue;
            for (int num : buckets[freq]) {
                res.emplace_back(num);
                if ((int)res.size() == k) break;
            }
        }
        return res;
    }
};
// @lc code=end
