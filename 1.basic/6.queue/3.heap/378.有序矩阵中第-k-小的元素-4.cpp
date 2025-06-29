/*
 *   author:    zhouyuhao
 *   created:   2024-12-10 21:53:35
 *   modified:  2025-03-03 09:42:08
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
    int count(vector<vector<int>>& matrix, int val, int n) {
        int i = n - 1, j = 0, cnt = 0;
        /*
            zigzag search in a matrix
            - bottom-left corner -> top-right corner
        */
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= val) {
                cnt += i + 1; // column by column
                j++;
            } else {
                i--;
            }
        }
        return cnt;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int lo = matrix[0][0], hi = matrix[n - 1][n - 1] + 1;
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (count(matrix, mi, n) >= k) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return lo;
    }
};
// @lc code=end
