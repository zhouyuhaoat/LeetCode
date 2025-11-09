/*
 *   author:    zhouyuhao
 *   created:   2025-02-11 22:21:57
 *   modified:  2025-05-22 13:50:29
 *   project:   LeetCode of labuladong
 *   venue:     226, Harbin
 */

/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start
class Solution {
private:
    int ship(vector<int>& weights, int cap) {
        int day = 1, load = 0;
        for (int weight : weights) {
            load += weight;
            if (load > cap) {
                day++;
                load = weight;
            }
        }
        return day;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = ranges::max(weights);
        int hi = accumulate(weights.begin(), weights.end(), 1);
        vector<int> d(hi - lo);
        ranges::iota(d, lo);
        auto it = ranges::partition_point(d, [&](int cap) {
            return ship(weights, cap) > days; // first false
        });
        return *it;
    }
};
// @lc code=end
