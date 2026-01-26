/*
 *   author:    zhouyuhao
 *   created:   2025-12-28 13:37:58
 *   modified:  2025-12-30 09:23:27
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
class Solution {
private:
    int eat(vector<int>& piles, int speed) {
        return transform_reduce(piles.begin(), piles.end(), 0, plus<int>(), [&](int pile) {
            return (pile + speed - 1) / speed;
        });
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = ranges::max(piles) + 1;
        auto it = ranges::partition_point(views::iota(lo, hi), [&](int speed) {
            return eat(piles, speed) > h;
        });
        return *it;
    }
};
// @lc code=end
