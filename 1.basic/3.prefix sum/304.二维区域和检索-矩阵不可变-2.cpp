/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-03 09:53:50
 * 	 modified: 	2024-11-03 10:16:14
 * 	 project: 	LeetCode
 * 	 venue: 	226, Harbin
 */

/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
class NumMatrix {
public:
    vector<vector<int>> pre; // 2-dim prefix sum

    /*
    +-----+-+-------+     +--------+-----+     +-----+---------+     +-----+--------+
    |     | |       |     |        |     |     |     |         |     |     |        |
    |     | |       |     |        |     |     |     |         |     |     |        |
    +-----+-+       |     +--------+     |     |     |         |     +-----+        |
    |     | |       |  =  |              |  +  |     |         |  -  |              |
    +-----+-+       |     |              |     +-----+         |     |              |
    |               |     |              |     |               |     |              |
    |               |     |              |     |               |     |              |
    +---------------+     +--------------+     +---------------+     +--------------+
       sums[i][j]      =    sums[i-1][j]    +     sums[i][j-1]    -   sums[i-1][j-1]   +
                            matrix[i-1][j-1]

    +---------------+   +---------+----+   +---+-----------+   +---------+----+   +---+----------+
    |               |   |         |    |   |   |           |   |         |    |   |   |          |
    |   (r1,c1)     |   |         |    |   |   |           |   |         |    |   |   |          |
    |   +------+    |   |         |    |   |   |           |   +---------+    |   +---+          |
    |   |      |    | = |         |    | - |   |           | - |      (r1,c2) | + |   (r1,c1)    |
    |   |      |    |   |         |    |   |   |           |   |              |   |              |
    |   +------+    |   +---------+    |   +---+           |   |              |   |              |
    |        (r2,c2)|   |       (r2,c2)|   |   (r2,c1)     |   |              |   |              |
    +---------------+   +--------------+   +---------------+   +--------------+   +--------------+
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
        // (r1, c1) = (row1, col1); (r2, c2) = (row2 + 1, col2 + 1)
        return pre[row2 + 1][col2 + 1] - pre[row2 + 1][col1] - pre[row1][col2 + 1] + pre[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
