/*
 *   author:    zhouyuhao
 *   created:   2025-12-25 23:47:25
 *   modified:  2025-12-29 13:11:51
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
        int sum = reduce(cardPoints.end() - k, cardPoints.end()), res = sum;
        int lo = 0, hi = cardPoints.size() - k; // suffix: [hi, size); prefix: [0, lo)
        while (hi < (int)cardPoints.size()) {
            sum += cardPoints[lo++] - cardPoints[hi++]; // right rotate
            res = max(res, sum);
        }
        return res;
    }
};
// @lc code=end
