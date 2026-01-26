/*
 *   author:    zhouyuhao
 *   created:   2025-12-25 23:47:25
 *   modified:  2025-12-30 10:17:21
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=1423 lang=cpp
 *
 * [1423] 可获得的最大点数
 */

// @lc code=start
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = reduce(cardPoints.begin(), cardPoints.begin() + k), res = sum;
        int lo = k, hi = cardPoints.size(); // prefix: [0, lo); suffix: [hi, size)
        while (lo > 0) {
            sum += cardPoints[--hi] - cardPoints[--lo]; // left rotate
            res = max(res, sum);
        }
        return res;
    }
};
// @lc code=end
