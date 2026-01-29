/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:37:15
 *   modified:  2026-01-29 11:33:25
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
class NumMatrix {
private:
    int m, n;
    vector<vector<int>> pref; // 2-dim prefix sum

public:
    NumMatrix(vector<vector<int>>& matrix) : m(matrix.size()), n(matrix[0].size()), pref(m + 1, vector<int>(n + 1)) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pref[i + 1][j + 1] = pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) { // [row1, row2 + 1)[col1, col2 + 1)
        return pref[row2 + 1][col2 + 1] - pref[row2 + 1][col1] - pref[row1][col2 + 1] + pref[row1][col1];
    }
};
// @lc code=end
