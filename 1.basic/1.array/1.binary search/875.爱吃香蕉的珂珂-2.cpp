/*
 *   author:    zhouyuhao
 *   created:   2025-02-11 22:16:31
 *   modified:  2025-05-22 09:41:01
 *   project:   LeetCode of labuladong
 *   venue:     226, Harbin
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
        return accumulate(piles.begin(), piles.end(), 0, [v](int h, int p) {
            return h + (p + v - 1) / v;
        });
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = *ranges::max_element(piles) + 1;
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (eat(piles, mi) <= h) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return lo;
    }
};
// @lc code=end
