/*
 *   author:    zhouyuhao
 *   created:   2025-01-19 19:35:35
 *   modified:  2025-03-03 09:42:14
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
private:
    int zigzag_count(vector<vector<int>>& A, int e) {
        int m = A.size(), n = A[0].size();
        int i = 0, j = n - 1, cnt = 0;
        while (i < m && j >= 0) {
            if (A[i][j] > e) {
                j--;
            } else {
                cnt += j + 1; // row by row
                i++;
            }
        }
        return cnt;
    }

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int lo = matrix[0][0], hi = matrix[m - 1][n - 1] + 1;
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (zigzag_count(matrix, mi) >= k) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return lo;
    }
};
// @lc code=end
