/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:37:15
 *   modified:  2025-02-28 15:15:42
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
    vector<vector<int>> pre; // 1-dim prefix sum

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        pre.resize(m, vector<int>(n + 1));
        for (int i = 0; i < m; i++) {
            for (int j = 1; j <= n; j++) {
                pre[i][j] = pre[i][j - 1] + matrix[i][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; i++) {
            sum += pre[i][col2 + 1] - pre[i][col1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
