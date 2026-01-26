/*
 *   author:    zhouyuhao
 *   created:   2025-05-22 09:37:20
 *   modified:  2025-11-14 11:49:30
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
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
        int day = 0, load = 0;
        for (int weight : weights) {
            load += weight; // no try
            if (load > cap) {
                day++;
                load = weight; // restore
            }
        }
        return day + (load > 0);
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = ranges::max(weights);
        int hi = reduce(weights.begin(), weights.end()) + 1;
        auto it = ranges::partition_point(views::iota(lo, hi), [&](int cap) {
            return ship(weights, cap) > days;
        });
        return *it;
    }
};
// @lc code=end
