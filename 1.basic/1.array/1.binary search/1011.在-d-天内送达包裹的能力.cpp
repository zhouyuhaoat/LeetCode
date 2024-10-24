/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-24 21:02:05
 * 	 modified: 	2024-10-24 21:12:55
 * 	 project: 	LeetCode
 * 	 venue: 	914, Harbin
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
        int lo = *max_element(weights.begin(), weights.end()); // no +1
        int hi = accumulate(weights.begin(), weights.end(), 1);
        while (lo < hi) {
            int mi = (lo + hi) >> 1;
            // binary search -> decision/determine with condition
            if (ship(weights, mi) <= days) {
                hi = mi; // [hi, acc): ship <= days
            } else {
                lo = mi + 1; // [max, lo): ship > days
            }
        }
        return lo; // first ship <= days
    }
};
// @lc code=end
