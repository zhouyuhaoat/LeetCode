/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:37:15
 *   modified:  2025-02-28 16:30:57
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
public:
    vector<vector<int>> pre;
    /*
        2-dim prefix sum
        - pre[i][j] = sum[0, i)[0, j)
            - pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + matrix[i - 1][j - 1]
            - matrix[i - 1][j - 1] = pre[i][j] - pre[i - 1][j] - pre[i][j - 1] + pre[i - 1][j - 1]
            +--------+------+     +--------+-----+     +-----+---------+     +-----+--------+
            |        |      |     |        |     |     |     |         |     |     |        |
            |        |      |     |        |     |     |     |         |     |     |        |
            |        |      |     +--------+     |     |     |         |     +-----+        |
            |        |      |  =  |              |  +  |     |         |  -  |              |
            +--------+      |     |              |     +-----+         |     |              |
            |               |     |              |     |               |     |              |
            |               |     |              |     |               |     |              |
            +---------------+     +--------------+     +---------------+     +--------------+
        - sum[r1, r2)[c1, c2) = sum[0, r2)[0, c2) - sum[0, r2)[0, c1) - sum[0, r1)[0, c2) + sum[0, r1)[0, c1)
            - sum[r1, r2)[c1, c2) = pre[r2][c2] - pre[r2][c1] - pre[r1][c2] + pre[r1][c1]
            +---------------+     +---------+----+     +---+-----------+     +---------+----+     +---+----------+
            |               |     |         |    |     |   |           |     |         |    |     |   |          |
            |(r1, c1)       |     |         |    |     |   |           |     |         |    |     |   |          |
            |   +------+    |     |         |    |     |   |           |     +---------+    |     +---+          |
            |   |      |    |  =  |         |    |  -  |   |           |  -  |      (r1, c2)|  +  |(r1, c1)      |
            |   |      |    |     |         |    |     |   |           |     |              |     |              |
            |   +------+    |     +---------+    |     +---+           |     |              |     |              |
            |       (r2, c2)|     |      (r2, c2)|     |(r2, c1)       |     |              |     |              |
            +---------------+     +--------------+     +---------------+     +--------------+     +--------------+
        - prefix: not include itself, all previous
    */

    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        pre.resize(row + 1, vector<int>(col + 1, 0));
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        // sum[row1, row2][col1, col2] = sum[row1, row2 + 1)[col1, col2 + 1)
        return pre[row2 + 1][col2 + 1] - pre[row2 + 1][col1] - pre[row1][col2 + 1] + pre[row1][col1];
    }
};
// @lc code=end
