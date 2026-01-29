/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:37:10
 *   modified:  2026-01-29 11:49:50
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=1314 lang=cpp
 *
 * [1314] 矩阵区域和
 */

// @lc code=start
class NumMatrix {
private:
    int m, n;
    vector<vector<int>> pref;

public:
    NumMatrix(vector<vector<int>>& matrix) : m(matrix.size()), n(matrix[0].size()), pref(m + 1, vector<int>(n + 1)) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pref[i + 1][j + 1] = pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return pref[row2 + 1][col2 + 1] - pref[row2 + 1][col1] - pref[row1][col2 + 1] + pref[row1][col1];
    }
};

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        NumMatrix numMatrix(mat);
        vector res(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            int row1 = max(i - k, 0), row2 = min(i + k, m - 1); // row
            for (int j = 0; j < n; j++) {
                int col1 = max(j - k, 0), col2 = min(j + k, n - 1); // col
                res[i][j] = numMatrix.sumRegion(row1, col1, row2, col2);
            }
        }
        return res;
    }
};
// @lc code=end
