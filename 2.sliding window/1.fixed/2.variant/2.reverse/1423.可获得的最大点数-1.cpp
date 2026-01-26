/*
 *   author:    zhouyuhao
 *   created:   2025-12-25 23:47:25
 *   modified:  2025-12-26 12:06:13
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
        int totalSum = reduce(cardPoints.begin(), cardPoints.end());
        int len = cardPoints.size() - k; // reverse
        if (len <= 0) return totalSum;
        int res = 0, sum = 0;
        for (int hi = 0; hi < (int)cardPoints.size(); hi++) { // [lo, hi]
            sum += cardPoints[hi];
            int lo = hi - len + 1;
            if (lo >= 0) {
                res = max(res, totalSum - sum);
                sum -= cardPoints[lo];
            }
        }
        return res;
    }
};
// @lc code=end
