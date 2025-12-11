/*
 *   author:    zhouyuhao
 *   created:   2024-12-14 16:30:11
 *   modified:  2025-12-03 18:44:35
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
        for (auto [num, _] : cnt) {
            res.emplace_back(num);
        }
        ranges::partial_sort(res, res.begin() + k, [&](int a, int b) {
            return cnt[a] > cnt[b];
        });
        return {res.begin(), res.begin() + k};
    }
};
// @lc code=end
