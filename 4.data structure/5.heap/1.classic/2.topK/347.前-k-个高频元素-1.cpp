/*
 *   author:    zhouyuhao
 *   created:   2024-12-10 22:13:48
 *   modified:  2025-03-02 11:12:16
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
        unordered_map<int, int> cnt; // num -> freq
        for (int num : nums) {
            cnt[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto [num, freq] : cnt) {
            pq.emplace(freq, num); // {freq, num}
            if ((int)pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> res;
        res.reserve(k);
        while (!pq.empty()) { // reverse order
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
// @lc code=end
