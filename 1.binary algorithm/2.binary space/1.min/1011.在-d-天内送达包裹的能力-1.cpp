/*
 *   author:    zhouyuhao
 *   created:   2025-02-11 22:21:57
 *   modified:  2025-11-14 11:06:17
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
        int day = 0, load = 0;
        for (int weight : weights) {
            if (load + weight > cap) { // try
                day++;
                load = 0; // reset
            }
            load += weight;
        }
        return day + (load > 0); // last day
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *ranges::max_element(weights);
        int hi = accumulate(weights.begin(), weights.end(), 0) + 1;
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (ship(weights, mi) <= days) { // first ship <= days
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return hi;
    }
};
// @lc code=end
