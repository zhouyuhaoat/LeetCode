/*
 *   author:    zhouyuhao
 *   created:   2025-05-22 09:37:20
 *   modified:  2025-05-22 10:05:15
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
public:
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
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *ranges::max_element(weights);
        int hi = accumulate(weights.begin(), weights.end(), 1);
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (ship(weights, mi) <= days) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return lo;
    }
};
// @lc code=end
