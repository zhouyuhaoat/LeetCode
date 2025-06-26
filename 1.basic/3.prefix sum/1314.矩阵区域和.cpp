/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:37:10
 *   modified:  2025-02-28 15:19:12
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
public:
    int row, col;
    vector<vector<int>> pre;

    void prefixing(vector<vector<int>>& matrix) {
        row = matrix.size(), col = matrix[0].size();
        pre.resize(row + 1, vector<int>(col + 1, 0));
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return pre[row2 + 1][col2 + 1] - pre[row2 + 1][col1] - pre[row1][col2 + 1] + pre[row1][col1];
    }

    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        prefixing(mat);
        vector<vector<int>> res(row, vector<int>(col));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int row1 = max(i - k, 0), col1 = max(j - k, 0); // at least 0
                int row2 = min(i + k, row - 1), col2 = min(j + k, col - 1); // at most row - 1 and col - 1
                res[i][j] = sumRegion(row1, col1, row2, col2);
            }
        }
        return res;
    }
};
// @lc code=end
