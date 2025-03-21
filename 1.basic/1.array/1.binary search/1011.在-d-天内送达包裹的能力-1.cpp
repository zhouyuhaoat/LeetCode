/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-11 22:21:57
 * 	 modified: 	2025-02-12 18:55:23
 * 	 project: 	LeetCode of labuladong
 * 	 venue: 	226, Harbin
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
        int d = 1, cur = 0; // 1: last day
        for (int w : weights) {
            if (cur + w > cap) {
                cur = 0;
                d++;
            }
            cur += w;
        }
        return d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *ranges::max_element(weights); // boundary
        int hi = accumulate(weights.begin(), weights.end(), 1);
        // [max, lo): ship > days; [hi, acc): ship <= days
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (ship(weights, mi) <= days) { // first ship <= days
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return lo;
    }
};
// @lc code=end
