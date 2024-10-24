/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
class Solution {
public:
    int eat(vector<int>& piles, int k) {
        int h = 0;
        for (int p : piles) {
            h += (p + k - 1) / k; // floor -> ceil
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = *max_element(piles.begin(), piles.end()) + 1; // k != 0 => lo != 0
        while (lo < hi) {
            int mi = (lo + hi) >> 1;
            if (eat(piles, mi) <= h) {
                hi = mi; // [hi, max): eat <= h
            } else {
                lo = mi + 1; // [1, lo): eat > h
            }
        }
        return lo; // first eat <= h
    }
};
// @lc code=end
