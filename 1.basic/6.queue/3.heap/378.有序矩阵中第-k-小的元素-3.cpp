/*
 *   author:    zhouyuhao
 *   created:   2024-12-10 22:03:16
 *   modified:  2025-03-03 09:27:55
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第 K 小的元素
 */

// @lc code=start
class Solution {
public:
    int count(vector<vector<int>>& matrix, int val) {
        int cnt = 0;
        for (auto& row : matrix) {
            /*
                less or equal to val:
                - k-th smallest element: the number of elements less than or equal to val is k
                - upper_bound: count of elements less than or equal to val in a sorted range
            */
            cnt += distance(row.begin(), ranges::upper_bound(row, val));
        }
        return cnt;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int lo = matrix[0][0], hi = matrix[n - 1][n - 1] + 1;
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (count(matrix, mi) >= k) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return lo;
    }
};
// @lc code=end
