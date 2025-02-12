/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2025-02-11 22:16:31
 * 	 modified: 	2025-02-11 22:20:44
 * 	 project: 	LeetCode of labuladong
 * 	 venue: 	226, Harbin
 */

/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
class Solution {
public:
    int eat(vector<int>& piles, int v) {
        int h = 0;
        for (int p : piles) {
            h += (p + v - 1) / v;
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = *ranges::max_element(piles) + 1;
        // [1, lo): eat > h; [hi, max): eat <= h
        // boundary: lo != 0 since division by zero
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (eat(piles, mi) <= h) { // first eat <= h
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return lo;
    }
};
// @lc code=end
