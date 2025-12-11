/*
 *   author:    zhouyuhao
 *   created:   2024-12-10 22:13:48
 *   modified:  2025-03-02 11:13:52
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
        for (int num : nums) {
            cnt[num]++;
        }
        vector<int> res;
        priority_queue<pair<int, int>> pq;
        for (auto [num, freq] : cnt) {
            pq.emplace(freq, num);
            if ((int)pq.size() > (int)cnt.size() - k) {
                res.emplace_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};
// @lc code=end
