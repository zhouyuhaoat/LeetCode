/*
 *   author:    zhouyuhao
 *   created:   2025-12-02 23:37:10
 *   modified:  2025-12-03 15:19:12
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=1314 lang=cpp
 *
 * [1314] 矩阵区域和
 */

// @lc code=start
class Solution {
private:
    int m, n;
    vector<vector<int>> pre;

public:
    void prefixing(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        pre.resize(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return pre[row2 + 1][col2 + 1] - pre[row2 + 1][col1] - pre[row1][col2 + 1] + pre[row1][col1];
    }

    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        prefixing(mat);
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            int row1 = max(i - k, 0), row2 = min(i + k, m - 1); // row
            for (int j = 0; j < n; j++) {
                int col1 = max(j - k, 0), col2 = min(j + k, n - 1); // col
                res[i][j] = sumRegion(row1, col1, row2, col2);
            }
        }
        return res;
    }
};
// @lc code=end
