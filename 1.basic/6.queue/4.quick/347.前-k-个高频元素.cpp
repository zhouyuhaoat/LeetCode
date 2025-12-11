/*
 *   author:    zhouyuhao
 *   created:   2025-12-03 13:31:21
 *   modified:  2025-12-03 18:46:56
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
        ranges::nth_element(res, res.begin() + (k - 1), [&](int a, int b) {
            return cnt[a] > cnt[b];
        });
        return {res.begin(), res.begin() + k};
    }
};
// @lc code=end
